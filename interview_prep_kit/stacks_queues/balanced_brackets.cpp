// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/balanced-brackets/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 23/12/20.
//
//*****************************************************************

#include "utils.h"
#include <bits/stdc++.h>
#include <catch2/catch.hpp>
#include <iostream>

using namespace std;

// Complete the isBalanced function below.
string isBalanced(const string& s) {
  stack<char> brackets;

  for (auto ch : s) {
    switch (ch) {
      case ')':
        if (brackets.empty() || (brackets.top() != '(')) {
          return "NO";
        }
        brackets.pop();
        break;

      case '}':
        if (brackets.empty() || (brackets.top() != '{')) {
          return "NO";
        }
        brackets.pop();
        break;

      case ']':
        if (brackets.empty() || (brackets.top() != '[')) {
          return "NO";
        }
        brackets.pop();
        break;

      default:
        brackets.push(ch);
    }
  }

  return (brackets.empty() ? "YES" : "NO");
}

TEST_CASE("balanced_brackets", "[interview_prep_kit][stacks_queues][medium]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  int t;
  cin >> t;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  for (int t_itr = 0; t_itr < t; t_itr++) {
    string s;
    getline(cin, s);

    string result = isBalanced(s);

    fout << result << "\n";
  }

  fout.close();
}
