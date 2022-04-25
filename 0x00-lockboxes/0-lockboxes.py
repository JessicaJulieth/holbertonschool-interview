#!/usr/bin/python3


def canUnlockAll(boxes):
    nlist = []
    k = len(boxes)
    for x in boxes:
        if len(x) == 0 and x is not boxes[k-1]:
            return False
        for j in x:
            nlist.append(j)
    print(nlist)
    for index, keys in enumerate(boxes):
        if index in nlist or index < k-1:
            return True
        else:
            return False
