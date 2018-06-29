# Python 2.7
#===============================================================================
#                                PROBLEM
#===============================================================================
"""
Daily Coding Problem: Problem #30
DATE : 29/JUNE/2018
Good morning! Here's your coding interview problem for today.
This problem was asked by Facebook.

You are given an array of non-negative integers that represents a
two-dimensional elevation map where each element is unit-width wall and the
integer is the height. Suppose it will rain and all spots between two walls get
filled up.

Compute how many units of water remain trapped on the map in O(N) time and
O(1) space.

For example, given the input [2, 1, 2], we can hold 1 unit of water in the
middle.

Given the input [3, 0, 1, 3, 0, 5], we can hold 3 units in the first index,
2 in the second, and 3 in the fourth index (we cannot hold 5 since it would
run off to the left), so we can trap 8 units of water.
"""
#===============================================================================
#                                SOLUTION
#===============================================================================

msg = "INFO : {geom} has {water} blocks of water..."
# Calculate water blocks
def find_water(wall):
    n    = wall.__len__()                     # number of blocks in x direction
    hmin = min(wall[0],wall[n-1])             # min wall height

    # total water stored
    total_water = (hmin*n) - sum(wall[1:-1]) - 2*hmin    # O(n) comes from sum()
    print(msg.format(geom=wall,water=total_water))
    return total_water


# Driver function
if ( __name__ == "__main__"):

    # conatiner geometry
    wall1 = [2, 1, 2]
    wall2 = [3, 0, 1, 3, 0, 5]
    wall3 = [1, 0, 0, 0, 1]
    wall4 = [6, 1, 1, 2]

    # run validation tests
    assert(find_water(wall1) == 1)
    assert(find_water(wall2) == 8)
    assert(find_water(wall3) == 3)
    assert(find_water(wall4) == 2)

    print("INFO : ALL TEST SUCCESSFULL...")
