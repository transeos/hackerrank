// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/variable-sized-arrays/problem
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

TEST_CASE("variable_sized_arrays", "[cpp][easy]") {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */

  vector<vector<int>> data;

  int num_arrs = 0, num_queries = 0;
  cin >> num_arrs >> num_queries;

  data.resize(num_arrs);

  // population of arrays
  for (int arr_idx = 0; arr_idx < num_arrs; ++arr_idx) {
    int arr_size = 0;
    cin >> arr_size;

    data[arr_idx].resize(arr_size);

    for (int idx = 0; idx < arr_size; ++idx) {
      cin >> data[arr_idx][idx];
    }
  }

  // handle queries
  for (int query_idx = 0; query_idx < num_queries; ++query_idx) {
    int row = 0, col = 0;
    cin >> row >> col;
    cout << data[row][col] << endl;
  }
}
