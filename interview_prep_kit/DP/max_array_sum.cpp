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
int maxSubsetSum(const vector<int>& arr) {
  int max_sum = std::max(arr[0], 0);
  int prev_sum = 0;

  for (size_t idx = 1; idx < arr.size(); ++idx) {
    const int temp = max_sum;
    max_sum = std::max(prev_sum + arr[idx], max_sum);
    prev_sum = temp;
  }

  return max_sum;
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
