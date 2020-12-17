// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/counting-valleys/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 12/05/19.
//
//*****************************************************************

#include <bits/stdc++.h>
#include <cassert>
#include <catch2/catch.hpp>
#include <iostream>

using namespace std;

// Complete the countingValleys function below.
int countingValleys(int n, string s) {
  int height = 0;
  int num_vallies = 0;

  for (size_t idx = 0; idx < n; ++idx) {
    const int prev_height = height;
    if (s.at(idx) == 'U') {
      height++;
    } else if (s.at(idx) == 'D') {
      height--;
    } else {
      assert(0);
    }

    if ((prev_height < 0) && (height == 0)) {
      num_vallies++;
    }
    // cout << height << endl;
  }

  return num_vallies;
}

TEST_CASE("counting_valleys", "[interview_prep_kit][warm-up][easy]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  int n;
  cin >> n;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  string s;
  getline(cin, s);

  int result = countingValleys(n, s);

  fout << result << "\n";

  fout.close();
}
