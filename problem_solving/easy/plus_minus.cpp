// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/a-very-big-sum/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 11/06/22.
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
 * Complete the 'plusMinus' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

void plusMinus(const vector<int>& arr) {
  uint64_t positiveCount = 0;
  uint64_t negativeCount = 0;

  for (const int num : arr) {
    if (num > 0) {
      positiveCount++;
    } else if (num < 0) {
      negativeCount++;
    }
  }

  auto printResultFn = [](const uint64_t curCount, const uint64_t totalCount) {
    if (curCount == totalCount) {
      cout << "1.000000" << endl;
      return;
    }

    const uint64_t curCountX1M = curCount * 1000000L;
    const uint64_t curRatioX1M = curCountX1M / totalCount;
    int32_t numZeros = 5;
    int32_t remainder = curRatioX1M;

    while (remainder > 10) {
      numZeros--;
      remainder /= 10;
    }

    cout << "0.";
    for (size_t i = 0; i < numZeros; ++i) {
      cout << "0";
    }

    cout << curRatioX1M << endl;
  };

  printResultFn(positiveCount, arr.size());
  printResultFn(negativeCount, arr.size());
  printResultFn(arr.size() - positiveCount - negativeCount, arr.size());
}

TEST_CASE("plus_minus", "[problem_solving][easy]") {
  string n_temp;
  getline(cin, n_temp);

  int n = stoi(ltrim(rtrim(n_temp)));

  string arr_temp_temp;
  getline(cin, arr_temp_temp);

  vector<string> arr_temp = split(rtrim(arr_temp_temp));

  vector<int> arr(n);

  for (int i = 0; i < n; i++) {
    int arr_item = stoi(arr_temp[i]);

    arr[i] = arr_item;
  }

  plusMinus(arr);
}
