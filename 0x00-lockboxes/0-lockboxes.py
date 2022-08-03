#!/usr/bin/python3
"""
	Locked boxes method
"""
def canUnlockAll(boxes):
	key_list = [0]

	for key in key_list:
			for box in boxes[key]:
					if box not in key_list and box < len(boxes):
							key_list.append(box)
	for i in range(len(boxes)):
			if i not in key_list:
					return False
	return True