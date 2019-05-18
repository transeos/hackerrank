#!/usr/bin/python3
  
# -*- Python -*-
#
#*****************************************************************
#
# hackerrank: https://www.hackerrank.com/challenges/designer-door-mat/problem
#
# WARRANTY:
# Use all material in this file at your own risk.
#
# Created by Hiranmoy Basak on 18/05/18.
#
#*****************************************************************
#

# Enter your code here. Read input from STDIN. Print output to STDOUT

query, *line = input().split()
nums = list(map(int, line))

N = int(query)
M = int(nums[0])

assert (M == (3 * N))

sym = ".|."

half_range = int((N - 1) / 2)
for idx in range(half_range):
  sym_str = sym;
  for j in range(idx * 2):
    sym_str = sym_str+sym;
  print (sym_str.center(M,'-'))

print ('WELCOME'.center(M,'-'))

for idx in range(half_range):
  sym_str = sym;
  j = idx * 2
  while j < (half_range * 2 - 2):
    sym_str = sym_str+sym;
    j += 1

  print (sym_str.center(M,'-'))
