// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/new-year-chaos/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 25/05/19.
//
//*****************************************************************

#include <bits/stdc++.h>
#include <iostream>
#include <tuple>

#include "utils.h"
#include <catch2/catch.hpp>

using namespace std;

bool CompareTupleFn(const tuple<int, long>& lhs, const tuple<int, long>& rhs) {
  return (get<0>(lhs) < get<0>(rhs));
}

void printArray(const vector<tuple<int, long>>& data, const int n) {
  for (int idx = 0; idx < data.size(); ++idx) {
    const int end_idx = ((idx == (data.size() - 1)) ? n : get<0>(data[idx + 1]));
    for (int j = get<0>(data[idx]); j < end_idx; ++j) {
      cout << get<1>(data[idx]) << " ";
    }
  }
  cout << endl;
}

// Complete the arrayManipulation function below.
long arrayManipulation(int n, const vector<vector<int>>& queries) {
  vector<tuple<int, long>> data;

  const int num_queries = queries.size();
  for (int query_idx = 0; query_idx < num_queries; ++query_idx) {
    const int start_idx = (queries[query_idx][0] - 1);
    const int end_idx = queries[query_idx][1];
    const int increment = queries[query_idx][2];
    assert((start_idx >= 0) && (start_idx < end_idx) && (end_idx <= n) && (increment >= 0));

    const int num_data = data.size();
    if (num_data == 0) {
      if (start_idx == 0) {
        data.push_back({0, increment});
      } else {
        data.push_back({0, 0});
        data.push_back({start_idx, increment});
      }

      if (end_idx < n) {
        data.push_back({end_idx, 0});
      }
      continue;
    }

    tuple<int, long> start_tp = {start_idx, 0};
    auto iter1 = lower_bound(data.begin(), data.end(), start_tp, CompareTupleFn);
    if (iter1 == data.end()) {
      data.push_back({start_idx, increment});
      if (end_idx < n) {
        data.push_back({end_idx, get<1>(data[num_data - 1])});
      }
      continue;
    }

    const int update_start = (iter1 - data.begin());

    tuple<int, long> end_tp = {end_idx, 0};
    auto iter2 = lower_bound(data.begin(), data.end(), end_tp, CompareTupleFn);
    int update_end = num_data;
    if (iter2 != data.end()) {
      update_end = (iter2 - data.begin());
    }

    if (start_idx != get<0>(data[update_start])) {
      data.push_back({start_idx, (get<1>(data[update_start - 1]) + increment)});
    }

    if (update_end < num_data) {
      if (end_idx != get<0>(data[update_end])) {
        data.push_back({end_idx, (get<1>(data[update_end - 1]) + increment)});
      }
    } else if (end_idx < n) {
      data.push_back({end_idx, get<1>(data[num_data - 1])});
    }

    for (int iter_idx = update_start; iter_idx < update_end; ++iter_idx) {
      data[iter_idx] = {get<0>(data[iter_idx]), (get<1>(data[iter_idx]) + increment)};
    }

    sort(data.begin(), data.end(), CompareTupleFn);
  }

  // printArray(data, n);

  long max_val = 0;
  const int num_data = data.size();
  for (int idx = 0; idx < data.size(); ++idx) {
    if (max_val < get<1>(data[idx])) {
      max_val = get<1>(data[idx]);
    }
  }
  return max_val;
}

TEST_CASE("array_manipulation", "[interview_prep_kit][array][hard][incomplete]") {
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
