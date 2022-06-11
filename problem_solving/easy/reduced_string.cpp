// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/reduced-string/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 11/06/22.
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
 * Complete the 'superReducedString' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string superReducedString(const string& s) {
  string output;

  for (char c : s) {
    if (!output.empty() && output.back() == c) {
      output.pop_back();
    } else {
      output.push_back(c);
    }
  }

  if (output.length() == 0) {
    output = "Empty String";
  }

  return output;
}

TEST_CASE("reduced_string", "[problem_solving][easy]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  string s;
  getline(cin, s);

  string result = superReducedString(s);

  fout << result << "\n";

  fout.close();
}
