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
  std::array<int32_t, 26> lettersA;
  std::array<int32_t, 26> lettersB;

  auto populateLettersFn = [](std::array<int32_t, 26>& letters, const string& word) {
    std::fill(letters.begin(), letters.end(), 0);

    std::for_each(word.begin(), word.end(), [&letters](char ch) { letters[ch - 'a']++; });
  };

  populateLettersFn(lettersA, a);
  populateLettersFn(lettersB, b);

  int32_t numDeletions = 0;

  for (size_t i = 0; i < 26; i++) {
    numDeletions += std::abs(lettersA[i] - lettersB[i]);
  }

  return numDeletions;
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
