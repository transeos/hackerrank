#!/usr/bin/python3
  
# -*- Python -*-
#
#*****************************************************************
#
# hackerrank: https://www.hackerrank.com/challenges/py-if-else/problem
#
# WARRANTY:
# Use all material in this file at your own risk.
#
# Created by Hiranmoy Basak on 18/05/18.
#
#*****************************************************************
#

N = int(input())

if (N < 1):
  exit(1)

if (N % 2):
  print("Weird")
elif (N <= 6):
  print("Not Weird")
elif (N <= 20):
  print("Weird")
else:
  print("Not Weird")
