// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/pairs/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 26/05/19.
//
//*****************************************************************

#include <bits/stdc++.h>
#include <iostream>

#include "utils.h"
#include <catch2/catch.hpp>

using namespace std;

// Complete the pairs function below.
int pairs(int k, const vector<int>& arr) {
  unordered_set<int> target_nums;
  const int max = 2147483647;
  int num_pairs = 0;

  for (int cur_val : arr) {
    target_nums.insert(cur_val);

    if (cur_val > k) {
      const int target_num = (cur_val - k);
      if (target_nums.find(target_num) != target_nums.end()) {
        num_pairs++;
      }
    }

    if (cur_val < (max - k)) {
      const int target_num = (cur_val + k);
      if (target_nums.find(target_num) != target_nums.end()) {
        num_pairs++;
      }
    }
  }

  return num_pairs;
}

TEST_CASE("pairs", "[interview_prep_kit][search][medium]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  string nk_temp;
  getline(cin, nk_temp);

  vector<string> nk = split_string(nk_temp);

  int n = stoi(nk[0]);

  int k = stoi(nk[1]);

  string arr_temp_temp;
  getline(cin, arr_temp_temp);

  vector<string> arr_temp = split_string(arr_temp_temp);

  vector<int> arr(n);

  for (int i = 0; i < n; i++) {
    int arr_item = stoi(arr_temp[i]);

    arr[i] = arr_item;
  }

  int result = pairs(k, arr);

  fout << result << "\n";

  fout.close();
}
