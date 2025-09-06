#!/usr/bin/python3
"""
Reads stdin line by line and computes metrics:
- Total file size
- Number of lines by status code
Prints metrics every 10 lines or on keyboard interrupt.
"""

import sys
import re

STATUS_CODES = [200, 301, 400, 401, 403, 404, 405, 500]

def print_stats(total_size, status_counts):
    print(f"File size: {total_size}")
    for code in sorted(status_counts.keys()):
        if status_counts[code] > 0:
            print(f"{code}: {status_counts[code]}")

if __name__ == "__main__":
    total_size = 0
    status_counts = {code: 0 for code in STATUS_CODES}
    line_count = 0

    pattern = re.compile(
        r'^\d{1,3}(\.\d{1,3}){3} - \[.*\] "GET /projects/260 HTTP/1\.1" (\d{3}) (\d+)$'
    )

    try:
        for line in sys.stdin:
            line = line.strip()
            match = pattern.match(line)
            if not match:
                continue
            status = int(match.group(2))
            size = int(match.group(3))
            if status in status_counts:
                status_counts[status] += 1
            total_size += size
            line_count += 1

            if line_count % 10 == 0:
                print_stats(total_size, status_counts)
    except KeyboardInterrupt:
        pass
    finally:
        # Print the remaining stats if last batch < 10 lines
        if line_count % 10 != 0 or line_count == 0:
            print_stats(total_size, status_counts)