// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/angry-children/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 02/01/21.
//
//*****************************************************************

#include "utils.h"
#include <bits/stdc++.h>
#include <catch2/catch.hpp>
#include <iostream>

using namespace std;

// Complete the maxMin function below.
int maxMin(const int k, vector<int>& arr) {
  sort(arr.begin(), arr.end());

  int max_min = numeric_limits<int>::max();

  for (size_t idx = 0; idx < (arr.size() - k + 1); ++idx) {
    max_min = std::min((arr[idx + k - 1] - arr[idx]), max_min);
  }

  return max_min;
}

TEST_CASE("angry_children", "[interview_prep_kit][greedy][medium]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  int n;
  cin >> n;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  int k;
  cin >> k;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  vector<int> arr(n);

  for (int i = 0; i < n; i++) {
    int arr_item;
    cin >> arr_item;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    arr[i] = arr_item;
  }

  int result = maxMin(k, arr);

  fout << result << "\n";

  fout.close();
}
