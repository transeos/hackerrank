// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/magic-square-forming/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 22/05/22.
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
 * Complete the 'formingMagicSquare' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY s as parameter.
 */

int32_t formingMagicSquare(const vector<vector<int>>& s) {
  return 0;
}

TEST_CASE("magic_square_forming", "[problem_solving][medium][ToDo]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  vector<vector<int>> s(3);

  for (int i = 0; i < 3; i++) {
    s[i].resize(3);

    string s_row_temp_temp;
    getline(cin, s_row_temp_temp);

    vector<string> s_row_temp = split(rtrim(s_row_temp_temp));

    for (int j = 0; j < 3; j++) {
      int s_row_item = stoi(s_row_temp[j]);

      s[i][j] = s_row_item;
    }
  }

  int result = formingMagicSquare(s);

  fout << result << "\n";

  fout.close();
}
