import http from "http";
import { WebSocketServer, WebSocket } from "ws";

// 1. Normal HTTP server (your Express app could go here)
const server = http.createServer((req, res) => {
  if (req.url === "/health") return res.end("ok");
  res.writeHead(404).end();
});

// 2. Attach WebSocket to that same server, on a path
const wss = new WebSocketServer({ server, path: "/ws" });

// 3. Heartbeat bookkeeping — set up once, used by the connection handler
const alive = new WeakMap();

wss.on("connection", (socket, req) => {
  // Auth (query string / cookie / first message)
  const token = new URL(req.url, "http://x").searchParams.get("token");
  if (token !== "secret") {
    socket.close(4001, "unauthorized");
    return;
  }

  // Register heartbeat state
  alive.set(socket, true);
  socket.on("pong", () => alive.set(socket, true));

  socket.send(JSON.stringify({ type: "welcome", ts: Date.now() }));

  socket.on("message", (raw) => {
    // raw is a Buffer in `ws`
    try {
      const msg = JSON.parse(raw.toString());

      // Broadcast to every connected client
      for (const client of wss.clients) {
        if (client.readyState === WebSocket.OPEN) {
          client.send(JSON.stringify({ echo: msg, at: Date.now() }));
        }
      }
    } catch {
      socket.send(JSON.stringify({ error: "invalid json" }));
    }
  });

  socket.on("close", (code, reason) => {
    console.log("closed", code, reason.toString());
  });

  socket.on("error", (err) => console.error("ws error", err));
});

// 4. Heartbeat — detect dead connections that never sent a close frame
//    (very common interview question)
setInterval(() => {
  for (const client of wss.clients) {
    if (alive.get(client) === false) {
      client.terminate(); // force-close
      continue;
    }
    alive.set(client, false);
    client.ping(); // sends a WS ping frame
  }
}, 30_000);

// 5. Graceful shutdown
process.on("SIGTERM", () => {
  for (const c of wss.clients) c.close(1001, "server shutting down");
  wss.close(() => server.close(() => process.exit(0)));
});

server.listen(3000, () => console.log("http+ws on :3000"));