// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/maximum-subarray-sum/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 20/12/20.
//
//*****************************************************************
//
// Test case 6 takes 2376 ms

#include "utils.h"
#include <bits/stdc++.h>
#include <catch2/catch.hpp>
#include <chrono>
#include <iostream>

using namespace std;

// Complete the maximumSum function below.
long maximumSum(vector<long>& a, const long m) {
  const int arr_size = a.size();

  vector<long> subArrSub(arr_size, 0);

  long max_val = 0;

  for (size_t i = 0; i < arr_size; ++i) {
    for (size_t j = 0; j <= i; ++j) {
      const long cur_val = ((subArrSub[j] + a[i]) % m);

      /*if (cur_val == (m - 1)) {
        // max possible value = 'm-1'
        return (m - 1);
      }*/

      max_val = ((cur_val > max_val) ? cur_val : max_val);
      subArrSub[j] = cur_val;
    }
  }

  return max_val;
}

TEST_CASE("maximum_subarray_sum", "[interview_prep_kit][search][hard][star][incomplete][timeout]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  int q;
  cin >> q;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  // start
  const chrono::high_resolution_clock::time_point start_time = chrono::high_resolution_clock::now();

  for (int q_itr = 0; q_itr < q; q_itr++) {
    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    long m = stol(nm[1]);

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split_string(a_temp_temp);

    vector<long> a(n);

    for (int i = 0; i < n; i++) {
      long a_item = stol(a_temp[i]);

      a[i] = a_item;
    }

    long result = maximumSum(a, m);

    fout << result << "\n";
  }

  fout.close();

  // end
  const chrono::high_resolution_clock::time_point end_time = chrono::high_resolution_clock::now();

  // run time
  const int run_time = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();
  cout << "Time taken : " << run_time << " msec\n";
}
