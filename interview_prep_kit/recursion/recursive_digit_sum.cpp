// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/recursive-digit-sum/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 30/12/20.
//
//*****************************************************************

#include "utils.h"
#include <bits/stdc++.h>
#include <catch2/catch.hpp>
#include <iostream>

using namespace std;

unordered_map<uint64_t, int> super_digits;

int superDigit(const uint64_t n) {
  if (n < 10) {
    return n;
  }

  auto iter = super_digits.find(n);
  if (iter != super_digits.end()) {
    return iter->second;
  }

  int super_digit = 0;

  uint64_t cur_num = n;
  uint64_t prev_num = n;

  while (cur_num >= 10) {
    cur_num /= 10;
    super_digit += (prev_num - (cur_num * 10));
    prev_num = cur_num;
  }

  super_digit += cur_num;

  super_digit = superDigit(super_digit);
  super_digits[n] = super_digit;
  return super_digit;
}

// Complete the superDigit function below.
int superDigit(const string& big_num, int k) {
  int super_digit = 0;
  int last_idx = 0;

  for (size_t idx = 18; idx < big_num.size(); idx += 18) {
    super_digit += superDigit(stoul(big_num.substr((idx - 18), 18)));
    super_digit = superDigit(super_digit);
    last_idx = idx;
  }

  super_digit += superDigit(stoul(big_num.substr(last_idx)));

  super_digit = superDigit(super_digit * k);

  return super_digit;
}

TEST_CASE("recursive_digit_sum", "[interview_prep_kit][recursion][medium]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  string nk_temp;
  getline(cin, nk_temp);

  vector<string> nk = split_string(nk_temp);

  string n = nk[0];

  int k = stoi(nk[1]);

  int result = superDigit(n, k);

  fout << result << "\n";

  fout.close();
}
