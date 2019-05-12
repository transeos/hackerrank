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
#include <iostream>

#include <catch2/catch.hpp>

using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s, long n) {
  const long str_len = s.size();

  const long num_repeat = (n / str_len);
  const long remainder = (n - (str_len * num_repeat));

  int num_a = 0;
  int num_remainder_a = 0;

  for (size_t idx = 0; idx < remainder; ++idx) {
    num_remainder_a += (s.at(idx) == 'a');
  }

  num_a = num_remainder_a;

  for (size_t idx = remainder; idx < str_len; ++idx) {
    num_a += (s.at(idx) == 'a');
  }

  return ((num_a * num_repeat) + num_remainder_a);
}

TEST_CASE("repeated_string", "[interview_prep_kit][easy][incomplete]") {
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
