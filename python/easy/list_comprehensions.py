#!/usr/bin/python3
  
# -*- Python -*-
#
#*****************************************************************
#
# hackerrank: https://www.hackerrank.com/challenges/list-comprehensions/problem
#
# WARRANTY:
# Use all material in this file at your own risk.
#
# Created by Hiranmoy Basak on 18/05/18.
#
#*****************************************************************
#

if __name__ == '__main__':
    x = int(input())
    y = int(input())
    z = int(input())
    n = int(input())

all_coordinates = [];

for i in range(x + 1):
  for j in range(y + 1):
    for k in range(z + 1):
      if ((i + j + k) == n):
        continue

      coordinates = [i, j, k];
      all_coordinates.append(coordinates);

print (all_coordinates)
