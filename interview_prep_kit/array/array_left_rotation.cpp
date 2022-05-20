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
vector<int> rotLeft(const vector<int>& a, int d) {
  vector<int> rotArr(a.size());

  std::copy(a.begin(), a.begin() + d, rotArr.begin() + (a.size() - d));
  std::copy(a.begin() + d, a.end(), rotArr.begin());

  return rotArr;
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
