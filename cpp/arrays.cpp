// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/arrays-introduction/problem
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

TEST_CASE("arrays", "[cpp][easy]") {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */

  int arr_size = 0;
  cin >> arr_size;

  vector<int> numbers;
  numbers.resize(arr_size);

  for (int idx = 0; idx < arr_size; ++idx) {
    cin >> numbers[idx];
  }

  for (int idx = (arr_size - 1); idx >= 0; --idx) {
    cout << numbers[idx] << " ";
  }
}
