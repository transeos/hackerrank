// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/c-tutorial-conditional-if-else/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 12/05/19.
//
//*****************************************************************

#include <array>
#include <bits/stdc++.h>
#include <iostream>

#include <catch2/catch.hpp>

using namespace std;

TEST_CASE("conditional_statements", "[cpp][easy]") {
  int n;
  cin >> n;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  // Write Your Code Here

  array<const char*, 9> num_str_arr = {"one", "two",   "three", "four", "five",
                                       "six", "seven", "eight", "nine"};

  if (n <= 0) {
    // invalid input
    REQUIRE(false);
  } else if ((n > 0) && (n < 10)) {
    cout << num_str_arr[n - 1];
  } else {
    cout << "Greater than 9";
  }
}
