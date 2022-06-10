// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/hackerland-radio-transmitters/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 26/05/22.
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
 * Complete the 'hackerlandRadioTransmitters' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY x
 *  2. INTEGER k
 */

int64_t hackerlandRadioTransmitters(vector<int>& x, const int32_t k) {
  if (k <= 0) {
    return x.size();
  }

  std::sort(x.begin(), x.end());

  if (k >= (x.back() - x.front())) {
    return 1;
  }

  int64_t towerCount = 0;
  int64_t range = 1;

  for (size_t i = 1; i < x.size(); ++i) {
    const int64_t diff = x[i] - x[i - 1];
    range += diff;
    if (range > k + 1) {
      // place tower at previous city
      towerCount++;

      range = diff - k;
      if (range > 1) {
        // outside the range of previous city
        range = 1;
      }
    }
  }

  if (range > 0) {
    towerCount++;
  }

  return towerCount;
}

TEST_CASE("hackerland_radio_transmitters", "[problem_solving][medium][ToDo]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  string first_multiple_input_temp;
  getline(cin, first_multiple_input_temp);

  vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

  int n = stoi(first_multiple_input[0]);

  int k = stoi(first_multiple_input[1]);

  string x_temp_temp;
  getline(cin, x_temp_temp);

  vector<string> x_temp = split(rtrim(x_temp_temp));

  vector<int> x(n);

  for (int i = 0; i < n; i++) {
    int x_item = stoi(x_temp[i]);

    x[i] = x_item;
  }

  int result = hackerlandRadioTransmitters(x, k);

  fout << result << "\n";

  fout.close();
}
