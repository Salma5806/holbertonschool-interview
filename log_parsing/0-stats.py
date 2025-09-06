#!/usr/bin/python3
import sys

def print_stats(total_size, status_counts):
    """Print the accumulated statistics."""
    print(f"File size: {total_size}")
    for code in sorted(status_counts.keys()):
        if status_counts[code] > 0:
            print(f"{code}: {status_counts[code]}")

if __name__ == "__main__":
    total_size = 0
    status_counts = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}
    line_count = 0

    try:
        for line in sys.stdin:
            parts = line.split()
            if len(parts) < 9:  # Skip malformed lines
                continue
            try:
                status = int(parts[-2])
                size = int(parts[-1])
            except ValueError:
                continue

            if status in status_counts:
                status_counts[status] += 1
            total_size += size
            line_count += 1

            if line_count % 10 == 0:
                print_stats(total_size, status_counts)
    except KeyboardInterrupt:
        pass
    finally:
        # Print stats at the end or on KeyboardInterrupt
        print_stats(total_size, status_counts)
