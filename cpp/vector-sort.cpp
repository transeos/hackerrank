// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/vector-sort/problem
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

bool compareInt(int a, int b) {
  return (a < b);
}

TEST_CASE("vector-sort-erase", "[cpp][easy]") {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */

  vector<int> nums;
  int arr_size = 0;

  cin >> arr_size;
  nums.resize(arr_size);

  for (int idx = 0; idx < arr_size; ++idx) {
    cin >> nums[idx];
  }

  // sort(nums.begin(), nums.end());
  // sort(nums.begin(), nums.end(), less<int>());
  sort(nums.begin(), nums.end(), compareInt);

  for (int idx = 0; idx < arr_size; ++idx) {
    cout << nums[idx] << " ";
  }
}
