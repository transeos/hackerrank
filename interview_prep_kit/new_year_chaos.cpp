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

#include "utils.h"
#include <catch2/catch.hpp>

using namespace std;

int fixPosition(vector<int>& q, int pos) {
  const int cur_val = q[pos];
  assert(cur_val != (pos + 1));

  if (cur_val == (pos + 2)) {
    int ret_val = 0;

    while (cur_val < q[pos + 1]) {
      const int cur_ret_val = fixPosition(q, (pos + 1));
      if (cur_ret_val < 0) return -1;
      ret_val += cur_ret_val;
    }

    q[pos] = q[pos + 1];
    q[pos + 1] = cur_val;
    return (ret_val + 1);
  }

  if (cur_val == (pos + 3)) {
    int ret_val = 0;

    while (cur_val < q[pos + 2]) {
      const int cur_ret_val = fixPosition(q, (pos + 2));
      if (cur_ret_val < 0) return -1;
      ret_val += cur_ret_val;
    }

    while (cur_val < q[pos + 1]) {
      const int cur_ret_val = fixPosition(q, (pos + 1));
      if (cur_ret_val < 0) return -1;
      ret_val += cur_ret_val;
    }

    q[pos] = q[pos + 1];
    q[pos + 1] = q[pos + 2];
    q[pos + 2] = cur_val;
    ret_val += 2;
    return ret_val;
  }

  return -1;
}

// Complete the minimumBribes function below.
void minimumBribes(vector<int> q) {
  int swaps = 0;
  int num_persons = q.size();

  for (int idx = 0; idx < num_persons; ++idx) {
    const int cur_val = q[idx];
    if (cur_val == (idx + 1)) continue;

    if (swaps > (2 * num_persons)) {
      cout << "Too chaotic\n";
      return;
    }

    int cur_swaps = fixPosition(q, idx);
    if (cur_swaps < 0) {
      cout << "Too chaotic\n";
      return;
    }
    swaps += cur_swaps;
    idx--;
  }

  cout << swaps << endl;
}

TEST_CASE("new_year_chaos", "[interview_prep_kit][array][medium]") {
  int t;
  cin >> t;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  for (int t_itr = 0; t_itr < t; t_itr++) {
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string q_temp_temp;
    getline(cin, q_temp_temp);

    vector<string> q_temp = split_string(q_temp_temp);

    vector<int> q(n);

    for (int i = 0; i < n; i++) {
      int q_item = stoi(q_temp[i]);

      q[i] = q_item;
    }

    minimumBribes(q);
  }
}
