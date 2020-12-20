// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/minimum-time-required/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 27/05/19.
//
//*****************************************************************

#include "utils.h"
#include <bits/stdc++.h>
#include <cassert>
#include <catch2/catch.hpp>
#include <cmath>
#include <iostream>

using namespace std;

// get approximate value
long getInitValue(vector<long>& machines, long goal) {
  double production_compute = 0;
  for (long machine : machines) {
    production_compute += (1 / (double)machine);
  }

  production_compute = (goal / production_compute);
  cout << "== approximate value : " << production_compute << " ==" << endl;

  return floor(production_compute);
}

// Complete the minTime function below.
long minTime(vector<long>& machines, long goal) {
  long cur_production = 0;
  long cur_time = getInitValue(machines, goal);

  // <time, <day, quantity>>
  map<long, unordered_map<long, int>> remaining_days;
  for (long machine : machines) {
    long production = (cur_time / machine);
    cur_production += production;
    long next_time = ((production + 1) * machine);

    auto iter = remaining_days.find(next_time);
    if (iter == remaining_days.end()) {
      unordered_map<long, int> entry;
      entry[machine] = 1;
      remaining_days[next_time] = entry;
    } else {
      auto& cur_entry = iter->second;
      cur_entry[machine]++;
    }
  }

  while (cur_production < goal) {
    auto begining = remaining_days.begin();
    cur_time = begining->first;

    // other machines to done on this day
    auto& cur_machines = begining->second;
    for (auto& entries : cur_machines) {
      // update production
      cur_production += entries.second;

      // next time these machine will be done
      long next_time = (cur_time + entries.first);

      auto next_iter = remaining_days.find(next_time);
      if (next_iter == remaining_days.end()) {
        unordered_map<long, int> entry;
        entry[entries.first] = entries.second;
        remaining_days[next_time] = entry;
      } else {
        auto& cur_entry = next_iter->second;
        assert(cur_entry.find(entries.first) == cur_entry.end());
        cur_entry[entries.first] = entries.second;
      }
    }

    remaining_days.erase(begining);
  }

  return cur_time;
}

TEST_CASE("minimum_time_required", "[interview_prep_kit][search][medium][star]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  string nGoal_temp;
  getline(cin, nGoal_temp);

  vector<string> nGoal = split_string(nGoal_temp);

  int n = stoi(nGoal[0]);

  long goal = stol(nGoal[1]);

  string machines_temp_temp;
  getline(cin, machines_temp_temp);

  vector<string> machines_temp = split_string(machines_temp_temp);

  vector<long> machines(n);

  for (int i = 0; i < n; i++) {
    long machines_item = stol(machines_temp[i]);

    machines[i] = machines_item;
  }

  long ans = minTime(machines, goal);

  fout << ans << "\n";

  fout.close();
}
