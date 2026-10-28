#!/usr/bin/env python3
"""Open five browser searches for junior remote Node.js/MERN jobs."""

import webbrowser
from urllib.parse import quote_plus


ROLE = '("junior" OR "entry level" OR graduate OR associate) ("Node.js" OR MERN OR React)'
REMOTE = '("remote India" OR "India remote" OR "remote worldwide" OR "work from anywhere" OR APAC)'
EXPERIENCE = '("0-2 years" OR "1-2 years" OR "early career" OR "new grad")'

# These are established job boards with searchable, identifiable listings.
SEARCHES = [
    ("Wellfound", f'site:wellfound.com/jobs {ROLE} {REMOTE} {EXPERIENCE}'),
    ("Y Combinator / Work at a Startup", f'site:workatastartup.com/jobs {ROLE} {REMOTE} {EXPERIENCE}'),
    ("We Work Remotely", f'site:weworkremotely.com {ROLE} {REMOTE} {EXPERIENCE}'),
    ("Remotive", f'site:remotive.com/remote-jobs {ROLE} {REMOTE} {EXPERIENCE}'),
    ("Remote OK", f'site:remoteok.com {ROLE} {REMOTE} {EXPERIENCE}'),
]


def main():
    print("Opening five remote junior-job searches in your default browser.")
    print("Check each listing for India eligibility, experience, and whether it is still open.")
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
