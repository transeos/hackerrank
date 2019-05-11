// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/c-tutorial-for-loop/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 12/05/19.
//
//*****************************************************************

#include <array>
#include <cstdio>
#include <iostream>

#include <catch2/catch.hpp>

using namespace std;

TEST_CASE("for_loop", "[cpp][easy]") {
  // Complete the code.

  array<const char*, 9> num_str_arr = {"one", "two",   "three", "four", "five",
                                       "six", "seven", "eight", "nine"};

  int start = 0, end = 0;
  cin >> start;
  cin >> end;

  if (start <= 0) {
    // invalid input
    REQUIRE(false);
  }

  if (end < start) {
    // invalid input
    REQUIRE(false);
  }

  const int loop1_end = (end > 9 ? 9 : end);

  for (int idx = start; idx <= loop1_end; idx++) {
    cout << num_str_arr[idx - 1] << endl;
  }

  for (int idx = 10; idx <= end; idx++) {
    if ((idx % 2) == 0) {
      cout << "even\n";
    } else {
      cout << "odd\n";
    }
  }
}
