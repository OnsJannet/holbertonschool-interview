#!/usr/bin/python3


def canUnlockAll(boxes):
    ''' determines if all the boxes can be opened '''
    new = []
    for x in boxes[0]:
        new.append(x)
    for x in range(len(boxes)):
        if x in new:
            for y in range(len(boxes[x])):
                if not boxes[x][y] in new :
                    new.append(boxes[x][y])

    if len(new) is len(boxes) - 1:
        return True
    else:
        return False
