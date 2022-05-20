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

#include "utils.h"
#include <bits/stdc++.h>
#include <catch2/catch.hpp>
#include <iostream>

using namespace std;

void minimumBribes(vector<int>& q) {
  size_t numBribes = 0;

  for (int64_t pos = (q.size() - 1); pos >= 0; --pos) {
    if (q[pos] == (pos + 1)) {
      continue;
    }

    if (q[pos] > (pos + 3)) {
      cout << "Too chaotic" << endl;
      return;
    }

    if ((q[pos - 1] == (pos + 1)) && (pos > 0)) {
      int temp = q[pos];
      q[pos] = q[pos - 1];
      q[pos - 1] = temp;

      pos++;
      numBribes++;
    } else if ((q[pos - 2] == (pos + 1)) && (pos > 1)) {
      q[pos - 2] = q[pos - 1];
      q[pos - 1] = q[pos];
      q[pos] = pos + 1;

      pos = std::min(pos + 2, static_cast<int64_t>(q.size()));
      numBribes += 2;
    }
  }

  cout << numBribes << endl;
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
