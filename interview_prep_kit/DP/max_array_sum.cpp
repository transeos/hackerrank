// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/max-array-sum/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 03/01/21.
//
//*****************************************************************

#include "utils.h"
#include <bits/stdc++.h>
#include <catch2/catch.hpp>
#include <iostream>

using namespace std;

// Complete the maxSubsetSum function below.
int64_t maxSubsetSum(const vector<int>& arr) {
  if (arr.size() == 0) {
    return 0;
  }

  int64_t maxSumWithoutLastElm = 0;
  int64_t maxSum = max(0, arr[0]);

  for (size_t i = 1; i < arr.size(); ++i) {
    if (arr[i] <= 0) {
      maxSumWithoutLastElm = maxSum;
      continue;
    }

    const int64_t prevMaxSum = maxSum;
    maxSum = max(maxSum, maxSumWithoutLastElm + (int64_t)arr[i]);
    maxSumWithoutLastElm = prevMaxSum;
  }

  return maxSum;
}

TEST_CASE("max_array_sum", "[interview_prep_kit][DP][medium]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  int n;
  cin >> n;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  string arr_temp_temp;
  getline(cin, arr_temp_temp);

  vector<string> arr_temp = split_string(arr_temp_temp);

  vector<int> arr(n);

  for (int i = 0; i < n; i++) {
    int arr_item = stoi(arr_temp[i]);

    arr[i] = arr_item;
  }

  int res = maxSubsetSum(arr);

  fout << res << "\n";

  fout.close();
}
