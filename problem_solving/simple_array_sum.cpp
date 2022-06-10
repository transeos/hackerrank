// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/simple-array-sum/problem
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
 * Complete the 'simpleArraySum' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY ar as parameter.
 */

int32_t simpleArraySum(const vector<int>& arr) {
  return std::accumulate(arr.begin(), arr.end(), 0);
}

TEST_CASE("simple_array_sum", "[problem_solving][easy]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  string ar_count_temp;
  getline(cin, ar_count_temp);

  int ar_count = stoi(ltrim(rtrim(ar_count_temp)));

  string ar_temp_temp;
  getline(cin, ar_temp_temp);

  vector<string> ar_temp = split(rtrim(ar_temp_temp));

  vector<int> ar(ar_count);

  for (int i = 0; i < ar_count; i++) {
    int ar_item = stoi(ar_temp[i]);

    ar[i] = ar_item;
  }

  int result = simpleArraySum(ar);

  fout << result << "\n";

  fout.close();
}
