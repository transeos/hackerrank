// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/larrys-array/problem
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

string larrysArray(vector<int>& A) {
  if (A.size() < 3) {
    return "YES";
  }

  for (size_t i = 0; i < A.size() - 2; ++i) {
    if (A[i] == i + 1) {
      continue;
    }

    size_t currentPos = A.size();
    for (size_t j = i + 1; j < A.size(); ++j) {
      if (A[j] == i + 1) {
        currentPos = j;
        break;
      }
    }
    assert(currentPos < A.size());

    // start swaps
    while (currentPos != i) {
      if (currentPos >= (i + 2)) {
        // ABC -> CAB allowed
        // ABC -> CBA -> CAB
        std::swap(A[currentPos], A[currentPos - 2]);
        std::swap(A[currentPos], A[currentPos - 1]);
        currentPos -= 2;
      } else if (currentPos == i + 1) {
        // ABC -> BCA allowed
        // ABC -> BAC -> BCA
        std::swap(A[currentPos], A[currentPos - 1]);
        std::swap(A[currentPos], A[currentPos + 1]);
        currentPos--;
      }
    }
  }

  if (A.back() != A.size()) {
    return "NO";
  } else {
    return "YES";
  }
}

TEST_CASE("larrys_array", "[problem_solving][medium]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  string t_temp;
  getline(cin, t_temp);

  int t = stoi(ltrim(rtrim(t_temp)));

  for (int t_itr = 0; t_itr < t; t_itr++) {
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

    string result = larrysArray(A);

    fout << result << "\n";
  }

  fout.close();
}
