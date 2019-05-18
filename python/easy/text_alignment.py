#!/usr/bin/python3
  
# -*- Python -*-
#
#*****************************************************************
#
# hackerrank: https://www.hackerrank.com/challenges/text-alignment/problem
#
# WARRANTY:
# Use all material in this file at your own risk.
#
# Created by Hiranmoy Basak on 18/05/18.
#
#*****************************************************************
#

#Replace all ______ with rjust, ljust or center. 

thickness = int(input()) #This must be an odd number
c = 'H'

#Top Cone
for i in range(thickness):
  cstr = ""
  for j in range(i):
    cstr = cstr+c;

  print (cstr.rjust(thickness - 1), end='')
  print (c, end='')
  print (cstr)

  #print((c*i).______(thickness-1)+c+(c*i).______(thickness-1))

#Top Pillars
for i in range(thickness+1):
  cstr = ""
  for j in range(thickness):
    cstr = cstr+c;

  print (cstr.center(thickness*2), end='')
  print (cstr.center(thickness*6))

  #print((c*thickness).______(thickness*2)+(c*thickness).______(thickness*6))

#Middle Belt
for i in range((thickness+1)//2):
  cstr = ""
  for j in range(thickness*5):
    cstr = cstr+c;

  print (cstr.center(thickness*6))

  #print((c*thickness*5).______(thickness*6))    

#Bottom Pillars
for i in range(thickness+1):
  cstr = ""
  for j in range(thickness):
    cstr = cstr+c;

  print (cstr.center(thickness*2), end='')
  print (cstr.center(thickness*6))

  #print((c*thickness).______(thickness*2)+(c*thickness).______(thickness*6))    

#Bottom Cone
for i in range(thickness):
  cstr = ""
  j = i
  while j < (thickness - 1):
    cstr = cstr+c;
    j += 1

  print (cstr.rjust(thickness*5 - 1), end='')
  print (c, end='')
  print (cstr)

  #print(((c*(thickness-i-1)).______(thickness)+c+(c*(thickness-i-1)).______(thickness)).______(thickness*6))
