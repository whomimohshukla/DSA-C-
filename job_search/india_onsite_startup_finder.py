#!/usr/bin/env python3
"""Open five browser searches for onsite junior roles at small Indian startups."""

import webbrowser
from urllib.parse import quote_plus


ROLE = '("junior" OR "entry level" OR graduate OR associate) ("Node.js" OR MERN OR React)'
EXPERIENCE = '("0-2 years" OR "1-2 years" OR "early career" OR "new grad")'
ONSITE = '("on-site" OR onsite OR "work from office" OR WFO)'
SMALL_COMPANY = '("1-10 employees" OR "11-50 employees" OR "1-50 employees" OR "under 50 employees")'
INDIA = '(India OR Bengaluru OR Bangalore OR Hyderabad OR Pune OR Mumbai OR Delhi OR Gurugram OR Noida OR Chennai)'

# Search established startup and India-focused boards. Verify location and
# company headcount on the listing/company profile; web search cannot enforce either.
SEARCHES = [
    ("Wellfound", f'site:wellfound.com/jobs {ROLE} {EXPERIENCE} {ONSITE} {INDIA} {SMALL_COMPANY}'),
    ("Y Combinator / Work at a Startup", f'site:workatastartup.com/jobs {ROLE} {EXPERIENCE} {ONSITE} India {SMALL_COMPANY}'),
    ("Cutshort", f'site:cutshort.io/job {ROLE} {EXPERIENCE} {ONSITE} {INDIA} startup {SMALL_COMPANY}'),
    ("LinkedIn Jobs", f'site:linkedin.com/jobs/view {ROLE} {EXPERIENCE} {ONSITE} {INDIA} startup {SMALL_COMPANY}'),
    ("Naukri", f'site:naukri.com {ROLE} {EXPERIENCE} {ONSITE} {INDIA} startup {SMALL_COMPANY}'),
]


def main():
    print("Opening five searches for onsite junior roles at Indian startups.")
    print("Verify the job is onsite in India and the company has at most 50 people.")
    print("Search results cannot reliably confirm company headcount or whether a role is still open.")
    for board, query in SEARCHES:
        url = f"https://www.google.com/search?q={quote_plus(query)}"
        opened = webbrowser.open_new_tab(url)
        if not opened:
            raise RuntimeError(
                f"Could not open the {board} search. Check that a default browser is configured."
            )
        print(f"Opened: {board}")


if __name__ == "__main__":
    main()
