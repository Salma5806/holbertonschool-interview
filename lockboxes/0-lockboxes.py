#!/usr/bin/python3
""" solve lockboxes problem  """


def canUnlockAll(boxes):
    """determines if all boxes can be unlocked"""
    keys = [0]
    for key in keys:
        for box_key in boxes[key]:
            if box_key < len(boxes) and box_key not in keys:
                keys.append(box_key)
    if len(keys) == len(boxes):
        return True
    else:
        return False
