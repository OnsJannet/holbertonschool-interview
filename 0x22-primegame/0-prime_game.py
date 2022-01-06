#!/usr/bin/python3
'''
prime game
'''


def isWinner(x, nums):
    '''
    Returns: name of the player that won the most rounds
    x is the number of rounds and nums is an array of n
    '''
    if not nums or x < 1:
        return None
    max_numbers = max(nums)
    filters = [True for _ in range(max(max_numbers + 1, 2))]
    for i in range(2, int(pow(max_numbers, 0.5)) + 1):
        if not filters[i]:
            continue
        for j in range(i * i, max_numbers + 1, i):
            filters[j] = False
    filters[0] = filters[1] = False
    c = 0
    for i in range(len(filters)):
        if filters[i]:
            c += 1
        filters[i] = c
    player_number_one = 0
    for max_numbers in nums:
        player_number_one += filters[max_numbers] % 2 == 1
    if player_number_one * 2 == len(nums):
        return None
    if player_number_one * 2 > len(nums):
        return "Maria"
    return "Ben"
