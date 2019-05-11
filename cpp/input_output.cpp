// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/cpp-input-and-output/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 12/05/19.
//
//*****************************************************************

#include <algorithm>
#include <array>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>

#include <catch2/catch.hpp>

using namespace std;

TEST_CASE("input_output", "[cpp][easy]") {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  array<int, 3> nums;

  cin >> nums[0] >> nums[1] >> nums[2];
  cout << (nums[0] + nums[1] + nums[2]);
}
