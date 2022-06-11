// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/flatland-space-stations/problem
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

// Complete the flatlandSpaceStations function below.
int32_t flatlandSpaceStations(const int32_t n, vector<int>& c) {
  std::sort(c.begin(), c.end());

  int32_t maxDistance = c[0];

  for (size_t i = 1; i < c.size(); ++i) {
    maxDistance = std::max(maxDistance, (c[i] - c[i - 1]) / 2);
  }

  maxDistance = std::max(maxDistance, (n - c.back() - 1));

  return maxDistance;
}

TEST_CASE("flatland_space_stations", "[problem_solving][easy]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  string nm_temp;
  getline(cin, nm_temp);

  vector<string> nm = split_string(nm_temp);

  int n = stoi(nm[0]);

  int m = stoi(nm[1]);

  string c_temp_temp;
  getline(cin, c_temp_temp);

  vector<string> c_temp = split_string(c_temp_temp);

  vector<int> c(m);

  for (int i = 0; i < m; i++) {
    int c_item = stoi(c_temp[i]);

    c[i] = c_item;
  }

  int result = flatlandSpaceStations(n, c);

  fout << result << "\n";

  fout.close();
}
