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

// Complete the stepPerms function below.
constexpr int stepPerms(const int n) {
  if (n <= 0) {
    return 0;
  }
  if (n == 1) {
    return 1;
  }
  if (n == 2) {
    return 2;
  }
  if (n == 3) {
    return 4;
  }

  int prevPrevNumSteps = 1;
  int prevNumSteps = 2;
  int curNumSteps = 4;

  for (size_t i = 4; i <= (size_t)n; ++i) {
    const int temp = curNumSteps;

    curNumSteps = (curNumSteps + prevNumSteps + prevPrevNumSteps) % 10000000007;
    prevPrevNumSteps = prevNumSteps;
    prevNumSteps = temp;
  }

  return curNumSteps;
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
