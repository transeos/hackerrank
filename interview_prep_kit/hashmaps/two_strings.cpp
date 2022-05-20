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
#include <execution>
#include <iostream>

using namespace std;

// Complete the twoStrings function below.
bool checkForExclusiveChar(const string& smallerWord, const string& biggerWord) {
  std::unordered_set letters(smallerWord.begin(), smallerWord.end());

  const bool noCommonChar =
      std::none_of(std::execution::par_unseq, biggerWord.begin(), biggerWord.end(),
                   [&letters](auto ch) { return letters.find(ch) != letters.end(); });
  return noCommonChar;
}

string twoStrings(const string& s1, const string& s2) {
  const bool noCommonChar =
      s1.length() < s2.length() ? checkForExclusiveChar(s1, s2) : checkForExclusiveChar(s2, s1);
  return noCommonChar ? "NO" : "YES";
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
