// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/ctci-array-left-rotation/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 12/05/19.
//
//*****************************************************************

#include "utils.h"
#include <bits/stdc++.h>
#include <cassert>
#include <catch2/catch.hpp>
#include <iostream>

using namespace std;

// Complete the rotLeft function below.
vector<int> rotLeft(const vector<int>& orig_arr, int d) {
  if (d == 0) return orig_arr;

  const int num = orig_arr.size();
  assert(d < num);

  vector<int> new_arr(num);

  for (size_t idx = 0; idx < (num - d); ++idx) {
    new_arr[idx] = orig_arr[idx + d];
  }

  for (size_t idx = (num - d); idx < num; ++idx) {
    new_arr[idx] = orig_arr[idx + d - num];
  }

  return new_arr;
}

TEST_CASE("array_left_rotation", "[interview_prep_kit][array][easy]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  string nd_temp;
  getline(cin, nd_temp);

  vector<string> nd = split_string(nd_temp);

  int n = stoi(nd[0]);

  int d = stoi(nd[1]);

  string a_temp_temp;
  getline(cin, a_temp_temp);

  vector<string> a_temp = split_string(a_temp_temp);

  vector<int> a(n);

  for (int i = 0; i < n; i++) {
    int a_item = stoi(a_temp[i]);

    a[i] = a_item;
  }

  vector<int> result = rotLeft(a, d);

  for (int i = 0; i < result.size(); i++) {
    fout << result[i];

    if (i != result.size() - 1) {
      fout << " ";
    }
  }

  fout << "\n";

  fout.close();
}
