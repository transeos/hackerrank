// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/abbr/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 03/01/21.
//
//*****************************************************************

#include "utils.h"
#include <bits/stdc++.h>
#include <catch2/catch.hpp>
#include <iostream>

using namespace std;

// Complete the abbreviation function below.
string abbreviation(const string& a, const string& b) {
  if (a.length() < b.length()) {
    return "NO";
  }

  const int lena = a.length();
  const int lenb = b.length();

  vector<vector<int>> matched_str;
  matched_str.resize(lenb + 1);

  for (size_t i = 0; i <= lenb; ++i) {
    matched_str[i].resize(lena + 1);
    matched_str[i][0] = 0;
  }

  for (size_t j = 0; j <= lena; ++j) {
    matched_str[0][j] = 0;
  }

  for (size_t i = 1; i <= lenb; ++i) {
    for (size_t j = 1; j <= lena; ++j) {
      int data1 = matched_str[i - 1][j - 1];
      int data2 = matched_str[i - 1][j];
      int data3 = matched_str[i][j - 1];

      if (islower(a[j - 1])) {
        if (b[i - 1] == toupper(a[j - 1])) {
          data1++;
        }
      } else {
        if (b[i - 1] == a[j - 1]) {
          data1++;
        } else {
          // dead path
          matched_str[i][j] = numeric_limits<int>::min();
          continue;
        }
      }

      matched_str[i][j] = std::max(data1, std::max(data2, data3));
    }
  }

  // cout << a.length() << "," << b.length() << " : " << matched_str[lenb][lena] << endl;
  assert(matched_str[lenb][lena] <= (int)b.length());
  return (matched_str[lenb][lena] == b.length() ? "YES" : "NO");
}

TEST_CASE("abbreviation", "[interview_prep_kit][DP][medium][star][incomplete][failed]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  int q;
  cin >> q;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  for (int q_itr = 0; q_itr < q; q_itr++) {
    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    string result = abbreviation(a, b);

    fout << result << "\n";
  }

  fout.close();
}
