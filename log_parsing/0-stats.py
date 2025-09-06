#!/usr/bin/env python3
"""
Reads stdin line by line and computes metrics:
- Total file size
- Number of lines by status code (200, 301, 400, 401, 403, 404, 405, 500)
Prints statistics every 10 lines and on CTRL+C.
"""

import sys

STATUS_CODES = [200, 301, 400, 401, 403, 404, 405, 500]


def print_stats(total_size, status_count):
    """Prints total file size and counts by status code."""
    print(f"File size: {total_size}")
    for code in sorted(status_count):
        if status_count[code] > 0:
            print(f"{code}: {status_count[code]}")


def main():
    total_size = 0
    status_count = {code: 0 for code in STATUS_CODES}
    line_count = 0

    try:
        for line in sys.stdin:
            line = line.strip()
            if not line:
                continue

            parts = line.split()
            # Expect at least status code and size at the end
            if len(parts) < 2:
                continue

            try:
                status = int(parts[-2])
                size = int(parts[-1])
            except ValueError:
                continue

            if status in STATUS_CODES:
                status_count[status] += 1
            total_size += size
            line_count += 1

            if line_count % 10 == 0:
                print_stats(total_size, status_count)

    except KeyboardInterrupt:
        pass
    finally:
        print_stats(total_size, status_count)


if __name__ == "__main__":
    main()