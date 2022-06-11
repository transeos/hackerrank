// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/beautiful-pairs/problem
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
 * Complete the 'beautifulPairs' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY A
 *  2. INTEGER_ARRAY B
 */

int32_t beautifulPairs(const vector<int>& A, const vector<int>& B) {
  auto addNum = [](std::unordered_map<int32_t, int32_t>& numMap, const vector<int>& arr) {
    for (const int num : arr) {
      auto it = numMap.find(num);
      if (it != numMap.end()) {
        it->second++;
      } else {
        numMap[num] = 1;
      }
    }
  };

  std::unordered_map<int32_t, int32_t> numsInA;
  std::unordered_map<int32_t, int32_t> numsInB;

  addNum(numsInA, A);
  addNum(numsInB, B);

  int32_t numDisjointPairs = 0;

  for (auto itB : numsInB) {
    auto itA = numsInA.find(itB.first);
    if (itA != numsInA.end()) {
      numDisjointPairs += std::min(itA->second, itB.second);
    }
  }

  if (numDisjointPairs == A.size()) {
    return numDisjointPairs - 1;
  } else {
    return numDisjointPairs + 1;
  }
}

TEST_CASE("beautiful_pairs", "[problem_solving][easy]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  string n_temp;
  getline(cin, n_temp);

  int n = stoi(ltrim(rtrim(n_temp)));

  string A_temp_temp;
  getline(cin, A_temp_temp);

  vector<string> A_temp = split(rtrim(A_temp_temp));

  vector<int> A(n);

  for (int i = 0; i < n; i++) {
    int A_item = stoi(A_temp[i]);

    A[i] = A_item;
  }

  string B_temp_temp;
  getline(cin, B_temp_temp);

  vector<string> B_temp = split(rtrim(B_temp_temp));

  vector<int> B(n);

  for (int i = 0; i < n; i++) {
    int B_item = stoi(B_temp[i]);

    B[i] = B_item;
  }

  int result = beautifulPairs(A, B);

  fout << result << "\n";

  fout.close();
}
