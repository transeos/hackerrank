// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/ctci-big-o/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 29/12/19.
//
//*****************************************************************

#include "utils.h"
#include <bits/stdc++.h>
#include <catch2/catch.hpp>
#include <iostream>

using namespace std;

// Complete the primality function below.
string primality(const int n) {
  if (n == 1) {
    return "Not prime";
  }

  if (n < 4) {
    return "Prime";
  }

  if ((n % 2) == 0) {
    return "Not prime";
  }

  const int max_try = sqrt(n);
  for (size_t idx = 3; idx <= max_try; idx += 2) {
    if ((n % idx) == 0) {
      return "Not prime";
    }
  }

  return "Prime";
}

TEST_CASE("primality", "[interview_prep_kit][miscellaneous][medium]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  int p;
  cin >> p;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  for (int p_itr = 0; p_itr < p; p_itr++) {
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = primality(n);

    fout << result << "\n";
  }

  fout.close();
}
