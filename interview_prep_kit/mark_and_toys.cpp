// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/mark-and-toys/problem
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

// Complete the maximumToys function below.
int maximumToys(vector<int>& prices, int k) {
  sort(prices.begin(), prices.end());

  int budget_left = k;

  const int num_toys = prices.size();
  for (int idx = 0; idx < num_toys; ++idx) {
    budget_left -= prices[idx];
    if (budget_left < 0) {
      return idx;
    }
  }

  return num_toys;
}

TEST_CASE("mark_and_toys", "[interview_prep_kit][sorting][easy]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  string nk_temp;
  getline(cin, nk_temp);

  vector<string> nk = split_string(nk_temp);

  int n = stoi(nk[0]);

  int k = stoi(nk[1]);

  string prices_temp_temp;
  getline(cin, prices_temp_temp);

  vector<string> prices_temp = split_string(prices_temp_temp);

  vector<int> prices(n);

  for (int i = 0; i < n; i++) {
    int prices_item = stoi(prices_temp[i]);

    prices[i] = prices_item;
  }

  int result = maximumToys(prices, k);

  fout << result << "\n";

  fout.close();
}
