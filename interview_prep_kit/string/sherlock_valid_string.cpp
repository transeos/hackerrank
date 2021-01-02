// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/sherlock-and-valid-string/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 02/01/21.
//
//*****************************************************************
//
// Test case 4 : aabbc = YES
// Test case 19: abbccc = NO

#include "utils.h"
#include <bits/stdc++.h>
#include <catch2/catch.hpp>
#include <iostream>

using namespace std;

// Complete the isValid function below.
string isValid(const string& s) {
  array<int, 26> characters = {};

  for (char c : s) {
    characters[c - 'a']++;
  }

  int freq = 0;
  int alternate_freq = 0;
  bool deletion = false;

  for (size_t idx = 0; idx < 26; ++idx) {
    const int num_c = characters[idx];
    if (num_c == 0) {
      continue;
    }

    if (freq == 0) {
      freq = num_c;
      continue;
    }

    if (freq == num_c) {
      // frequency fixed
      alternate_freq = freq;
      continue;
    }

    if (alternate_freq == freq) {
      if (deletion) {
        return "NO";
      }

      if ((num_c == 1) || (num_c == (freq + 1))) {
        deletion = true;
        continue;
      } else {
        return "NO";
      }
    }

    if (alternate_freq == num_c) {
      // frequency fixed
      freq = alternate_freq;
      continue;
    }

    if (num_c == (freq + 1)) {
      if (alternate_freq == 0) {
        alternate_freq = num_c;
        deletion = true;
        continue;
      }
      return "NO";
    }

    if (num_c == (freq - 1)) {
      if (alternate_freq == 0) {
        alternate_freq = freq;
        freq = num_c;
        deletion = true;
        continue;
      }
      return "NO";
    }

    if (num_c == 1) {
      if (alternate_freq == 0) {
        alternate_freq = freq;
        deletion = true;
        continue;
      }
      return "NO";
    }

    return "NO";
  }

  return "YES";
}

TEST_CASE("sherlock_valid_string", "[interview_prep_kit][string][medium]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  string s;
  getline(cin, s);

  string result = isValid(s);

  fout << result << "\n";

  fout.close();
}
