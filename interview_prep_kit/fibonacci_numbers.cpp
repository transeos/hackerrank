// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/ctci-fibonacci-numbers/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 08/06/19.
//
//*****************************************************************

#include <bits/stdc++.h>
#include <cassert>
#include <iostream>

#include <catch2/catch.hpp>

using namespace std;

int fibonacci(int n) {
  // Complete the function.
  assert(n >= 0);

  if (n == 0) {
    return 0;
  }

  int prev_val = 0;  // n = 0
  int cur_val = 1;   // n = 1

  for (int idx = 2; idx <= n; ++idx) {
    const int prev_prev_val = prev_val;
    prev_val = cur_val;
    cur_val = cur_val + prev_prev_val;
  }

  return cur_val;
}

TEST_CASE("fibonacci_numbers", "[interview_prep_kit][recursion][easy]") {
  int n;
  cin >> n;
  cout << fibonacci(n);
}
