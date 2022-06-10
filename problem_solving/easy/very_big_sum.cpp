// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/a-very-big-sum/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 11/06/22.
//
//*****************************************************************

#include "utils.h"
#include <bits/stdc++.h>
#include <catch2/catch.hpp>

using std::cin;
using std::cout;
using std::endl;
using std::ofstream;
using std::string;
using std::vector;

/*
 * Complete the 'aVeryBigSum' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts LONG_INTEGER_ARRAY ar as parameter.
 */

int64_t aVeryBigSum(const vector<int64_t>& arr) {
  return std::accumulate(arr.begin(), arr.end(), 0L);
}

TEST_CASE("very_big_sum", "[problem_solving][easy]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  string ar_count_temp;
  getline(cin, ar_count_temp);

  int ar_count = stoi(ltrim(rtrim(ar_count_temp)));

  string ar_temp_temp;
  getline(cin, ar_temp_temp);

  vector<string> ar_temp = split(rtrim(ar_temp_temp));

  vector<int64_t> ar(ar_count);

  for (int i = 0; i < ar_count; i++) {
    int64_t ar_item = stol(ar_temp[i]);

    ar[i] = ar_item;
  }

  int64_t result = aVeryBigSum(ar);

  fout << result << "\n";

  fout.close();
}
