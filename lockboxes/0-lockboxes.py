#!/usr/bin/python3
"""
Locked boxes method
"""


def canUnlockAll(boxes):
    l=[]
    X=len(boxes)
    for i in boxes:
        if len(i)==0 and i is not boxes[X-1]: #### if the empty list is not the last list in the boxes (in the middle) [case of third]
            return False

        for j in i:
            l.append(j)  #creation  de la  list: change the list of list into a simple list


    #print(l) affichage
    for index, keys in enumerate(boxes):
        if index in l or index<X-1:
            return True
        else:
            return False
