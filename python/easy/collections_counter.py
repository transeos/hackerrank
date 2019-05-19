#!/usr/bin/python3
  
# -*- Python -*-
#
#*****************************************************************
#
# hackerrank: https://www.hackerrank.com/challenges/collections-counter/problem
#
# WARRANTY:
# Use all material in this file at your own risk.
#
# Created by Hiranmoy Basak on 18/05/18.
#
#*****************************************************************
#

# Enter your code here. Read input from STDIN. Print output to STDOUT
from collections import Counter

X = int(input())
shoes = Counter(list(map(int, input().split())))
num_customer = int(input())

earnings = 0

for idx in range(num_customer):
  customer_inputs = list(map(int, input().split()))
  cur_stock = shoes[customer_inputs[0]]
  if (cur_stock):
    earnings += customer_inputs[1]
    shoes[customer_inputs[0]] = (cur_stock - 1)

print(earnings)
