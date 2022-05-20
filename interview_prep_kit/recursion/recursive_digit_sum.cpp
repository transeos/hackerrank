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

int superDigit(const string& n, const int k) {
  int64_t sum = 0;

  for (size_t i = 0; i < n.length(); ++i) {
    sum += static_cast<int64_t>(n[i] - '0');
  }

  sum *= (int64_t)k;

  auto calSuperDigitFn = [](int64_t n) {
    int result = 0;
    while (n > 0) {
      result += n % 10L;
      n /= 10L;
    }
    return result;
  };

  int result = calSuperDigitFn(sum);
  while (result >= 10) {
    result = calSuperDigitFn(result);
  }
  return result;
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
