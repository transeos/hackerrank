// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/bitset-1/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 11/05/19.
//
//*****************************************************************

// Test case 3 (100000000 923092883 976061291 1205350525) took 11 sec

#include <algorithm>
#include <catch2/catch.hpp>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

TEST_CASE("bit_array", "[cpp][hard][incomplete][timeout]") {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */

  long N = 0, S = 0, P = 0, Q = 0;
  cin >> N >> S >> P >> Q;

  // start
  const chrono::high_resolution_clock::time_point start_time = chrono::high_resolution_clock::now();

  vector<bool> items(numeric_limits<int>::max(), false);

  long cur_idx = S;

  items[cur_idx] = true;
  int count = 1;

  for (int idx = 1; idx < N; ++idx) {
    cur_idx = (((cur_idx * P) + Q) & 0x7FFFFFFF);
    count += (!items[cur_idx]);
    items[cur_idx] = true;
  }

  cout << count << endl;

  // end
  const chrono::high_resolution_clock::time_point end_time = chrono::high_resolution_clock::now();

  // run time
  const int run_time = chrono::duration_cast<chrono::seconds>(end_time - start_time).count();
  cout << "Time taken : " << run_time << " sec\n";
}
