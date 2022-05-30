// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/coin-change/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 27/05/22.
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
 * Complete the 'getWays' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. LONG_INTEGER_ARRAY c
 */

int64_t getWays(const int32_t n, vector<long>& c) {
  std::sort(c.begin(), c.end());

  std::vector<int32_t> changeTypes(n, 0);

  for (size_t i = 1; i <= n; ++i) {
    for (const int32_t coin : c) {
      if (coin >= i) {
        if (coin == i) {
          changeTypes[i - 1]++;
        }

        break;
      }

      changeTypes[i - 1] += changeTypes[i - 1 - coin];
    }

    std::for_each(changeTypes.begin(), changeTypes.end(), [](int32_t num) { cout << num << " "; });
    cout << endl;
  }

  return changeTypes[n - 1];
}

TEST_CASE("coin_change", "[problem_solving][medium][ToDo]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  string first_multiple_input_temp;
  getline(cin, first_multiple_input_temp);

  vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

  int n = stoi(first_multiple_input[0]);

  int m = stoi(first_multiple_input[1]);

  string c_temp_temp;
  getline(cin, c_temp_temp);

  vector<string> c_temp = split(rtrim(c_temp_temp));

  vector<long> c(m);

  for (int i = 0; i < m; i++) {
    long c_item = stol(c_temp[i]);

    c[i] = c_item;
  }

  // Print the number of ways of making change for 'n' units using coins having the values given by
  // 'c'

  long ways = getWays(n, c);

  fout << ways << "\n";

  fout.close();
}
