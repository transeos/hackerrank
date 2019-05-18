#!/usr/bin/python3
  
# -*- Python -*-
#
#*****************************************************************
#
# hackerrank: https://www.hackerrank.com/challenges/capitalize/problem
#
# WARRANTY:
# Use all material in this file at your own risk.
#
# Created by Hiranmoy Basak on 18/05/18.
#
#*****************************************************************
#

import math
import os
import random
import re
import sys

# Complete the solve function below.
def solve(s):
  words = s.split(' ')

  new_name = ""
  for word in words:
    if (len(word)):
      new_name += word[0].upper()    
      new_name += word[1:]
    new_name += " "

  return new_name

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = solve(s)

    fptr.write(result + '\n')

    fptr.close()
