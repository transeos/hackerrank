// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/sherlock-and-anagrams/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 31/12/20.
//
//*****************************************************************

#include "utils.h"
#include <bits/stdc++.h>
#include <catch2/catch.hpp>
#include <iostream>

using namespace std;

// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(const string& s) {
  unordered_map<string, int> sub_strings;

  int num_anagrams = 0;

  for (size_t l = 1; l < s.length(); ++l) {
    for (size_t i = 0; i <= (s.length() - l); ++i) {
      string sub_str = s.substr(i, l);
      sort(sub_str.begin(), sub_str.end());

      auto iter = sub_strings.find(sub_str);
      if (iter != sub_strings.end()) {
        iter->second++;
        cout << iter->second << " : " << s.substr(i, l) << endl;
      } else {
        sub_strings[sub_str] = 1;
      }
    }
  }

  for (auto iter : sub_strings) {
    // nC2
    num_anagrams += ((iter.second * (iter.second - 1)) / 2);
  }

  return num_anagrams;
}

TEST_CASE("sherlock_anagrams", "[interview_prep_kit][hashmaps][medium][star]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  int q;
  cin >> q;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  for (int q_itr = 0; q_itr < q; q_itr++) {
    string s;
    getline(cin, s);

    int result = sherlockAndAnagrams(s);

    fout << result << "\n";
  }

  fout.close();
}
