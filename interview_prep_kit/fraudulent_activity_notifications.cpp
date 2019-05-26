// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/fraudulent-activity-notifications/problem
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

// Complete the activityNotifications function below.
int activityNotifications(vector<int> expenditure, int d) {
  deque<int> trailing_expenses;
  for (int idx = 0; idx < d; ++idx) {
    trailing_expenses.push_back(expenditure[idx]);
  }

  int num_notifications = 0;

  const int num_days = expenditure.size();
  for (int idx = d; idx < num_days; ++idx) {
    /*
    for (int jdx = 0; jdx < d; ++jdx) {
      cout << trailing_expenses[jdx] << " ";
    }
    cout << endl;*/

    deque<int> sorted_expenses = trailing_expenses;
    sort(sorted_expenses.begin(), sorted_expenses.end());

    const int medianx2 = (d % 2) ? (2 * sorted_expenses[(d - 1) / 2])
                                 : (sorted_expenses[(d / 2) - 1] + sorted_expenses[d / 2]);

    const int cur_expense = expenditure[idx];
    if (cur_expense >= medianx2) {
      num_notifications++;
    }

    trailing_expenses.pop_front();
    trailing_expenses.push_back(expenditure[idx]);
  }

  return num_notifications;
}

TEST_CASE("fraudulent_activity_notifications",
          "[interview_prep_kit][sorting][medium][incomplete]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  string nd_temp;
  getline(cin, nd_temp);

  vector<string> nd = split_string(nd_temp);

  int n = stoi(nd[0]);

  int d = stoi(nd[1]);

  string expenditure_temp_temp;
  getline(cin, expenditure_temp_temp);

  vector<string> expenditure_temp = split_string(expenditure_temp_temp);

  vector<int> expenditure(n);

  for (int i = 0; i < n; i++) {
    int expenditure_item = stoi(expenditure_temp[i]);

    expenditure[i] = expenditure_item;
  }

  int result = activityNotifications(expenditure, d);

  fout << result << "\n";

  fout.close();
}
