#!/usr/bin/python3
""" Log parsing """
import sys

i = 0
size = 0
status = {"200": 0, "301": 0, "400": 0, "401": 0, "403": 0, "404": 0, "405": 0, "500": 0}

try:
    for line in sys.stdin:
        i += 1
        data = line.split()
        if len(data) > 2:
            size += int(data[-1])
            if data[-2] in status:
                status[data[-2]] += 1
        if i % 10 == 0:
            print("File size: {}".format(size))
            for key, value in sorted(status.items()):
                if value:
                    print("{}: {}".format(key, value))
finally:
    print("File size: {}".format(size))
    for key, value in sorted(status.items()):
        if value:
            print("{}: {}".format(key, value))
