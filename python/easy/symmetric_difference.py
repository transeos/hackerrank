#!/usr/bin/python3
  
# -*- Python -*-
#
#*****************************************************************
#
# hackerrank: https://www.hackerrank.com/challenges/symmetric-difference/problem
#
# WARRANTY:
# Use all material in this file at your own risk.
#
# Created by Hiranmoy Basak on 19/05/18.
#
#*****************************************************************
#

# Enter your code here. Read input from STDIN. Print output to STDOUT

N = input()
set1 = set(list(map(int, input().split())))
M = input()
set2 = set(list(map(int, input().split())))

diff = set1.difference(set2)
diff = diff.union(set2.difference(set1))
diff = sorted(diff)

for num in diff:
  print(num)
