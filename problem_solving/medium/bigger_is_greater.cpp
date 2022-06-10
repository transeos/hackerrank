// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/bigger-is-greater/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 25/05/22.
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
 * Complete the 'biggerIsGreater' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING w as parameter.
 */

string biggerIsGreater(string& w) {
  if (std::next_permutation(w.begin(), w.end())) {
    return w;
  } else {
    return "no answer";
  }
}

TEST_CASE("bigger_is_greater", "[problem_solving][medium]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  string T_temp;
  getline(cin, T_temp);

  int T = stoi(ltrim(rtrim(T_temp)));

  for (int T_itr = 0; T_itr < T; T_itr++) {
    string w;
    getline(cin, w);

    string result = biggerIsGreater(w);

    fout << result << "\n";
  }

  fout.close();
}
