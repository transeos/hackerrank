#!/usr/bin/python3
  
# -*- Python -*-
#
#*****************************************************************
#
# hackerrank: https://www.hackerrank.com/challenges/python-string-split-and-join/problem
#
# WARRANTY:
# Use all material in this file at your own risk.
#
# Created by Hiranmoy Basak on 18/05/18.
#
#*****************************************************************
#

import re

def split_and_join(line):
  # write your code here
  return re.sub(" ", "-", line)

if __name__ == '__main__':
    line = input()
    result = split_and_join(line)
    print(result)
