// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/greedy-florist/problem
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

// Complete the getMinimumCost function below.
int getMinimumCost(const int k, vector<int>& flowers) {
  int min_cost = 0;

  if (k >= flowers.size()) {
    // a customer buys only 1 flower
    for (int cost : flowers) {
      min_cost += cost;
    }

    return min_cost;
  }

  sort(flowers.begin(), flowers.end(), greater<int>());

  int flowers_each_customer = 0;

  for (size_t idx = 0; idx < flowers.size(); ++idx) {
    min_cost += ((1 + flowers_each_customer) * flowers[idx]);

    if (((idx + 1) % k) == 0) {
      flowers_each_customer++;
    }
  }

  return min_cost;
}

TEST_CASE("greedy_florist", "[interview_prep_kit][greedy][medium]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  string nk_temp;
  getline(cin, nk_temp);

  vector<string> nk = split_string(nk_temp);

  int n = stoi(nk[0]);

  int k = stoi(nk[1]);

  string c_temp_temp;
  getline(cin, c_temp_temp);

  vector<string> c_temp = split_string(c_temp_temp);

  vector<int> c(n);

  for (int i = 0; i < n; i++) {
    int c_item = stoi(c_temp[i]);

    c[i] = c_item;
  }

  int minimumCost = getMinimumCost(k, c);

  fout << minimumCost << "\n";

  fout.close();
}
