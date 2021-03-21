// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/min-max-riddle/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 23/12/20.
//
//*****************************************************************
//
// Test case 2 takes 233 sec

#include "utils.h"
#include <bits/stdc++.h>
#include <catch2/catch.hpp>
#include <iostream>

using namespace std;

int FindInArr(const int val, const vector<int64_t>& arr, const int start_idx, const int end_idx) {
  if (arr[start_idx] == val) {
    return start_idx;
  }

  const int mid_idx = ((start_idx + end_idx + 1) / 2);
  if (arr[mid_idx] >= val) {
    return FindInArr(val, arr, mid_idx, end_idx);
  } else {
    return FindInArr(val, arr, start_idx, mid_idx);
  }
}

// Complete the riddle function below.
vector<int64_t> riddle(const vector<int64_t>& arr) {
  // complete this function

  const int arr_size = arr.size();

  vector<int64_t> result(arr_size, 0);

  vector<int64_t> min_end_window(arr_size, 0);

  int64_t min_val = numeric_limits<int64_t>::max();

  for (int i = 0; i < arr_size; ++i) {
    int end_idx = i;

    if (min_val > arr[i]) {
      min_val = arr[i];
    } else {
      end_idx = FindInArr(min_val, result, 0, (i - 1));

      result[i] = min_val;
      min_end_window[i] = min_val;
    }

    for (int j = end_idx; j >= 0; --j) {
      if (j == 0) {
        min_end_window[0] = arr[i];
      } else {
        min_end_window[j] = std::min(min_end_window[j - 1], arr[i]);
      }

      result[j] = std::max(result[j], min_end_window[j]);
    }
  }

  return result;
}

TEST_CASE("min_max_riddle",
          "[interview_prep_kit][stacks_queues][medium][star][incomplete][timeout]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  int n;
  cin >> n;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  string arr_temp_temp;
  getline(cin, arr_temp_temp);

  // start
  const chrono::high_resolution_clock::time_point start_time = chrono::high_resolution_clock::now();

  vector<string> arr_temp = split_string(arr_temp_temp);

  vector<long> arr(n);

  for (int i = 0; i < n; i++) {
    long arr_item = stol(arr_temp[i]);

    arr[i] = arr_item;
  }

  vector<int64_t> res = riddle(arr);

  for (int i = 0; i < res.size(); i++) {
    fout << res[i];

    if (i != res.size() - 1) {
      fout << " ";
    }
  }

  fout << "\n";

  fout.close();

  // end
  const chrono::high_resolution_clock::time_point end_time = chrono::high_resolution_clock::now();

  // run time
  const int run_time = chrono::duration_cast<chrono::seconds>(end_time - start_time).count();
  cout << "Time taken : " << run_time << " sec\n";
}
