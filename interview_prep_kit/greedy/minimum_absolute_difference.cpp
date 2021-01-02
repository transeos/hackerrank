// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/minimum-absolute-difference-in-an-array/problem
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

// Complete the minimumAbsoluteDifference function below.
int minimumAbsoluteDifference(vector<int>& arr) {
  // check for identical element
  unordered_set<int> elements;
  for (int num : arr) {
    auto iter = elements.find(num);
    if (iter == elements.end()) {
      elements.insert(num);
    } else {
      return 0;
    }
  }
  elements.clear();

  sort(arr.begin(), arr.end());

  int min_diff = (arr.back() - arr.front());
  for (size_t idx = 1; idx < arr.size(); ++idx) {
    min_diff = std::min(abs(arr[idx] - arr[idx - 1]), min_diff);
  }

  return min_diff;
}

TEST_CASE("minimum_absolute_difference", "[interview_prep_kit][greedy][easy]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  int n;
  cin >> n;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  string arr_temp_temp;
  getline(cin, arr_temp_temp);

  vector<string> arr_temp = split_string(arr_temp_temp);

  vector<int> arr(n);

  for (int i = 0; i < n; i++) {
    int arr_item = stoi(arr_temp[i]);

    arr[i] = arr_item;
  }

  int result = minimumAbsoluteDifference(arr);

  fout << result << "\n";

  fout.close();
}
