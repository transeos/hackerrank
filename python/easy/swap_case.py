#!/usr/bin/python3
  
# -*- Python -*-
#
#*****************************************************************
#
# hackerrank: https://www.hackerrank.com/challenges/swap-case/problem
#
# WARRANTY:
# Use all material in this file at your own risk.
#
# Created by Hiranmoy Basak on 18/05/18.
#
#*****************************************************************
#

def swap_case(s):
  return s.swapcase()

if __name__ == '__main__':
    s = input()
    result = swap_case(s)
    print(result)
