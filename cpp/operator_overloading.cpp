// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/operator-overloading/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 12/05/19.
//
//*****************************************************************

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>

#include <catch2/catch.hpp>

using namespace std;

class Matrix {
 public:
  Matrix() {}
  ~Matrix() {}

  Matrix operator+(const Matrix& right) const {
    Matrix m;

    const int num_rows = a.size();
    assert(num_rows == right.a.size());
    m.a.resize(num_rows);

    const int num_col = a[0].size();

    for (int row_idx = 0; row_idx < num_rows; ++row_idx) {
      assert((num_col == a[row_idx].size()) && (num_col == right.a[row_idx].size()));

      m.a[row_idx].resize(num_col);

      for (int col_idx = 0; col_idx < num_col; ++col_idx) {
        m.a[row_idx][col_idx] = a[row_idx][col_idx] + right.a[row_idx][col_idx];
      }
    }
    return m;
  }

  vector<vector<int>> a;
};

TEST_CASE("operator_overloading", "[cpp][medium]") {
  int cases, k;
  cin >> cases;
  for (k = 0; k < cases; k++) {
    Matrix x;
    Matrix y;
    Matrix result;
    int n, m, i, j;
    cin >> n >> m;
    for (i = 0; i < n; i++) {
      vector<int> b;
      int num;
      for (j = 0; j < m; j++) {
        cin >> num;
        b.push_back(num);
      }
      x.a.push_back(b);
    }
    for (i = 0; i < n; i++) {
      vector<int> b;
      int num;
      for (j = 0; j < m; j++) {
        cin >> num;
        b.push_back(num);
      }
      y.a.push_back(b);
    }
    result = x + y;
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {
        cout << result.a[i][j] << " ";
      }
      cout << endl;
    }
  }
}
