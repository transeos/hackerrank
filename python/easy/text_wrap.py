#!/usr/bin/python3
  
# -*- Python -*-
#
#*****************************************************************
#
# hackerrank: https://www.hackerrank.com/challenges/text-wrap/problem
#
# WARRANTY:
# Use all material in this file at your own risk.
#
# Created by Hiranmoy Basak on 18/05/18.
#
#*****************************************************************
#

import textwrap

def wrap(string, max_width):
  wrapped_str = ""

  wrap_strs = textwrap.wrap(string, width=max_width)  
  for x in wrap_strs:
    wrapped_str = wrapped_str+x+'\n'
  return wrapped_str

if __name__ == '__main__':
    string, max_width = input(), int(input())
    result = wrap(string, max_width)
    print(result)
