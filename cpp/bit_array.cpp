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

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>

#include <catch2/catch.hpp>

using namespace std;

TEST_CASE("bit_array", "[cpp][hard]") {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */

  const long max = (1L << 31);
  long N = 0, S = 0, P = 0, Q = 0;
  cin >> N >> S >> P >> Q;

  vector<bool> items(max, false);

  long cur_item = S;

  items[cur_item] = true;
  int count = 1;

  for (int idx = 1; idx < N; ++idx) {
    cur_item = (((cur_item * P) + Q) % max);
    if (items[cur_item] == false) {
      items[cur_item] = true;
      count++;
    }
  }

  cout << count << endl;
}
