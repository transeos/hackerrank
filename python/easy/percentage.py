#!/usr/bin/python3
  
# -*- Python -*-
#
#*****************************************************************
#
# hackerrank: https://www.hackerrank.com/challenges/finding-the-percentage/problem
#
# WARRANTY:
# Use all material in this file at your own risk.
#
# Created by Hiranmoy Basak on 18/05/18.
#
#*****************************************************************
#

if __name__ == '__main__':
  n = int(input())
  student_marks = {}
  for _ in range(n):
    name, *line = input().split()
    scores = list(map(float, line))
    student_marks[name] = scores
  query_name = input()

  marks = student_marks[query_name]
  avg = sum(marks) / len(marks)

  print (int(avg), end="")
  print (".", end="")

  decimal = int((avg - int(avg)) * 100)
  print (decimal if decimal else "00")
else:
  exit(1)
