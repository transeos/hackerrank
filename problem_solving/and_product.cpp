// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/and-product/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 24/05/22.
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
 * Complete the 'andProduct' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. LONG_INTEGER a
 *  2. LONG_INTEGER b
 */

uint64_t andProduct(uint64_t a, uint64_t b) {
  std::bitset<64> startBits(a);
  std::bitset<64> endBits(b);

  uint64_t result = 0;

  for (int64_t i = 63; i >= 0; i--) {
    if (startBits.test(i) == endBits.test(i)) {
      if (startBits.test(i)) {
        result += 1L << i;
      }
    } else {
      break;
    }
  }

  return result;
}

TEST_CASE("and_product", "[problem_solving][medium]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  string n_temp;
  getline(cin, n_temp);

  int n = stoi(ltrim(rtrim(n_temp)));

  for (int n_itr = 0; n_itr < n; n_itr++) {
    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    long a = stol(first_multiple_input[0]);

    long b = stol(first_multiple_input[1]);

    int64_t result = andProduct(a, b);

    fout << result << "\n";
  }

  fout.close();
}
