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

int32_t hackerlandRadioTransmitters(const vector<int>& x, const int32_t k) {
  return 0;
}

TEST_CASE("hackerland_radio_transmitters", "[problem_solving][medium]") {
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
