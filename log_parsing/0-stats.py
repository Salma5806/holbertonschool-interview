    #!/usr/bin/env python3
"""
Reads stdin line by line and computes metrics.

- Accepts only lines matching:
  <IP> - [<date>] "GET /projects/260 HTTP/1.1" <status> <file size>
- After every 10 lines read (valid or not) and on KeyboardInterrupt,
  prints:
    File size: <total size>
    <status>: <count>            # for 200, 301, 400, 401, 403, 404, 405, 500
- Safe when imported (runs only when executed as script).
"""

import sys
import re

LOG_RE = re.compile(
    r'^(\d{1,3}(?:\.\d{1,3}){3}) - \[(.*?)\] "GET /projects/260 HTTP/1\.1" (\d{3}) (\d+)$'
)

TRACKED_CODES = ('200', '301', '400', '401', '403', '404', '405', '500')


def print_stats(total_size, status_counts):
    """Prints the accumulated statistics."""
    print(f"File size: {total_size}")
    for code in TRACKED_CODES:
        if status_counts.get(code):
            print(f"{code}: {status_counts[code]}")


def main():
    total_size = 0
    status_counts = {}
    lines_read = 0

    try:
        for line in sys.stdin:
            lines_read += 1
            line = line.strip()

            m = LOG_RE.match(line)
            if m:
                status, size = m.group(3), m.group(4)
                # file size is guaranteed numeric by regex
                try:
                    total_size += int(size)
                except ValueError:
                    # Shouldn't happen due to regex, but be defensive
                    pass

                # Count only tracked integer status codes
                if status in TRACKED_CODES:
                    status_counts[status] = status_counts.get(status, 0) + 1

            if lines_read % 10 == 0:
                print_stats(total_size, status_counts)

    except KeyboardInterrupt:
        print_stats(total_size, status_counts)
        raise
    finally:
        # Print at EOF as well (and also after CTRL+C, once more is okay)
        print_stats(total_size, status_counts)


if __name__ == "__main__":
    main()
