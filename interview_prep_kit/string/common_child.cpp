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
int32_t commonChild(const string& s1, const string& s2) {
  const size_t rowSize = s1.length() + 1;
  const size_t columnSize = s2.length() + 1;

  vector<vector<int32_t>> result(rowSize);

  for_each(result.begin(), result.end(), [columnSize](auto& column) {
    column.resize(columnSize);
    column[0] = 0;
  });

  std::fill(result[0].begin(), result[0].end(), 0);

  for (size_t i = 1; i < rowSize; ++i) {
    for (size_t j = 1; j < columnSize; ++j) {
      if (s1[i - 1] == s2[j - 1]) {
        result[i][j] = result[i - 1][j - 1] + 1;
      } else {
        result[i][j] = max(result[i - 1][j], result[i][j - 1]);
      }
    }
  }

  return result[rowSize - 1][columnSize - 1];
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
