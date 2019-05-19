#!/usr/bin/python3
  
# -*- Python -*-
#
#*****************************************************************
#
# hackerrank: https://www.hackerrank.com/challenges/polar-coordinates/problem
#
# WARRANTY:
# Use all material in this file at your own risk.
#
# Created by Hiranmoy Basak on 18/05/18.
#
#*****************************************************************
#

# Enter your code here. Read input from STDIN. Print output to STDOUT
import cmath

complex_num = complex(input())

r = abs(complex_num)
phi = cmath.phase(complex_num)

print(r)
print(phi)
