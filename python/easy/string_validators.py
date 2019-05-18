#!/usr/bin/python3
  
# -*- Python -*-
#
#*****************************************************************
#
# hackerrank: https://www.hackerrank.com/challenges/string-validators/problem
#
# WARRANTY:
# Use all material in this file at your own risk.
#
# Created by Hiranmoy Basak on 18/05/18.
#
#*****************************************************************
#

if __name__ == '__main__':
  s = input()

  for line in range(5):
    output = False

    for idx in range(len(s)):
      if (line == 0):
        if (s[idx].isalnum()):
          output = True
          break
      if (line == 1):
        if (s[idx].isalpha()):
          output = True
          break
      elif (line == 2):
        if (s[idx].isdigit()):
          output = True
          break
      elif (line == 3):
        if (s[idx].islower()):
          output = True
          break
      elif (line == 4):
        if (s[idx].isupper()):
          output = True
          break

    print(output)
else:
  exit(1)
