import webbrowser, itertools, csv, sys, os, time, datetime as dt
from urllib.parse import quote_plus

BATCH = 6
FRESH = "w"   # d = past 24h, w = past week, m = past month

# ---------- NAUKRI: skill-led searches (last 24h, 1-2 yrs) ----------
ROLES = ["nestjs-developer", "node-js-developer", "typescript-developer",
         "mern-stack-developer", "react-js-developer", "next-js-developer"]
HUBS = ["bengaluru", "hyderabad", "pune", "noida", "gurgaon", "delhi-ncr",
        "mumbai", "chennai"]
HUB_ROLES = ["node-js-developer", "nestjs-developer", "mern-stack-developer",
             "typescript-developer", "react-js-developer"]
OTHER = ["kolkata", "ahmedabad", "jaipur", "chandigarh", "mohali", "indore",
         "lucknow", "kochi", "coimbatore", "nagpur", "bhopal", "ghaziabad",
         "greater-noida", "meerut", "dehradun"]
OTHER_ROLES = ["node-js-developer", "mern-stack-developer"]

urls = [f"https://www.naukri.com/{r}-jobs?experience={e}&jobAge=1"
        for r, e in itertools.product(ROLES, [1, 2])]
urls += [f"https://www.naukri.com/{r}-jobs-in-{c}?experience=1&jobAge=1"
         for c, r in itertools.product(HUBS, HUB_ROLES)]
urls += [f"https://www.naukri.com/{r}-jobs-in-{c}?experience=1&jobAge=1"
         for c, r in itertools.product(OTHER, OTHER_ROLES)]

# Your own saved Naukri URLs with filters (best quality), opened first
if os.path.exists("my_urls.txt"):
    urls = [u.strip() for u in open("my_urls.txt") if u.strip()] + urls

# ---------- GOOGLE: short queries, Google's own date filter ----------
def g(query):
    return f"https://www.google.com/search?q={quote_plus(query)}&tbs=qdr:{FRESH}&num=20"

ATS = ["jobs.lever.co", "job-boards.greenhouse.io", "boards.greenhouse.io",
       "jobs.ashbyhq.com", "apply.workable.com", "jobs.smartrecruiters.com"]
BOARDS = ["wellfound.com/jobs", "cutshort.io", "instahyre.com", "hirist.tech",
          "workatastartup.com"]

NOJAVA = "-java -.net -php"
searches = []
for site in ATS + BOARDS:
    searches.append(f'site:{site} "full stack" (NestJS OR "Node.js") India {NOJAVA}')
    searches.append(f'site:{site} "full stack" TypeScript React remote {NOJAVA}')

# Domain / niche searches (no site: so they reach company career pages)
searches += [
    f'proptech "full stack" "Node.js" India careers {NOJAVA}',
    f'"real estate" tech "full stack" NestJS India {NOJAVA}',
    f'"LLM" OR GenAI "full stack" "Node.js" React India {NOJAVA}',
    f'"we are hiring" "full stack" NestJS OR "Node.js" India {NOJAVA}',
    f'"send your resume" "node.js" "react" India {NOJAVA}',
    f'"Who is hiring" "full stack" TypeScript remote site:news.ycombinator.com',
]
urls += [g(q) for q in searches]

def run():
    print(f"{len(urls)} searches")
    for i in range(0, len(urls), BATCH):
        for u in urls[i:i + BATCH]:
            webbrowser.open_new_tab(u)
            time.sleep(1.5)  # avoids Google CAPTCHA
        if i + BATCH < len(urls):
            input(f"Opened {min(i + BATCH, len(urls))}/{len(urls)}. Enter for next batch...")

def log(company, role_, link, contact=""):
    with open("applications.csv", "a", newline="", encoding="utf-8") as f:
        csv.writer(f).writerow([dt.date.today(), company, role_, link, contact,
                                "applied", (dt.date.today() + dt.timedelta(days=4)).isoformat()])
    print("Logged. Follow up on", dt.date.today() + dt.timedelta(days=4))

if __name__ == "__main__":
    if len(sys.argv) > 1 and sys.argv[1] == "log":
        log(*sys.argv[2:])
    else:
        run()