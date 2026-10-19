#!/usr/bin/env python3
"""
Find NEW, SMALL, EARLY-STAGE startups that hire remote full stack / backend / software engineers
and can take someone from India. Then shortlist and track the best ones.

  python3 startup_hunt.py                 open every search group (in batches)
  python3 startup_hunt.py founding        only one group (see GROUPS below)
  python3 startup_hunt.py groups          list the groups
  python3 startup_hunt.py print [group]   print queries, no browser

  python3 startup_hunt.py add             add a startup you found (asks a few questions, scores it 0-6)
  python3 startup_hunt.py list            shortlist, best fit first
  python3 startup_hunt.py contacted "Name"   mark as contacted, follow-up in 4 days
  python3 startup_hunt.py due             follow-ups due today
  python3 startup_hunt.py status "Name" replied|interview|rejected|ghosted

Why these startups: in a 3-15 person team the hiring bar is "can you ship and own things",
not "do you have 3+ years", and the founder reads the message. That's where your Taurgo
work and your live projects count the most.
"""
import webbrowser, time, sys, os, csv, shutil, datetime as dt
from urllib.parse import quote_plus

# ===================== SETTINGS =====================
BATCH  = 6
FRESH  = "w"        # d = 24h, w = week, m = month (funding news always uses the last month)
ENGINE = "google"   # "bing" if Google shows CAPTCHAs
FOLLOWUP_DAYS = 4
FILE = "startups.csv"

# ===================== BROWSER (Brave support) =====================
_BRAVE = [r"C:\Program Files\BraveSoftware\Brave-Browser\Application\brave.exe",
          r"C:\Program Files (x86)\BraveSoftware\Brave-Browser\Application\brave.exe",
          os.path.expandvars(r"%LOCALAPPDATA%\BraveSoftware\Brave-Browser\Application\brave.exe"),
          "/Applications/Brave Browser.app/Contents/MacOS/Brave Browser",
          shutil.which("brave-browser") or "", shutil.which("brave") or ""]
_p = next((p for p in _BRAVE if p and os.path.exists(p)), None)
if _p:
    webbrowser.register("brave", None, webbrowser.BackgroundBrowser(_p))
    open_tab = webbrowser.get("brave").open_new_tab
else:
    open_tab = webbrowser.open_new_tab

# ===================== BUILDING BLOCKS =====================
STACK = '("Node.js" OR NestJS OR TypeScript) (React OR "Next.js")'
WHERE = '(India OR APAC OR worldwide OR anywhere)'
NO    = '-senior -staff -lead -python -java'
TITLE = 'intitle:("full stack" OR fullstack OR backend)'
STAGE = '("seed" OR "early-stage" OR "small team")'
ATS = ["jobs.lever.co", "job-boards.greenhouse.io", "jobs.ashbyhq.com", "apply.workable.com",
       "jobs.smartrecruiters.com", "recruitee.com", "breezy.hr"]

# ===================== SEARCH GROUPS =====================
GROUPS = {}

# 1. "Founding / first engineer" roles: tiny teams, founder decides, years matter least
GROUPS["founding"] = [
    f'intitle:("founding engineer" OR "first engineer" OR "founding full stack") ("Node.js" OR TypeScript OR React) (remote OR India OR APAC OR worldwide) -senior -staff -python',
    f'intitle:("founding engineer" OR "founding software engineer") ("Node.js" OR TypeScript) {WHERE} -staff -python -java',
    f'"founding engineer" ("full stack" OR backend) remote ("Node.js" OR NestJS OR TypeScript) India OR APAC OR worldwide -staff -python',
] + [f'site:{a} intitle:("founding engineer" OR "first engineer" OR "founding full stack") remote -staff -python' for a in ATS]

# 2. Early-stage startups on applicant-tracking systems (stage words in the posting)
GROUPS["early"] = [f'site:{a} {TITLE} {STAGE} {STACK} {WHERE} -senior -staff' for a in ATS]

