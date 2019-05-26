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
#include <cassert>
#include <iostream>

#include "utils.h"
#include <catch2/catch.hpp>

#define MAX_EXPENSE 200

using namespace std;

int getMedianX2Odd(const vector<int>& sorted_expenses, const int d) {
  assert(d % 2);
  const int target_pos = ((d + 1) / 2);

  int cur_pos = 0;
  for (int idx = 0; idx <= MAX_EXPENSE; ++idx) {
    cur_pos += sorted_expenses[idx];
    if (cur_pos >= target_pos) {
      return (idx * 2);
    }
  }

  assert(0);
  return -1;
}

int getMedianX2Even(const vector<int>& sorted_expenses, const int d) {
  assert((d % 2) == 0);
  const int target_pos1 = (d / 2);
  const int target_pos2 = ((d / 2) + 1);

  int cur_pos = 0;
  int cur_val = -1;

  for (int idx = 0; idx <= MAX_EXPENSE; ++idx) {
    cur_pos += sorted_expenses[idx];
    if ((cur_val < 0) && (cur_pos >= target_pos1)) {
      cur_val = idx;
    }

    if (cur_pos >= target_pos2) {
      return (cur_val + idx);
    }
  }

  assert(0);
  return -1;
}

void printQueue(deque<int>& trailing_expenses, const int d) {
  for (int jdx = 0; jdx < d; ++jdx) {
    cout << trailing_expenses[jdx] << " ";
  }
  cout << endl;
}

// Complete the activityNotifications function below.
int activityNotifications(vector<int>& expenditure, int d) {
  vector<int> sorted_expenses((MAX_EXPENSE + 1), 0);

  deque<int> trailing_expenses;
  for (int idx = 0; idx < d; ++idx) {
    const int cur_expense = expenditure[idx];
    assert(cur_expense <= MAX_EXPENSE);
    trailing_expenses.push_back(cur_expense);
    sorted_expenses[cur_expense]++;
  }

  int num_notifications = 0;

  const int num_days = expenditure.size();
  for (int idx = d; idx < num_days; ++idx) {
    const int medianx2 =
        ((d % 2) ? getMedianX2Odd(sorted_expenses, d) : getMedianX2Even(sorted_expenses, d));

    const int cur_expense = expenditure[idx];
    if (cur_expense >= medianx2) {
      num_notifications++;
    }

    const int last_expense = trailing_expenses.front();
    trailing_expenses.pop_front();
    sorted_expenses[last_expense]--;

    trailing_expenses.push_back(cur_expense);
    sorted_expenses[cur_expense]++;
  }

  return num_notifications;
}

TEST_CASE("fraudulent_activity_notifications", "[interview_prep_kit][sorting][medium]") {
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
