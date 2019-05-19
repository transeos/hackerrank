// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/minimum-swaps-2/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 13/05/19.
//
//*****************************************************************

#include <bits/stdc++.h>
#include <iostream>

#include "utils.h"
#include <catch2/catch.hpp>

using namespace std;

// Complete the minimumSwaps function below.
int minimumSwaps(vector<int> arr) {
  int num_swaps = 0;
  const int num_arr = arr.size();

  for (size_t idx = 0; idx < num_arr; ++idx) {
    int cur_val = arr[idx];
    while (cur_val != (idx + 1)) {
      const int temp_val = arr[cur_val - 1];
      arr[cur_val - 1] = cur_val;
      arr[idx] = temp_val;
      cur_val = temp_val;

      num_swaps++;
    }
  }

  return num_swaps;
}

TEST_CASE("minimum_swaps", "[interview_prep_kit][array][medium]") {
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

  int res = minimumSwaps(arr);

  fout << res << "\n";

  fout.close();
}
