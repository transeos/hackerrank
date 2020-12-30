// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/ctci-recursive-staircase/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 30/12/20.
//
//*****************************************************************

#include "utils.h"
#include <bits/stdc++.h>
#include <catch2/catch.hpp>
#include <iostream>

using namespace std;

#define STEP_MOD 10000000007L

// Complete the stepPerms function below.
int64_t stepPerms(const int n) {
  if (n < 2) {
    return n;
  }
  if (n == 2) {
    return 2;
  }
  if (n == 3) {
    return 4;
  }

  int64_t cur_steps = 4;
  int64_t prev_steps = 2;
  int64_t prev_prev_steps = 1;

  for (size_t idx = 3; idx < n; ++idx) {
    int64_t temp = (cur_steps + prev_steps + prev_prev_steps);
    if (temp >= STEP_MOD) {
      temp -= STEP_MOD;
    }
    prev_prev_steps = prev_steps;
    prev_steps = cur_steps;
    cur_steps = temp;
  }

  return cur_steps;
}

TEST_CASE("davis_staircase", "[interview_prep_kit][recursion][medium]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  int s;
  cin >> s;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  for (int s_itr = 0; s_itr < s; s_itr++) {
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int64_t res = stepPerms(n);

    fout << res << "\n";
  }

  fout.close();
}
