// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/poisonous-plants/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 27/12/19.
//
//*****************************************************************

#include "utils.h"
#include <bits/stdc++.h>
#include <catch2/catch.hpp>
#include <iostream>

//#define DEBUG_POISONOUS_PLANTS

using namespace std;

int CheckForPesticide(stack<pair<int, int>>& left_plants, const int cur_pesticide) {
  int prev_days = -1;

  while (!left_plants.empty()) {
    const pair<int, int>& prev_plant = left_plants.top();
    if (prev_plant.first == cur_pesticide) {
      // no need to keep identical plant

      if (prev_plant.second == -1) {
#ifdef DEBUG_POISONOUS_PLANTS
        cout << cur_pesticide << "= -1" << endl;
#endif
        return -1;
      }

      prev_days = std::max(prev_days, (prev_plant.second + 1));

      left_plants.pop();
      left_plants.emplace(cur_pesticide, prev_days);

#ifdef DEBUG_POISONOUS_PLANTS
      cout << cur_pesticide << ": " << prev_days << endl;
#endif
      return prev_days;
    }

    if (prev_plant.first < cur_pesticide) {
      // this plant will die
      prev_days = ((prev_days == -1) ? 0 : prev_days);
      left_plants.emplace(cur_pesticide, prev_days);

#ifdef DEBUG_POISONOUS_PLANTS
      cout << cur_pesticide << ": " << prev_days << endl;
#endif
      return prev_days;
    }

    prev_days = std::max(prev_days, (prev_plant.second + 1));

    left_plants.pop();
  }

  // this plant will not die
  left_plants.emplace(cur_pesticide, -1);

#ifdef DEBUG_POISONOUS_PLANTS
  cout << cur_pesticide << ": -1" << endl;
#endif
  return -1;
}

// Complete the poisonousPlants function below.
int poisonousPlants(const vector<int>& p) {
  // pesticide on plant, day of death
  stack<pair<int, int>> left_plants;

  int max_day = -1;

  for (size_t idx = 0; idx < p.size(); ++idx) {
    const int num_days = CheckForPesticide(left_plants, p[idx]);
    max_day = std::max(max_day, num_days);
  }

  return (max_day + 1);
}

TEST_CASE("poisonous_plants", "[interview_prep_kit][stacks_queues][hard][star]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  int n;
  cin >> n;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  string p_temp_temp;
  getline(cin, p_temp_temp);

  vector<string> p_temp = split_string(p_temp_temp);

  vector<int> p(n);

  for (int i = 0; i < n; i++) {
    int p_item = stoi(p_temp[i]);

    p[i] = p_item;
  }

  int result = poisonousPlants(p);

  fout << result << "\n";

  fout.close();
}
