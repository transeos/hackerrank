// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/fibonacci-modified/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 23/05/22.
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
 * Complete the 'fibonacciModified' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER t1
 *  2. INTEGER t2
 *  3. INTEGER n
 */

constexpr uint64_t fibonacciModified(const int32_t t1, const int32_t t2, const int32_t n) {
  if (n < 2) {
    return t1;
  }
  if (n == 2) {
    return t2;
  }

  uint64_t prev = t1;
  uint64_t current = t2;

  for (size_t i = 3; i <= (size_t)n; ++i) {
    uint64_t temp = current;
    current = prev + (current * current);
    prev = temp;
  }

  return current;
}

TEST_CASE("fibonacci_modified", "[problem_solving][medium][ToDo]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  string first_multiple_input_temp;
  getline(cin, first_multiple_input_temp);

  vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

  int t1 = stoi(first_multiple_input[0]);

  int t2 = stoi(first_multiple_input[1]);

  int n = stoi(first_multiple_input[2]);

  uint64_t result = fibonacciModified(t1, t2, n);

  fout << result << "\n";

  fout.close();
}
