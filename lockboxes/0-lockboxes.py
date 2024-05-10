#!/usr/bin/python3
"""A module that contains canUnlockAll function"""


def canUnlockAll(boxes):
    """A function that check if all boxes are unlockable"""
    # Set to keep track of visited and unlocked boxes
    visited = set([0])  # Starting from box 0

    # Queue to perform BFS
    queue = [0]

    # Traverse through the boxes
    while queue:
        current_box = queue.pop(0)  # Get the first box in the queue

        # Collect keys from the current box
        for key in boxes[current_box]:
            # If the key corresponds to a box we haven't visited yet
            if key not in visited and key < len(boxes):
                visited.add(key)  # Mark the box as visited
                queue.append(key)  # Add the box to the queue
                # for further exploration

    # If all boxes have been visited, return True
    return len(visited) == len(boxes)
