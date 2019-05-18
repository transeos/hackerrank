#!/usr/bin/python3
  
# -*- Python -*-
#
#*****************************************************************
#
# hackerrank: https://www.hackerrank.com/challenges/python-tuples/problem
#
# WARRANTY:
# Use all material in this file at your own risk.
#
# Created by Hiranmoy Basak on 18/05/18.
#
#*****************************************************************
#

if __name__ == '__main__':
  n = int(input())
  integer_list = map(int, input().split())
  
  tup = tuple(integer_list)
  print(hash(tup))
else:
  exit(1)
