// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/non-divisible-subset/problem
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

uint32_t nonDivisibleSubset(const uint32_t k, const vector<int>& s) {
  vector<int32_t> modResult(k, 0);

  for (int num : s) {
    uint32_t remainder = num % k;

    if (remainder == 0) {
      modResult[0] = 1;
    } else if (k % 2 == 0 && remainder == k / 2) {
      modResult[remainder] = 1;
    } else {
      modResult[remainder]++;
    }
  }

  uint32_t subSetSize = modResult[0];
  if (k % 2 == 0) {
    subSetSize += modResult[k / 2];
  }

  for (size_t i = 1; i < (k + 1) / 2; ++i) {
    subSetSize += std::max(modResult[i], modResult[k - i]);
  }

  return subSetSize;
}

TEST_CASE("non_divisible_subset", "[problem_solving][medium]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  string first_multiple_input_temp;
  getline(cin, first_multiple_input_temp);

  vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

  int n = stoi(first_multiple_input[0]);

  int k = stoi(first_multiple_input[1]);

  string s_temp_temp;
  getline(cin, s_temp_temp);

  vector<string> s_temp = split(rtrim(s_temp_temp));

  vector<int> s(n);

  for (int i = 0; i < n; i++) {
    int s_item = stoi(s_temp[i]);

    s[i] = s_item;
  }

  int result = nonDivisibleSubset(k, s);

  fout << result << "\n";

  fout.close();
}
