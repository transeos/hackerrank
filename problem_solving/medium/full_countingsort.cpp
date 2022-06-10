// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/countingsort4/problem
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
 * Complete the 'countSort' function below.
 *
 * The function accepts 2D_STRING_ARRAY arr as parameter.
 */
void countSort(const vector<vector<string>>& arr) {
  std::array<vector<string>, 100> allData;

  for (size_t i = 0; i < arr.size(); ++i) {
    const int32_t key = std::stoi(arr[i][0]);
    if (i < arr.size() / 2) {
      allData[key].push_back("-");
    } else {
      allData[key].push_back(arr[i][1]);
    }
  }

  for (const vector<string>& data : allData) {
    for (const string& str : data) {
      cout << str << " ";
    }
  }
}

TEST_CASE("full_countingsort", "[problem_solving][medium]") {
  string n_temp;
  getline(cin, n_temp);

  int n = stoi(ltrim(rtrim(n_temp)));

  vector<vector<string>> arr(n);

  for (int i = 0; i < n; i++) {
    arr[i].resize(2);

    string arr_row_temp_temp;
    getline(cin, arr_row_temp_temp);

    vector<string> arr_row_temp = split(rtrim(arr_row_temp_temp));

    for (int j = 0; j < 2; j++) {
      string arr_row_item = arr_row_temp[j];

      arr[i][j] = arr_row_item;
    }
  }

  countSort(arr);
}
