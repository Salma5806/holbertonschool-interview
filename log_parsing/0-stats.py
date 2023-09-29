#!/usr/bin/python3
"""Log parsing"""
import datetime
import sys

status = [200, 301, 400, 401, 403, 404, 405, 500]
status_count = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}


def parse(line):
    """Parse a line"""
    data = line.rstrip().split()
    try:
        status_code = int(data[-2])
        file_size = int(data[-1])
        if status_code not in status:
            return None
        return {"status_code": status_code, "file_size": file_size}
    except Exception:
        pass


def parse10(data_list):
    """parse 10 lines of generated logs"""
    file_size = 0
    try:
        for data in data_list:
            file_size += data["file_size"]
            status_count[data["status_code"]] += 1
        return file_size, status_count
    except Exception:
        pass


def print_stats(file_size, status_count):
    """print stats"""
    print("File size: {}".format(file_size))
    for k, v in sorted(status_count.items()):
        if v != 0:
            print("{}: {}".format(k, v))


if __name__ == "__main__":
    data_list = []
    h = 0
    try:
        for input_line in sys.stdin:
            if input_line == "":
                print("file size: 0")
            data_list.append(parse(input_line))
            if len(data_list) == 10:
                file_size, status_count = parse10(data_list)
                h = file_size
                print_stats(file_size, status_count)
                data_list = []
        x, y = parse10(data_list)
        x += h
        print_stats(x, y)
    except KeyboardInterrupt:
        print("KeyboardInterrupt")
        exit(0)