# 3. Y Combinator and other startup job boards
GROUPS["boards"] = [
    'site:workatastartup.com ("full stack" OR backend OR "software engineer") ("Node.js" OR TypeScript) (remote OR India) -senior -staff',
    'site:ycombinator.com/companies ("full stack" OR "software engineer" OR backend) remote ("Node.js" OR TypeScript) -senior -staff',
    f'site:wellfound.com/jobs {TITLE} {STACK} {WHERE} {NO}',
    f'site:startup.jobs {TITLE} {STACK} remote {NO}',
    f'site:himalayas.app {TITLE} {STACK} {WHERE} {NO}',
    f'site:workingnomads.com {TITLE} {STACK} {NO}',
    f'site:cutshort.io {TITLE} {STACK} startup {NO}',
]

# 4. Careers pages that describe themselves as small / early
GROUPS["careers"] = [
    f'inurl:careers ("small team" OR "founding team" OR seed) {TITLE} {STACK} {WHERE} -senior -staff',
    f'inurl:jobs ("small team" OR "founding team") {TITLE} {STACK} remote -senior -staff -python',
    f'("early-stage startup" OR "seed-funded") {TITLE} {STACK} India remote -senior -python',
    f'("remote-first" OR "fully remote") startup {TITLE} {STACK} {WHERE} -senior -python',
]

# 5. Newly funded startups (they hire right after raising). Last month only.
FUNDED = [
    '("raises" OR "raised") ("pre-seed" OR "seed round") ("hiring" OR "engineering team") (SaaS OR AI) (India OR remote)',
    'site:entrackr.com ("seed" OR "pre-seed") ("hiring" OR "engineers" OR "tech team")',
    'site:inc42.com ("seed" OR "pre-seed") raises ("hiring" OR "engineers" OR "product")',
    'site:yourstory.com ("seed" OR "pre-seed") raises ("hiring" OR "engineers")',
    'site:techcrunch.com ("pre-seed" OR "seed") raises ("hiring engineers" OR "growing the team") remote',
]
GROUPS["funded"] = FUNDED

# 6. Hacker News: founders post hiring comments themselves (sorted newest first)
def hn(query, kind="comment"):
    return ("https://hn.algolia.com/?dateRange=pastMonth&page=0&prefix=false"
            f"&query={quote_plus(query)}&sort=byDate&type={kind}")
HN_URLS = [hn("remote full stack node india"), hn("remote typescript node worldwide"),
           hn("founding engineer remote"), hn("remote backend nodejs APAC"),
           hn("hiring remote software engineer india")]
GROUPS["hn"] = HN_URLS

# 7. Your niche
GROUPS["niche"] = [
    f'(proptech OR "property technology" OR "real estate") {TITLE} ("Node.js" OR TypeScript) {WHERE} -senior -staff -python',
    f'intitle:("AI engineer" OR "applied AI" OR "LLM" OR "GenAI") ("Node.js" OR TypeScript) {WHERE} {STAGE} -senior -staff -python',
]

# ===================== OPEN =====================
_BING = {"d": "ez1", "w": "ez2", "m": "ez3"}

def q(query, fresh=None):
    f = fresh or FRESH
    if ENGINE == "bing":
        return f"https://www.bing.com/search?q={quote_plus(query)}&filters=ex1%3a%22{_BING.get(f, 'ez2')}%22"
    return f"https://www.google.com/search?q={quote_plus(query)}&tbs=qdr:{f},sbd:1&num=20"

def urls_for(name):
    items = GROUPS[name]
    if name == "hn":
        return items
    return [q(s, "m" if name == "funded" else None) for s in items]

def run(selected):
    urls = [u for g in selected for u in urls_for(g)]
    print(f"{len(urls)} searches from: {', '.join(selected)}")
    for i in range(0, len(urls), BATCH):
        for u in urls[i:i + BATCH]:
            open_tab(u); time.sleep(2)
        if i + BATCH < len(urls):
            input(f"Opened {min(i + BATCH, len(urls))}/{len(urls)}. Enter for next batch...")
    print("\nFound a promising startup? Run: python3 startup_hunt.py add")

