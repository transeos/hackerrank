// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/flipping-the-matrix/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 21/03/21.
//
//*****************************************************************

#include "utils.h"
#include <bits/stdc++.h>
#include <catch2/catch.hpp>

using namespace std;

pair<long, long> GetRowSum(const vector<vector<int>>& matrix, const size_t row,
                           const size_t half_len) {
  pair<long, long> output = {0, 0};

  for (size_t idx = 0; idx < half_len; ++idx) {
    output.first += matrix[row][idx];
    output.second += matrix[row][idx + half_len];
  }

  return output;
}

pair<long, long> GetColSum(const vector<vector<int>>& matrix, const size_t col,
                           const size_t half_len) {
  pair<long, long> output = {0, 0};

  for (size_t idx = 0; idx < half_len; ++idx) {
    output.first += matrix[idx][col];
    output.second += matrix[idx + half_len][col];
  }

  return output;
}

void SwapRow(vector<vector<int>>& matrix, const size_t row, const size_t half_len) {
  for (size_t idx = 0; idx < half_len; ++idx) {
    int temp = matrix[row][idx];
    matrix[row][idx] = matrix[row][2 * half_len - idx - 1];
    matrix[row][2 * half_len - idx - 1] = temp;
  }
}

void SwapCol(vector<vector<int>>& matrix, const size_t col, const size_t half_len) {
  for (size_t idx = 0; idx < half_len; ++idx) {
    int temp = matrix[idx][col];
    matrix[idx][col] = matrix[2 * half_len - idx - 1][col];
    matrix[2 * half_len - idx - 1][col] = temp;
  }
}

void PrintMatrix(const vector<vector<int>>& matrix, const size_t matrix_size) {
  for (size_t row_idx = 0; row_idx < matrix_size; ++row_idx) {
    for (size_t col_idx = 0; col_idx < matrix_size; ++col_idx) {
      cout << matrix[row_idx][col_idx] << " ";
    }
    cout << endl;
  }
}

// Complete the flippingMatrix function below.
long flippingMatrix(vector<vector<int>>& matrix) {
  const size_t matrix_size = matrix.size();
  const size_t half_len = (matrix_size / 2);

  bool change = true;

  while (change) {
    change = false;

    for (size_t row_idx = 0; row_idx < matrix_size; ++row_idx) {
      auto sum_pair = GetRowSum(matrix, row_idx, half_len);
      if (sum_pair.first < sum_pair.second) {
        cout << "---- Swap row " << row_idx << " ----" << endl;
        SwapRow(matrix, row_idx, half_len);
        PrintMatrix(matrix, matrix_size);
        change = true;
      }
    }

    for (size_t col_idx = 0; col_idx < matrix_size; ++col_idx) {
      auto sum_pair = GetColSum(matrix, col_idx, half_len);
      if (sum_pair.first < sum_pair.second) {
        cout << "==== Swap col " << col_idx << " ====" << endl;
        SwapCol(matrix, col_idx, half_len);
        PrintMatrix(matrix, matrix_size);
        change = true;
      }
    }
  }

  long quadrant_sum = 0;
  for (size_t row_idx = 0; row_idx < half_len; ++row_idx) {
    for (size_t col_idx = 0; col_idx < half_len; ++col_idx) {
      quadrant_sum += matrix[row_idx][col_idx];
    }
  }

  return quadrant_sum;
}

TEST_CASE("flipping_the_matrix", "[problem_solving][medium][incomplete]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  int q;
  cin >> q;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  for (int q_itr = 0; q_itr < q; q_itr++) {
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> matrix(2 * n);
    for (int i = 0; i < 2 * n; i++) {
      matrix[i].resize(2 * n);

      for (int j = 0; j < 2 * n; j++) {
        cin >> matrix[i][j];
      }

      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    long result = flippingMatrix(matrix);

    fout << result << "\n";
  }

  fout.close();
}
