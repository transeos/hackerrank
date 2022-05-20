// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/alternating-characters/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 02/01/21.
//
//*****************************************************************

#include "utils.h"
#include <bits/stdc++.h>
#include <catch2/catch.hpp>
#include <iostream>

using namespace std;

// Complete the alternatingCharacters function below.
int alternatingCharacters(string& s) {
  auto it = std::unique(s.begin(), s.end());
  return std::distance(it, s.end());
}

TEST_CASE("alternating_characters", "[interview_prep_kit][string][easy]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  int q;
  cin >> q;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  for (int q_itr = 0; q_itr < q; q_itr++) {
    string s;
    getline(cin, s);

    int result = alternatingCharacters(s);

    fout << result << "\n";
  }

  fout.close();
}
