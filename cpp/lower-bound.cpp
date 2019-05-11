// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/cpp-lower-bound/problem
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

TEST_CASE("lower-bound", "[cpp][easy]") {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */

  vector<int> nums;
  int arr_size = 0;

  cin >> arr_size;
  nums.resize(arr_size);

  for (int idx = 0; idx < arr_size; ++idx) {
    cin >> nums[idx];
  }

  int num_queries = 0;
  cin >> num_queries;

  for (int idx = 0; idx < num_queries; ++idx) {
    int query_num = 0;
    cin >> query_num;

    auto low = lower_bound(nums.begin(), nums.end(), query_num);
    if (*low == query_num) {
      cout << "Yes " << (low - nums.begin() + 1) << endl;
    } else {
      auto up = upper_bound(nums.begin(), nums.end(), query_num);
      cout << "No " << (low - nums.begin() + 1) << endl;
    }
  }
}
