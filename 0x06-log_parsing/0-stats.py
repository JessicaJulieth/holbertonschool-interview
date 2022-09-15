#!/usr/bin/python3
"""
Write a script that reads stdin line by line and computes metrics:
"""
import sys


def metrics(codes, size):
    print("File size: {}".format(size))
    for key, value in sorted(codes.items()):
        if value > 0:
            print("{}: {}".format(key, value))


x = {'200': 0, '301': 0, '400': 0, '401': 0,
     '403': 0, '404': 0, '405': 0, '500': 0}
count = 1
z = 0

try:
    for line in sys.stdin:
        split_args = line.split()
        if len(split_args) < 7:
            continue
        z += int(split_args[-1])
        code_stats = split_args[-2]
        if code_stats in x:
            x[code_stats] += 1
        if count == 10:
            metrics(x, z)
            count = 1
        else:
            count += 1
    metrics(x, z)
except KeyboardInterrupt:
    metrics(x, z)
    raise
