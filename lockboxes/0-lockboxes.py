#!/usr/bin/python3
"""
Locked boxes method
"""


def canUnlockAll(boxes):

    numberofBoxes = len(boxes)
    unlocked = [0]
    numberofUnlockedBoxes = 1

    for box in unlocked:

        for key in boxes[box]:

            if key <= numberofBoxes and key not in unlocked:
                unlocked.append(key)
                numberofUnlockedBoxes += 1

    return numberofBoxes == numberofUnlockedBoxes
