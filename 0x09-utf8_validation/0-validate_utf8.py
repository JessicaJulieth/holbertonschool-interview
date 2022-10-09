#!/usr/bin/python3
"""UTF-8 Validation
"""


def validUTF8(data):
    """Method that determines if a given data set
       represents a valid UTF-8 encoding.
    """

    x = 1 << 7
    y = 1 << 6
    bytesn = 0

    if not data or len(data) == 0:
        return True

    for n in data:
        m = 1 << 7
        if bytesn == 0:
            while (m & n):
                bytesn += 1
                m = m >> 1

            if bytesn == 0:
                continue
            if bytesn == 1 or bytesn > 4:
                return False
        else:

            if not (n & x and not (n & y)):
                return False
        bytesn -= 1

    if bytesn:
        return False
    else:
        return True