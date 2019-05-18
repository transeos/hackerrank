#!/usr/bin/python3
  
# -*- Python -*-
#
#*****************************************************************
#
# hackerrank: https://www.hackerrank.com/challenges/nested-list/problem
#
# WARRANTY:
# Use all material in this file at your own risk.
#
# Created by Hiranmoy Basak on 16/05/18.
#
#*****************************************************************
#

if __name__ == '__main__':
  students_min_score = []
  students_2nd_min_score = []

  min_score = 100.1
  second_min_score = 100.1

  for _ in range(int(input())):
    name = input()
    score = float(input())
    assert(score < 100.1);

    if (min_score > score):
      second_min_score = min_score
      min_score = score

      students_2nd_min_score = students_min_score
      students_min_score = [name]
    elif (min_score == score):
      students_min_score.append(name)
    elif (second_min_score > score):
      second_min_score = score
      students_2nd_min_score = [name]
    elif (second_min_score == score):
      students_2nd_min_score.append(name)
    
  students_2nd_min_score.sort()
  for student in students_2nd_min_score:
    print(student)
else:
  exit(1)
