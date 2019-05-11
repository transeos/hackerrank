// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/c-tutorial-pointer/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 12/05/19.
//
//*****************************************************************

#include <iostream>
#include <stdio.h>

#include <catch2/catch.hpp>

using namespace std;

void update(int* a, int* b) {
  // Complete this function
  const int a_val = *a;
  const int b_val = *b;

  *a = (a_val + b_val);
  *b = (a_val - b_val);

  if (*b < 0) {
    *b *= (-1);
  }
}

TEST_CASE("pointer", "[cpp][easy]") {
  int a, b;
  int *pa = &a, *pb = &b;

  scanf("%d %d", &a, &b);
  update(pa, pb);
  printf("%d\n%d", a, b);
}
