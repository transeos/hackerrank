// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/ctci-merge-sort/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 17/12/20.
//
//*****************************************************************

#include "utils.h"
#include <bits/stdc++.h>
#include <catch2/catch.hpp>

using namespace std;

// Complete the countInversions function below.
long countInversions(vector<int>& arr, int start_idx, int end_idx) {
  if (start_idx >= end_idx) {
    return 0;
  }

  int divide_idx = ((start_idx + end_idx) / 2);

  int64_t count = (countInversions(arr, start_idx, divide_idx) +
                   countInversions(arr, (divide_idx + 1), end_idx));

  int arr1_idx = start_idx;
  for (size_t idx = (divide_idx + 1); idx <= end_idx; ++idx) {
    while ((arr[arr1_idx] <= arr[idx]) && (arr1_idx <= divide_idx)) {
      arr1_idx++;
    }

    if (arr1_idx > divide_idx) {
      break;
    }

    count += (divide_idx - arr1_idx + 1);
  }

  auto iter_begin = (arr.begin() + start_idx);
  auto iter_end = ((end_idx != (arr.size() - 1)) ? (arr.begin() + end_idx + 1) : arr.end());

  if ((iter_begin != arr.begin()) || (iter_end != arr.end())) {
    std::sort(iter_begin, iter_end);
  }

  return count;
}

TEST_CASE("counting_inversions", "[interview_prep_kit][sorting][hard]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  int t;
  cin >> t;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  for (int t_itr = 0; t_itr < t; t_itr++) {
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

    long result = countInversions(arr, 0, (n - 1));

    fout << result << "\n";
  }

  fout.close();
}
