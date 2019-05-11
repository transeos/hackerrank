// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/vector-erase/problem
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

TEST_CASE("vector-erase", "[cpp][easy]") {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */

  vector<int> nums;
  int arr_size = 0;

  cin >> arr_size;
  nums.resize(arr_size);

  for (int idx = 0; idx < arr_size; ++idx) {
    cin >> nums[idx];
  }

  int first_erased_idx = 0;
  int second_erase_start = 0, second_erase_end = 0;

  cin >> first_erased_idx;
  cin >> second_erase_start >> second_erase_end;

  nums.erase(nums.begin() + first_erased_idx - 1);
  nums.erase(nums.begin() + second_erase_start - 1, nums.begin() + second_erase_end - 1);

  const int cur_arr_size = nums.size();
  cout << cur_arr_size << endl;

  for (int idx = 0; idx < cur_arr_size; ++idx) {
    cout << nums[idx] << " ";
  }
}
