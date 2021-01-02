// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/special-palindrome-again/problem
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

// Complete the substrCount function below.
long substrCount(const int n, const string& s) {
  // single characters
  long num_palindrome = n;

  for (size_t idx = 1; idx < n; ++idx) {
    int max_len = std::min(((idx * 2) + 1), (((n - idx - 1) * 2) + 1));
    if ((idx << 1) == n) {
      max_len++;
    } else if (max_len == 1) {
      max_len = 2;
    }

    bool check_odd_len = true;
    bool check_even_len = true;

    const char c_odd = s[idx - 1];
    const char c_even = s[idx];

    for (size_t l = 2; l <= max_len; ++l) {
      if ((l % 2) == 1) {
        // odd length sub string
        if (check_odd_len) {
          if ((s[idx - ((l - 1) / 2)] != c_odd) || (s[idx + ((l - 1) / 2)] != c_odd)) {
            check_odd_len = false;
          } else {
            num_palindrome++;
            // cout << s.substr((idx - ((l - 1) / 2)), l) << ", ";
            // cout << l << "(" << idx << ")" << endl;
          }
        }
      } else {
        if (check_even_len) {
          if ((s[idx - (l / 2)] != c_even) || (s[idx + (l / 2) - 1] != c_even)) {
            check_even_len = false;
          } else {
            num_palindrome++;
            // cout << s.substr((idx - (l / 2)), l) << ", ";
            // cout << l << "(" << idx << ")" << endl;
          }
        }
      }

      if (!check_odd_len && !check_even_len) {
        break;
      }
    }
  }

  return num_palindrome;
}

TEST_CASE("special_palindrome_again", "[interview_prep_kit][string][medium][incomplete][failed]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  int n;
  cin >> n;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  string s;
  getline(cin, s);

  long result = substrCount(n, s);

  fout << result << "\n";

  fout.close();
}
