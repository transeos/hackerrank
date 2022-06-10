// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/absolute-permutation/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 25/05/22.
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
 * Complete the 'absolutePermutation' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER k
 */

vector<int> absolutePermutation(const int32_t n, const int32_t k) {
  vector<int> result(1, -1);

  if (k == 0) {
    result.resize(n);
    for (int32_t i = 0; i < n; ++i) {
      result[i] = i + 1;
    }
    return result;
  }

  vector<std::set<int32_t>> data(n);

  for (int32_t i = 1; i <= n; ++i) {
    const int32_t index1 = i - k;
    if (index1 > 0) {
      data[index1 - 1].insert(i);
    }

    const int32_t index2 = i + k;
    if (index2 <= n) {
      data[index2 - 1].insert(i);
    }
  }

  for (const auto& positions : data) {
    if (positions.empty()) {
      return result;
    }
  }

  result.resize(n);

  for (int32_t i = 0; i < n; ++i) {
    auto& positions = data[i];

    bool validNumber = false;
    while (!validNumber) {
      const int32_t curNum = *positions.begin();

      const int32_t index1 = curNum - k;
      const int32_t index2 = curNum + k;
      if (index1 == i + 1 && index2 <= n) {
        if (data[index2 - 1].size() == 1) {
          positions.erase(curNum);
          if (positions.empty()) {
            result = {-1};
            return result;
          }
        } else {
          data[index2 - 1].erase(curNum);
          if (data[index2 - 1].empty()) {
            result = {-1};
            return result;
          }

          validNumber = true;
        }
      } else {
        validNumber = true;
      }
    }

    result[i] = *positions.begin();
  }

  return result;
}

TEST_CASE("absolute_permutation", "[problem_solving][medium]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  string t_temp;
  getline(cin, t_temp);

  int t = stoi(ltrim(rtrim(t_temp)));

  for (int t_itr = 0; t_itr < t; t_itr++) {
    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    vector<int> result = absolutePermutation(n, k);

    for (size_t i = 0; i < result.size(); i++) {
      fout << result[i];

      if (i != result.size() - 1) {
        fout << " ";
      }
    }

    fout << "\n";
  }

  fout.close();
}
