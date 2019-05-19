#!/usr/bin/python3
  
# -*- Python -*-
#
#*****************************************************************
#
# hackerrank: https://www.hackerrank.com/challenges/defaultdict-tutorial/problem
#
# WARRANTY:
# Use all material in this file at your own risk.
#
# Created by Hiranmoy Basak on 19/05/18.
#
#*****************************************************************
#

# Enter your code here. Read input from STDIN. Print output to STDOUT
from collections import defaultdict

catagories = list(map(int, input().split()))

numd = defaultdict(list)

for idx in range(catagories[0]):
  numd[catagories[0]].append(input())

for idx in range(catagories[1]):
  word = input()

  indices = [i for i, x in enumerate(numd[catagories[0]]) if x == word]

  for j in indices:
    print((j + 1),"", end='')

  if (len(indices) == 0):
    print("-1", end='')
    
  print()
