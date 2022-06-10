// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/almost-sorted/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 26/05/22.
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
 * Complete the 'almostSorted' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

void almostSorted(vector<int>& arr) {
  size_t incorrectValStart = arr.size();

  for (size_t i = 0; i < arr.size() - 1; ++i) {
    if (arr[i] <= arr[i + 1]) {
      continue;
    }

    incorrectValStart = i;

    int minValIndex = i + 1;
    for (size_t j = i + 2; j < arr.size(); ++j) {
      if (arr[j] < arr[minValIndex]) {
        minValIndex = j;
      }
    }

    if ((i > 0) && (arr[minValIndex] < arr[i - 1])) {
      break;
    }

    // swap once
    std::swap(arr[i], arr[minValIndex]);
    if (std::is_sorted(arr.begin() + i, arr.end())) {
      cout << "yes\nswap " << i + 1 << " " << minValIndex + 1 << endl;
      return;
    } else {
      // undo swap
      std::swap(arr[i], arr[minValIndex]);
      break;
    }
  }

  if (incorrectValStart == arr.size()) {
    // already sorted
    cout << "yes" << endl;
    return;
  }

  const int minVal = (incorrectValStart == 0) ? -1 : arr[incorrectValStart - 1];

  for (size_t i = incorrectValStart + 1; i < arr.size(); ++i) {
    if (arr[i] < minVal) {
      cout << "no" << endl;
      return;
    }

    if (arr[i] <= arr[i - 1]) {
      continue;
    }

    if (arr[i] < arr[incorrectValStart]) {
      cout << "no" << endl;
      return;
    }

    if (std::is_sorted(arr.begin() + i, arr.end())) {
      cout << "yes\nreverse " << incorrectValStart + 1 << " " << i << endl;
      return;
    } else {
      break;
    }
  }

  cout << "no" << endl;
}

TEST_CASE("almost_sorted", "[problem_solving][medium]") {
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

  almostSorted(arr);
}
