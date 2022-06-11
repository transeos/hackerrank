// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/mini-max-sum/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 11/06/22.
//
//*****************************************************************

#include "utils.h"
#include <bits/stdc++.h>
#include <catch2/catch.hpp>

using std::cin;
using std::cout;
using std::endl;
using std::ofstream;
using std::string;
using std::vector;

/*
 * Complete the 'miniMaxSum' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

void miniMaxSum(const vector<int>& arr) {
  int32_t min = arr[0];
  int32_t max = arr[0];
  int64_t sum = arr[0];

  for (size_t i = 1; i < 5; ++i) {
    min = std::min(min, arr[i]);
    max = std::max(max, arr[i]);
    sum += arr[i];
  }

  cout << sum - (int64_t)max << " " << sum - (int64_t)min << endl;
}

TEST_CASE("mini_max_sum", "[problem_solving][easy]") {
  string arr_temp_temp;
  getline(cin, arr_temp_temp);

  vector<string> arr_temp = split(rtrim(arr_temp_temp));

  vector<int> arr(5);

  for (int i = 0; i < 5; i++) {
    int arr_item = stoi(arr_temp[i]);

    arr[i] = arr_item;
  }

  miniMaxSum(arr);
}
