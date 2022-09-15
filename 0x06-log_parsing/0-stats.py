#!/usr/bin/python3
"""
Write a script that reads stdin line by line and computes metrics:
"""
import sys
import signal


def metrics(codes, size):
    """
    Function that print stats
    """
    print("File size: {}".format(codes))
    for key, value in sorted(size.items()):
        if value > 0:
            print("{}: {}".format(key, value))


if __name__ == '__main__':
    x = {'200': 0, '301': 0, '400': 0, '401': 0,
         '403': 0, '404': 0, '405': 0, '500': 0}
    count = 1
    z = 0

try:
    for line in sys.stdin:
        split_args = line.split()
        if len(split_args) > 6:
            status = split_args[-2]
            file_size = split_args[-1]
            z += int(file_size)
            if status in x:
                count += 1
                x[status] += 1
                if count % 10 == 0:
                    metrics(z, x)
except KeyboardInterrupt:
    metrics(z, x)
    raise
else:
    metrics(z, x)
