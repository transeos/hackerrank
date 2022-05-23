// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/pylons/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 23/05/22.
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
 * Complete the 'pylons' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY arr
 */

int32_t pylons(const int32_t k, const vector<int>& arr) {
  int32_t count = 0;

  int32_t distanceFromPrevPlant = 0;
  int32_t prevCityWherePlantPossible = -1;

  for (int32_t i = 0; i < arr.size(); ++i) {
    if (arr[i] == 1) {
      prevCityWherePlantPossible = i;
    }

    distanceFromPrevPlant++;

    if (distanceFromPrevPlant == k) {
      // build plant

      if (prevCityWherePlantPossible == -1) {
        return -1;
      }

      count++;
      distanceFromPrevPlant = i - prevCityWherePlantPossible - k + 1;
      prevCityWherePlantPossible = -1;
    }
  }

  if (distanceFromPrevPlant > 0) {
    if ((arr.size() - prevCityWherePlantPossible - 1) >= k) {
      return -1;
    } else {
      count++;
    }
  }

  return count;
}

TEST_CASE("goodland_electricity", "[problem_solving][medium]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  string first_multiple_input_temp;
  getline(cin, first_multiple_input_temp);

  vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

  int n = stoi(first_multiple_input[0]);

  int k = stoi(first_multiple_input[1]);

  string arr_temp_temp;
  getline(cin, arr_temp_temp);

  vector<string> arr_temp = split(rtrim(arr_temp_temp));

  vector<int> arr(n);

  for (int i = 0; i < n; i++) {
    int arr_item = stoi(arr_temp[i]);

    arr[i] = arr_item;
  }

  int result = pylons(k, arr);

  fout << result << "\n";

  fout.close();
}
