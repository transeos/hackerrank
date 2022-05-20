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

#include "utils.h"
#include <bits/stdc++.h>
#include <catch2/catch.hpp>
#include <iostream>

using namespace std;

// Complete the pairs function below.
int32_t pairs(const int32_t k, const vector<int>& arr) {
  std::unordered_set<int32_t> numbers;

  int32_t numPairs = 0;

  for_each(arr.begin(), arr.end(), [k, &numPairs, &numbers](int num) {
    if (numbers.find(num + k) != numbers.end()) {
      numPairs++;
    }

    if (k <= num && numbers.find(num - k) != numbers.end()) {
      numPairs++;
    }

    numbers.insert(num);
  });

  return numPairs;
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
