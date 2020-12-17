// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/crush/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 25/05/19.
//
//*****************************************************************

#include "utils.h"
#include <bits/stdc++.h>
#include <catch2/catch.hpp>
#include <iostream>

using namespace std;

bool ComparePairFn(const pair<int32_t, int64_t>& lhs, const pair<int32_t, int64_t>& rhs) {
  return ((lhs.first < rhs.first) ? true : ((lhs.first == rhs.first) && (lhs.second < rhs.second)));
}

void printArray(const vector<pair<int32_t, int64_t>>& data) {
  for (int idx = 0; idx < data.size(); ++idx) {
    cout << "{" << data[idx].first << "," << data[idx].second << "}" << endl;
  }
}

// Complete the arrayManipulation function below.
long arrayManipulation(int n, const vector<vector<int>>& queries) {
  vector<pair<int32_t, int64_t>> data;

  int arr_size = queries.size();
  for (size_t query_idx = 0; query_idx < arr_size; ++query_idx) {
    const int32_t increment = queries[query_idx][2];
    data.push_back({(queries[query_idx][0] - 1), increment});
    data.push_back({queries[query_idx][1], ((-1) * increment)});
  }

  sort(data.begin(), data.end(), ComparePairFn);
  // printArray(data);

  size_t cur_data_idx = 0;
  int64_t max_val = 0;
  int64_t cur_val = 0;

  arr_size = data.size();
  for (size_t idx = 0; idx < arr_size; ++idx) {
    cur_val += data[idx].second;
    max_val = ((cur_val > max_val) ? cur_val : max_val);
  }

  return max_val;
}

TEST_CASE("array_manipulation", "[interview_prep_kit][array][hard]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  string nm_temp;
  getline(cin, nm_temp);

  vector<string> nm = split_string(nm_temp);

  int n = stoi(nm[0]);

  int m = stoi(nm[1]);

  vector<vector<int>> queries(m);
  for (int i = 0; i < m; i++) {
    queries[i].resize(3);

    for (int j = 0; j < 3; j++) {
      cin >> queries[i][j];
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }

  long result = arrayManipulation(n, queries);

  fout << result << "\n";

  fout.close();
}
