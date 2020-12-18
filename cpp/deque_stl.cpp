// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/deque-stl/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 19/05/19.
//
//*****************************************************************

#include <algorithm>
#include <catch2/catch.hpp>
#include <chrono>
#include <deque>
#include <iostream>

using namespace std;

void printKMax(int arr[], int n, int k) {
  // Write your code here.

  deque<int> sub_arr;
  int max_val = 0;
  int num_max_elm = 0;

  auto update_max = [&max_val, &num_max_elm](const int cur_val) {
    if (max_val < cur_val) {
      max_val = cur_val;
      num_max_elm = 1;
    } else if (max_val == cur_val) {
      num_max_elm++;
    }
  };

  for (size_t idx = 0; idx < k; ++idx) {
    const int cur_val = arr[idx];
    sub_arr.push_back(cur_val);

    update_max(cur_val);
  }

  // first max element
  cout << max_val;

  for (size_t idx = k; idx < n; ++idx) {
    const int cur_val = arr[idx];
    sub_arr.push_back(cur_val);

    update_max(cur_val);

    const int last_elm = sub_arr.front();
    sub_arr.pop_front();

    if (max_val == last_elm) {
      num_max_elm--;

      if (num_max_elm == 0) {
        max_val = 0;

        // find current max
        for (int cur_val : sub_arr) {
          update_max(cur_val);
        }
      }
    }

    // max element
    cout << " " << max_val;
  }

  cout << endl;
}

TEST_CASE("deque_stl", "[cpp][medium]") {
  int t;
  cin >> t;

  int run_time = 0;

  while (t > 0) {
    int n, k;
    cin >> n >> k;
    int i;
    int arr[n];
    for (i = 0; i < n; i++) cin >> arr[i];

    // start
    const chrono::high_resolution_clock::time_point start_time =
        chrono::high_resolution_clock::now();

    printKMax(arr, n, k);

    // end
    const chrono::high_resolution_clock::time_point end_time = chrono::high_resolution_clock::now();

    // add run time
    run_time += chrono::duration_cast<chrono::seconds>(end_time - start_time).count();
    t--;
  }

  cout << "Time taken : " << run_time << " sec\n";
}
