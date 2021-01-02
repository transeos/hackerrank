// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/ctci-making-anagrams/problem
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

// Complete the makeAnagram function below.
int makeAnagram(const string& a, const string& b) {
  array<int, 26> characters_a = {};
  array<int, 26> characters_b = {};

  for (char c : a) {
    characters_a[c - 'a']++;
  }
  for (char c : b) {
    characters_b[c - 'a']++;
  }

  int num_deletion = 0;
  for (size_t idx = 0; idx < 26; ++idx) {
    num_deletion += abs(characters_a[idx] - characters_b[idx]);
  }

  return num_deletion;
}

TEST_CASE("making_anagrams", "[interview_prep_kit][string][easy]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  string a;
  getline(cin, a);

  string b;
  getline(cin, b);

  int res = makeAnagram(a, b);

  fout << res << "\n";

  fout.close();
}
