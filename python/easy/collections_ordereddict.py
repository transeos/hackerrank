#!/usr/bin/python3
  
# -*- Python -*-
#
#*****************************************************************
#
# hackerrank: https://www.hackerrank.com/challenges/py-collections-ordereddict/problem
#
# WARRANTY:
# Use all material in this file at your own risk.
#
# Created by Hiranmoy Basak on 19/05/18.
#
#*****************************************************************
#

# Enter your code here. Read input from STDIN. Print output to STDOUT

from collections import OrderedDict

N = int(input())
all_items = OrderedDict()
for idx in range(N):
  item_data = input()

  price_pos = len(item_data) - 1
  while (item_data[price_pos] != ' '):
    price_pos -= 1

  item_name = item_data[:price_pos]
  item_price = int(item_data[price_pos:])

  if item_name in all_items:
    all_items[item_name] = all_items[item_name] + item_price
  else:
    all_items[item_name] = item_price

for item in all_items:
  print(item, all_items[item])
