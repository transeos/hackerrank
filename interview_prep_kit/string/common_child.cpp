// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/common-child/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 02/01/21.
//
//*****************************************************************

#include "utils.h"
#include <bits/stdc++.h>
#include <catch2/catch.hpp>
#include <iostream>

using namespace std;

// Complete the commonChild function below.
int commonChild(const string& s1, const string& s2) {
  const int str_len = s1.length();
  assert(s2.length() == str_len);

  vector<vector<int>> matched_str;
  matched_str.resize(str_len + 1);

  for (size_t i = 0; i <= str_len; ++i) {
    matched_str[i].resize(str_len + 1);
    matched_str[i][0] = 0;
  }

  for (size_t j = 0; j <= str_len; ++j) {
    matched_str[0][j] = 0;
  }

  for (size_t i = 1; i <= str_len; ++i) {
    for (size_t j = 1; j <= str_len; ++j) {
      int data1 = ((s1[i - 1] == s2[j - 1]) + matched_str[i - 1][j - 1]);
      int data2 = matched_str[i - 1][j];
      int data3 = matched_str[i][j - 1];

      matched_str[i][j] = std::max(data1, std::max(data2, data3));
    }
  }

  return matched_str[str_len][str_len];
}

TEST_CASE("common_child", "[interview_prep_kit][string][medium]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  string s1;
  getline(cin, s1);

  string s2;
  getline(cin, s2);

  int result = commonChild(s1, s2);

  fout << result << "\n";

  fout.close();
}
