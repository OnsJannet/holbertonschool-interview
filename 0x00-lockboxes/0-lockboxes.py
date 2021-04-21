#!/usr/bin/python3
"""
boxes are numbered sequentially from 0 to n - 1
and each box may contain keys to the other boxes.
"""


def canUnlockAll(boxes):
    ''' determines if all the boxes can be opened '''
    all_boxes = [0]
    for key in all_boxes:
        for boxes_kies in boxes[key]:
            if boxes_kies not in all_boxes:
                if boxes_kies < len(boxes):
                    all_boxes.append(boxes_kies)
    if len(all_boxes) == len(boxes):
        return True
    return False
