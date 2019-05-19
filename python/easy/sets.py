#!/usr/bin/python3
  
# -*- Python -*-
#
#*****************************************************************
#
# hackerrank: https://www.hackerrank.com/challenges/py-introduction-to-sets/problem
#
# WARRANTY:
# Use all material in this file at your own risk.
#
# Created by Hiranmoy Basak on 18/05/18.
#
#*****************************************************************
#

def average(array):
  # your code goes here
  heights = set(array)
  return sum(heights)/len(heights)

if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))
    result = average(arr)
    print(result)
