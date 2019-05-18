#!/usr/bin/python3
  
# -*- Python -*-
#
#*****************************************************************
#
# hackerrank: https://www.hackerrank.com/challenges/find-second-maximum-number-in-a-list/problem
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
  arr = map(int, input().split())
  
  max_num = -1000;
  runner_up = -1000;

  for num in arr:
    if (max_num < num):
      runner_up = max_num
      max_num = num
    elif ((max_num != num) and (runner_up < num)):
      runner_up = num
  
  print (max_num if (runner_up == -1000) else runner_up)
else:
  exit(1)
