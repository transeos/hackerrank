// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/a-very-big-sum/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 11/06/22.
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
 * Complete the 'diagonalDifference' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY arr as parameter.
 */

int64_t diagonalDifference(const vector<vector<int>>& arr) {
  const size_t rowLen = arr.size();

  int64_t diff = 0;

  for (size_t i = 0; i < rowLen; i++) {
    diff += arr[i][i] - arr[rowLen - i - 1][i];
  }

  return std::abs(diff);
}

TEST_CASE("diagonal_difference", "[problem_solving][easy]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  string n_temp;
  getline(cin, n_temp);

  int n = stoi(ltrim(rtrim(n_temp)));

  vector<vector<int>> arr(n);

  for (int i = 0; i < n; i++) {
    arr[i].resize(n);

    string arr_row_temp_temp;
    getline(cin, arr_row_temp_temp);

    vector<string> arr_row_temp = split(rtrim(arr_row_temp_temp));

    for (int j = 0; j < n; j++) {
      int arr_row_item = stoi(arr_row_temp[j]);

      arr[i][j] = arr_row_item;
    }
  }

  int result = diagonalDifference(arr);

  fout << result << "\n";

  fout.close();
}
