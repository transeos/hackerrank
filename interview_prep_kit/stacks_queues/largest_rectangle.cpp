// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/balanced-brackets/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 23/12/19.
//
//*****************************************************************

#include "utils.h"
#include <bits/stdc++.h>
#include <catch2/catch.hpp>
#include <iostream>

using namespace std;

int64_t ClearStack(stack<pair<int, int>>& buildings, int& init_idx, const int cur_height,
                   const int cur_idx) {
  int64_t max_area = 0;

  while (!buildings.empty() && (buildings.top().first > cur_height)) {
    const pair<int, int>& building = buildings.top();

    int64_t cur_max_area = (building.first * (cur_idx - building.second));
    max_area = ((cur_max_area > max_area) ? cur_max_area : max_area);

    init_idx = building.second;

    buildings.pop();
  }

  return max_area;
}

// Complete the largest Rectangle function below.
int64_t largestRectangle(const vector<int>& h) {
  int64_t max_area = 0;

  // height, position
  stack<pair<int, int>> buildings;

  for (int idx = 0; idx < h.size(); ++idx) {
    const int cur_height = h[idx];
    if (buildings.empty()) {
      buildings.emplace(make_pair(cur_height, idx));
      continue;
    }

    if (buildings.top().first == cur_height) {
      continue;
    }

    if (buildings.top().first < cur_height) {
      buildings.emplace(make_pair(cur_height, idx));
      continue;
    }

    int init_idx = idx;

    int64_t max_area_from_stack = ClearStack(buildings, init_idx, cur_height, idx);
    max_area = ((max_area_from_stack > max_area) ? max_area_from_stack : max_area);

    buildings.emplace(make_pair(cur_height, init_idx));
  }

  int init_idx = (h.size() - 1);

  int64_t max_area_from_stack = ClearStack(buildings, init_idx, 0, h.size());
  max_area = ((max_area_from_stack > max_area) ? max_area_from_stack : max_area);

  return max_area;
}

TEST_CASE("largest_rectangle", "[interview_prep_kit][stacks_queues][medium][star]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  int n;
  cin >> n;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  string h_temp_temp;
  getline(cin, h_temp_temp);

  vector<string> h_temp = split_string(h_temp_temp);

  vector<int> h(n);

  for (int i = 0; i < n; i++) {
    int h_item = stoi(h_temp[i]);

    h[i] = h_item;
  }

  int64_t result = largestRectangle(h);

  fout << result << "\n";

  fout.close();
}
