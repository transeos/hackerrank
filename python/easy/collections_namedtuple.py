#!/usr/bin/python3
  
# -*- Python -*-
#
#*****************************************************************
#
# hackerrank: https://www.hackerrank.com/challenges/py-collections-namedtuple/problem
#
# WARRANTY:
# Use all material in this file at your own risk.
#
# Created by Hiranmoy Basak on 18/05/18.
#
#*****************************************************************
#

# Enter your code here. Read input from STDIN. Print output to STDOUT

from collections import namedtuple

Student = namedtuple('Student', 'ID MARKS NAME CLASS')
N, params, students = int(input()), input().split(), []
for idx in range(N):
  student_data = input().split()
  students.append(Student(ID=int(student_data[params.index("ID")]), MARKS=int(student_data[params.index("MARKS")]), NAME=student_data[params.index("NAME")], CLASS=int(student_data[params.index("CLASS")])))
print("%0.2f" % (sum(student_data.MARKS for student_data in students) / N))
