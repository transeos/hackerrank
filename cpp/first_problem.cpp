// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/solve-me-first/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 12/05/19.
//
//*****************************************************************

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>

#include <catch2/catch.hpp>

using namespace std;

int solveMeFirst(int a, int b) {
  // Hint: Type return a+b; below:
  return (a + b);
}

TEST_CASE("first_problem", "[cpp][easy]") {
  int num1, num2;
  int sum;
  cin >> num1 >> num2;
  sum = solveMeFirst(num1, num2);
  cout << sum;
}
