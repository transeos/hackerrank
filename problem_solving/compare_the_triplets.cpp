// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/compare-the-triplets/problem
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

vector<int> compareTriplets(const vector<int>& a, const vector<int>& b) {
  vector<int> result(2, 0);

  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] > b[i]) {
      result[0]++;
    } else if (a[i] < b[i]) {
      result[1]++;
    }
  }

  return result;
}

TEST_CASE("compare_the_triplets", "[problem_solving][easy]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  string a_temp_temp;
  getline(cin, a_temp_temp);

  vector<string> a_temp = split(rtrim(a_temp_temp));

  vector<int> a(3);

  for (int i = 0; i < 3; i++) {
    int a_item = stoi(a_temp[i]);

    a[i] = a_item;
  }

  string b_temp_temp;
  getline(cin, b_temp_temp);

  vector<string> b_temp = split(rtrim(b_temp_temp));

  vector<int> b(3);

  for (int i = 0; i < 3; i++) {
    int b_item = stoi(b_temp[i]);

    b[i] = b_item;
  }

  vector<int> result = compareTriplets(a, b);

  for (size_t i = 0; i < result.size(); i++) {
    fout << result[i];

    if (i != result.size() - 1) {
      fout << " ";
    }
  }

  fout << "\n";

  fout.close();
}
