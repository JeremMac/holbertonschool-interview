#!/usr/bin/python3
"""
Units of water
"""


def rain(walls):

    """
    calculate how many square units of water
    will be retained after it rains.
    """

    if not walls:
        return 0

    left, right = 0, len(walls) - 1

    left_max, right_max = walls[left], walls[right]

    water_trapped = 0

    while left < right:
        if left_max <= right_max:
            left += 1
            left_max = max(left_max, walls[left])
            water_trapped += max(0, left_max - walls[left])
        else:
            right -= 1
            right_max = max(right_max, walls[right])
            water_trapped += max(0, right_max - walls[right])

    return water_trapped
