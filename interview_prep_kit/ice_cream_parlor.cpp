// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/ctci-ice-cream-parlor/problem
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

// Complete the whatFlavors function below.
void whatFlavors(const vector<int>& cost, int money) {
  const int num_flavors = cost.size();
  unordered_map<int, int> visited_flavors;

  for (int idx = 0; idx < num_flavors; ++idx) {
    const int cur_flavor = cost[idx];
    const int complementory_flavor = (money - cur_flavor);

    auto iter = visited_flavors.find(complementory_flavor);
    if (iter != visited_flavors.end()) {
      cout << (iter->second + 1) << " " << (idx + 1) << endl;
      return;
    }

    visited_flavors[cur_flavor] = idx;
  }
}

TEST_CASE("ice_cream_parlor", "[interview_prep_kit][search][medium]") {
  int t;
  cin >> t;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  for (int t_itr = 0; t_itr < t; t_itr++) {
    int money;
    cin >> money;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string cost_temp_temp;
    getline(cin, cost_temp_temp);

    vector<string> cost_temp = split_string(cost_temp_temp);

    vector<int> cost(n);

    for (int i = 0; i < n; i++) {
      int cost_item = stoi(cost_temp[i]);

      cost[i] = cost_item;
    }

    whatFlavors(cost, money);
  }
}
