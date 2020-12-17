// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/two-strings/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 08/06/19.
//
//*****************************************************************

#include <bits/stdc++.h>
#include <catch2/catch.hpp>
#include <iostream>

using namespace std;

// Complete the twoStrings function below.
const char* twoStrings(string s1, string s2) {
  vector<bool> chars(128, false);

  const int s1_len = s1.size();
  for (int idx = 0; idx < s1_len; ++idx) {
    chars[s1[idx]] = true;
  }

  const int s2_len = s2.size();
  for (int idx = 0; idx < s2_len; ++idx) {
    if (chars[s2[idx]]) {
      return "YES";
    }
  }

  return "NO";
}

TEST_CASE("two_strings", "[interview_prep_kit][hashmaps][easy]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  int q;
  cin >> q;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  for (int q_itr = 0; q_itr < q; q_itr++) {
    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    string result = twoStrings(s1, s2);

    fout << result << "\n";
  }

  fout.close();
}
