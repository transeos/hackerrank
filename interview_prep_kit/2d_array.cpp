// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/2d-array/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 12/05/19.
//
//*****************************************************************

#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>

#include <catch2/catch.hpp>

using namespace std;

// Complete the hourglassSum function below.
int hourglassSum(const vector<vector<int>>& arr) {
  int sum = numeric_limits<int>::min();

  assert((arr.size() == 6) && (arr[0].size() == 6) && (arr[5].size() == 6));

  for (size_t row = 1; row < 5; ++row) {
    assert(arr[row].size() == 6);

    for (size_t col = 1; col < 5; ++col) {
      const int cur_sum =
          (arr[row - 1][col - 1] + arr[row - 1][col] + arr[row - 1][col + 1] + arr[row][col] +
           arr[row + 1][col - 1] + arr[row + 1][col] + arr[row + 1][col + 1]);
      sum = max(sum, cur_sum);
    }
  }

  return sum;
}

TEST_CASE("2d_array", "[interview_prep_kit][easy]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  vector<vector<int>> arr(6);
  for (int i = 0; i < 6; i++) {
    arr[i].resize(6);

    for (int j = 0; j < 6; j++) {
      cin >> arr[i][j];
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }

  int result = hourglassSum(arr);

  fout << result << "\n";

  fout.close();
}
