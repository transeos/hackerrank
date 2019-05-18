#!/usr/bin/python3
  
# -*- Python -*-
#
#*****************************************************************
#
# hackerrank: https://www.hackerrank.com/challenges/alphabet-rangoli/problem
#
# WARRANTY:
# Use all material in this file at your own risk.
#
# Created by Hiranmoy Basak on 18/05/18.
#
#*****************************************************************
#

def print_rangoli(size):
  # your code goes here
  lines = []

  for idx in range(size):
    line = chr(ord('a') + size - 1)
    for j in range(idx - 1):
      line = line + "-" + chr(ord('a') + size - 2 - j)

    if (idx > 0):
      line = line + "-" + chr(ord('a') + size - 1 - idx) + "-" + line[::-1]

    lines.append(line)

  padding = len(lines[len(lines) - 1])
  for idx in range(len(lines)):
    print(lines[idx].center(padding, '-'))

  for idx in range((len(lines) - 2), -1, -1):
    print(lines[idx].center(padding, '-'))

if __name__ == '__main__':
    n = int(input())
    print_rangoli(n)
