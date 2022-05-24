// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/extra-long-factorials/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 24/05/22.
//
//*****************************************************************

#include "utils.h"
#include <bits/stdc++.h>
#include <catch2/catch.hpp>

using std::cin;
using std::cout;
using std::endl;
using std::ofstream;
using std::string;
using std::vector;

/*
 * Complete the 'extraLongFactorials' function below.
 *
 * The function accepts INTEGER n as parameter.
 */

void extraLongFactorials(const int32_t n) {
  if (n <= 1) {
    cout << "1" << endl;
  }

  uint64_t result = 1;

  for (size_t i = 2; i <= (size_t)n; ++i) {
    result *= i;
  }

  cout << result << endl;
}

TEST_CASE("extra_long_factorials", "[problem_solving][medium][ToDo]") {
  string n_temp;
  getline(cin, n_temp);

  int n = stoi(ltrim(rtrim(n_temp)));

  extraLongFactorials(n);
}
