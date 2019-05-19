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
#include <chrono>
#include <deque>
#include <iostream>

#include <catch2/catch.hpp>

using namespace std;

void printKMax(int arr[], int n, int k) {
  // Write your code here.

  deque<int> sub_arr = {arr[0]};
  deque<int> max_elms = {arr[0]};

  for (int idx = 1; idx < k; ++idx) {
    const int cur_item = arr[idx];
    sub_arr.push_back(cur_item);
    if (max_elms.back() >= cur_item) {
      max_elms.push_back(max_elms.front());
    } else
      max_elms.push_back(cur_item);
  }
  cout << max_elms[k - 1];

  for (int idx = 1; idx < (n - k + 1); ++idx) {
    const int last_elm = sub_arr.front();
    sub_arr.pop_front();
    sub_arr.push_back(arr[idx + k - 1]);

    const int last_max_elm = max_elms.front();
    max_elms.pop_front();
    if (last_max_elm != last_elm) continue;

    max_elms[0] = sub_arr[0];

    for (int idx = 1; idx < (k - 1); ++idx) {
      if (max_elms[idx] == last_elm) {
        max_elms[idx] = max(sub_arr[idx], max_elms[idx - 1]);
      }
    }

    max_elms.push_back(max(sub_arr[k - 1], max_elms[k - 2]));

    cout << " " << max_elms[k - 1];
  }

  cout << endl;
}

TEST_CASE("deque_stl", "[cpp][medium][incomplete]") {
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
