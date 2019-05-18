#!/usr/bin/python3
  
# -*- Python -*-
#
#*****************************************************************
#
# hackerrank: https://www.hackerrank.com/challenges/python-string-formatting/problem
#
# WARRANTY:
# Use all material in this file at your own risk.
#
# Created by Hiranmoy Basak on 18/05/18.
#
#*****************************************************************
#

def print_formatted(number, padding = 0):
  # your code goes here
  if (number == 0):
    return

  bin_str = bin(number)[2:]

  if (padding == 0):
    padding = (len(bin_str) + 1)

  print_formatted((number - 1), padding) 

  print(str(number).rjust(padding - 1), end='')
  print(oct(number)[2:].rjust(padding), end='')
  print(hex(number)[2:].upper().rjust(padding), end='')
  print(bin_str.rjust(padding))

if __name__ == '__main__':
    n = int(input())
    print_formatted(n)
