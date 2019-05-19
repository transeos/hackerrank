#!/usr/bin/python3
  
# -*- Python -*-
#
#*****************************************************************
#
# hackerrank: https://www.hackerrank.com/challenges/calendar-module/problem
#
# WARRANTY:
# Use all material in this file at your own risk.
#
# Created by Hiranmoy Basak on 19/05/18.
#
#*****************************************************************
#

import calendar

date_params = list(map(int, input().split()))
assert(len(date_params) ==  3)

days = ["MONDAY", "TUESDAY", "WEDNESDAY", "THURSDAY", "FRIDAY", "SATURDAY", "SUNDAY"]
day_of_week = calendar.weekday(date_params[2], date_params[0], date_params[1])
print(days[day_of_week])
