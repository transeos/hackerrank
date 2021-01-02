// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/luck-balance/problem
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

// Complete the luckBalance function below.
int luckBalance(const int k, const vector<vector<int>>& contests) {
  int luck = 0;

  vector<int> imp_contests;

  for (auto& item : contests) {
    if (item[1] == 0) {
      // lose unimportant contests
      luck += item[0];
    } else {
      imp_contests.push_back(item[0]);
    }
  }

  if (imp_contests.size() <= k) {
    // lose all constest
    for (int consest_luck : imp_contests) {
      luck += consest_luck;
    }

    return luck;
  }

  sort(imp_contests.begin(), imp_contests.end());

  for (size_t idx = 0; idx < (imp_contests.size() - k); ++idx) {
    luck -= imp_contests[idx];
  }

  for (size_t idx = (imp_contests.size() - k); idx < imp_contests.size(); ++idx) {
    luck += imp_contests[idx];
  }

  return luck;
}

TEST_CASE("luck_balance", "[interview_prep_kit][greedy][easy]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  string nk_temp;
  getline(cin, nk_temp);

  vector<string> nk = split_string(nk_temp);

  int n = stoi(nk[0]);

  int k = stoi(nk[1]);

  vector<vector<int>> contests(n);
  for (int i = 0; i < n; i++) {
    contests[i].resize(2);

    for (int j = 0; j < 2; j++) {
      cin >> contests[i][j];
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }

  int result = luckBalance(k, contests);

  fout << result << "\n";

  fout.close();
}
