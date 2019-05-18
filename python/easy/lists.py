#!/usr/bin/python3
  
# -*- Python -*-
#
#*****************************************************************
#
# hackerrank: https://www.hackerrank.com/challenges/python-lists/problem
#
# WARRANTY:
# Use all material in this file at your own risk.
#
# Created by Hiranmoy Basak on 18/05/18.
#
#*****************************************************************
#

if __name__ == '__main__':
  items = []

  N = int(input())
  for query_idx in range(N):
    query, *line = input().split()
    nums = list(map(int, line))
    
    if (query == "insert"):
      items.insert(nums[0], nums[1])
    elif (query == "remove"):
      items.remove(nums[0])
    elif (query == "append"):
      items.append(nums[0])
    elif (query == "sort"):
      items.sort()
    elif (query == "reverse"):
      items.reverse()
    elif (query == "pop"):
      items.pop()
    elif (query == "print"):
      print (items)
    else:
      assert(False)
else:
  exit(1)
