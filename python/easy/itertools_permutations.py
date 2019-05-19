#!/usr/bin/python3
  
# -*- Python -*-
#
#*****************************************************************
#
# hackerrank: https://www.hackerrank.com/challenges/itertools-permutations/problem
#
# WARRANTY:
# Use all material in this file at your own risk.
#
# Created by Hiranmoy Basak on 18/05/18.
#
#*****************************************************************
#

# Enter your code here. Read input from STDIN. Print output to STDOUT
from itertools import permutations

user_inputs = input().split()

chars = list(user_inputs[0])

strs = list(permutations(chars, int(user_inputs[1])))

output = []
for string in strs:
  line = ""
  for c in string:
    line = line + c
  output.append(line)

output.sort()
for string in output:
  print(string)
