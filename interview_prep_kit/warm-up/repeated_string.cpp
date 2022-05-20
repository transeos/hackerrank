// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/repeated-string/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 12/05/19.
//
//*****************************************************************

#include <bits/stdc++.h>
#include <catch2/catch.hpp>
#include <iostream>

using namespace std;

// Complete the repeatedString function below.
uint64_t repeatedString(const string& s, uint64_t n) {
  uint64_t repeatsInSubStrBegin = 0;

  size_t subStrLen = n % s.length();
  if (subStrLen != 0) {
    repeatsInSubStrBegin = std::count(s.begin(), s.begin() + subStrLen, 'a');
  }

  uint64_t repeatsInSubStrEnd = std::count(s.begin() + subStrLen, s.end(), 'a');

  return ((repeatsInSubStrBegin + repeatsInSubStrEnd) * (n / s.length())) + repeatsInSubStrBegin;
}

TEST_CASE("repeated_string", "[interview_prep_kit][warm-up][easy]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  string s;
  getline(cin, s);

  long n;
  cin >> n;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  long result = repeatedString(s, n);

  fout << result << "\n";

  fout.close();
}
