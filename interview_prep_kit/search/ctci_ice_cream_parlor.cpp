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

#include "utils.h"
#include <bits/stdc++.h>
#include <catch2/catch.hpp>
#include <iostream>

using namespace std;

// Complete the whatFlavors function below.
void whatFlavors(const vector<int>& cost, const int money) {
  std::unordered_map<int, size_t> costMap;

  for (size_t i = 0; i < cost.size(); ++i) {
    if (auto it = costMap.find(money - cost[i]); it != costMap.end()) {
      cout << (it->second + 1) << " " << (i + 1) << endl;
      return;
    }

    costMap[cost[i]] = i;
  }
}

TEST_CASE("ctci_ice_cream_parlor", "[interview_prep_kit][search][medium]") {
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
