// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/3d-surface-area/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 25/05/22.
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
 * Complete the 'surfaceArea' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY A as parameter.
 */

int32_t surfaceArea(const vector<vector<int>>& A) {
  const size_t numRows = A.size();
  if (numRows == 0) {
    return 0;
  }

  const size_t numColumns = A[0].size();
  if (numColumns == 0) {
    return 0;
  }

  // top + bottom
  int32_t surfaceArea = numRows * numColumns * 2;

  // 2 sides
  for (size_t rowIndex = 0; rowIndex < numRows; ++rowIndex) {
    surfaceArea += A[rowIndex].front() + A[rowIndex].back();
  }

  // 2 sides
  for (size_t columnIndex = 0; columnIndex < numColumns; ++columnIndex) {
    surfaceArea += A.front()[columnIndex] + A.back()[columnIndex];
  }

  // middle
  for (size_t rowIndex = 1; rowIndex < numRows; ++rowIndex) {
    for (size_t columnIndex = 0; columnIndex < numColumns; ++columnIndex) {
      surfaceArea += std::abs(A[rowIndex - 1][columnIndex] - A[rowIndex][columnIndex]);
    }
  }
  for (size_t columnIndex = 1; columnIndex < numColumns; ++columnIndex) {
    for (size_t rowIndex = 0; rowIndex < numRows; ++rowIndex) {
      surfaceArea += std::abs(A[rowIndex][columnIndex - 1] - A[rowIndex][columnIndex]);
    }
  }

  return surfaceArea;
}

TEST_CASE("3d_surface_area", "[problem_solving][medium]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  string first_multiple_input_temp;
  getline(cin, first_multiple_input_temp);

  vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

  int H = stoi(first_multiple_input[0]);

  int W = stoi(first_multiple_input[1]);

  vector<vector<int>> A(H);

  for (int i = 0; i < H; i++) {
    A[i].resize(W);

    string A_row_temp_temp;
    getline(cin, A_row_temp_temp);

    vector<string> A_row_temp = split(rtrim(A_row_temp_temp));

    for (int j = 0; j < W; j++) {
      int A_row_item = stoi(A_row_temp[j]);

      A[i][j] = A_row_item;
    }
  }

  int result = surfaceArea(A);

  fout << result << "\n";

  fout.close();
}