# ===================== SHORTLIST =====================
FIELDS = ["added", "name", "website", "job_link", "stage", "team_size", "founder", "contact",
          "source", "score", "status", "followup_on", "notes"]
CHECKS = [
    "Early stage (pre-seed / seed / team under ~20)?",
    "Says remote, or India / APAC / worldwide is OK?",
    "Role posted in the last 2 weeks?",
    "Stack matches (Node/NestJS + React/TypeScript)?",
    "Can you reach the founder directly (email or profile)?",
    "No senior / 3+ years requirement?",
]

def load():
    if not os.path.exists(FILE): return []
    with open(FILE, newline="", encoding="utf-8") as f:
        return list(csv.DictReader(f))

def save(rows):
    with open(FILE, "w", newline="", encoding="utf-8") as f:
        w = csv.DictWriter(f, fieldnames=FIELDS); w.writeheader()
        for r in rows: w.writerow({k: r.get(k, "") for k in FIELDS})

def ask(p, d=""):
    v = input(f"{p}{f' [{d}]' if d else ''}: ").strip()
    return v or d

def find(rows, name):
    m = [r for r in rows if name.lower() in r["name"].lower()]
    if len(m) != 1:
        print("Matches:", [r["name"] for r in m] or "none"); return None
    return m[0]

def add():
    rows = load()
    name = ask("Startup name")
    if not name: return
    if any(r["name"].lower() == name.lower() for r in rows):
        print("Already on the list."); return
    r = dict(added=dt.date.today(), name=name, website=ask("Website"), job_link=ask("Job / careers link"),
             stage=ask("Stage (pre-seed/seed/series A/unknown)", "unknown"), team_size=ask("Team size (guess ok)"),
             founder=ask("Founder name"), contact=ask("Founder email / profile link"),
             source=ask("Where you found it"), status="to_contact", notes=ask("Notes (optional)"))
    print("\nFit check (y/n):")
    score = sum(1 for c in CHECKS if ask(f"  {c}", "n").lower() == "y")
    r["score"] = score
    rows.append(r); save(rows)
    verdict = "contact today" if score >= 5 else "worth a message" if score >= 3 else "low priority"
    print(f"Saved. Score {score}/6 -> {verdict}.")

def listing():
    rows = sorted(load(), key=lambda r: (-int(r["score"] or 0), r["added"]))
    for r in rows:
        print(f"{r['score']}/6 | {r['name'][:24]:24} | {r['stage'][:10]:10} | {r['status']:11} | {r['founder'][:18]:18} | {r['contact'][:34]}")

def contacted(name):
    rows = load(); r = find(rows, name)
    if r:
        r["status"] = "contacted"; r["followup_on"] = str(dt.date.today() + dt.timedelta(days=FOLLOWUP_DAYS))
        save(rows); print("Follow up on", r["followup_on"])

def due():
    t = str(dt.date.today()); n = 0
    for r in load():
        if r["status"] == "contacted" and r["followup_on"] <= t:
            print(f"FOLLOW UP: {r['name']} -> {r['founder']} {r['contact']}"); n += 1
    print("Nothing due." if not n else f"{n} due")

def setstatus(name, status):
    rows = load(); r = find(rows, name)
    if r: r["status"] = status; save(rows); print("Updated", r["name"], "->", status)

# ===================== MAIN =====================
if __name__ == "__main__":
    a = sys.argv[1:]
    cmd = a[0] if a else "all"
    if cmd == "add": add()
    elif cmd == "list": listing()
    elif cmd == "contacted" and len(a) > 1: contacted(a[1])
    elif cmd == "due": due()
    elif cmd == "status" and len(a) > 2: setstatus(a[1], a[2])
    elif cmd == "groups": print("Groups:", ", ".join(GROUPS))
    elif cmd == "print":
        for g in ([a[1]] if len(a) > 1 else GROUPS):
            print(f"\n## {g}")
            for s in GROUPS[g]: print(s, "\n")
    elif cmd == "all": run(list(GROUPS))
    elif cmd in GROUPS: run([cmd])
    else: print(__doc__)