#!/usr/bin/python3
"""
Reads lines from standard input and computes metrics:
- total file size
- number of lines per status code (200, 301, 400, 401, 403, 404, 405, 500)
Prints metrics every 10 lines or on keyboard interrupt.
"""

import sys

def print_stats(total_size, status_counts):
    """Prints the total file size and status code counts in ascending order"""
    print(f"File size: {total_size}")
    for code in sorted(status_counts.keys()):
        if status_counts[code] > 0:
            print(f"{code}: {status_counts[code]}")

if __name__ == "__main__":
    total_size = 0
    status_codes = [200, 301, 400, 401, 403, 404, 405, 500]
    status_counts = {code: 0 for code in status_codes}
    line_count = 0

    try:
        for line in sys.stdin:
            parts = line.strip().split()
            if len(parts) < 9:
                continue  # skip invalid lines
            try:
                status = int(parts[-2])
                size = int(parts[-1])
            except ValueError:
                continue  # skip lines with non-integer status or size
            if status in status_counts:
                status_counts[status] += 1
            total_size += size
            line_count += 1

            if line_count % 10 == 0:
                print_stats(total_size, status_counts)
    except KeyboardInterrupt:
        pass
    finally:
        if line_count % 10 != 0 or line_count == 0:
            print_stats(total_size, status_counts)