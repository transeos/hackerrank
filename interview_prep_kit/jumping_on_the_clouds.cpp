// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 12/05/19.
//
//*****************************************************************

#include <bits/stdc++.h>
#include <cassert>
#include <iostream>

#include <catch2/catch.hpp>

using namespace std;

vector<string> split_string2(string);

// Complete the jumpingOnClouds function below.
int jumpingOnClouds(const vector<int>& c) {
  int num_jumps = 0;
  const int num_clouds = c.size();

  assert((c.at(0) == 0) && (c.at(num_clouds - 1) == 0));

  size_t idx = 2;
  for (; idx < num_clouds; idx += 2) {
    if (c.at(idx) == 1) {
      assert(c.at(idx - 1) == 0);
      idx--;
    }
    num_jumps++;
  }

  if (idx == num_clouds) {
    num_jumps++;
  }

  return num_jumps;
}

TEST_CASE("jumping_on_the_clouds", "[interview_prep_kit][easy][incomplete]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  int n;
  cin >> n;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  string c_temp_temp;
  getline(cin, c_temp_temp);

  vector<string> c_temp = split_string2(c_temp_temp);

  vector<int> c(n);

  for (int i = 0; i < n; i++) {
    int c_item = stoi(c_temp[i]);

    c[i] = c_item;
  }

  int result = jumpingOnClouds(c);

  fout << result << "\n";

  fout.close();
}

vector<string> split_string2(string input_string) {
  string::iterator new_end =
      unique(input_string.begin(), input_string.end(),
             [](const char& x, const char& y) { return x == y and x == ' '; });

  input_string.erase(new_end, input_string.end());

  while (input_string[input_string.length() - 1] == ' ') {
    input_string.pop_back();
  }

  vector<string> splits;
  char delimiter = ' ';

  size_t i = 0;
  size_t pos = input_string.find(delimiter);

  while (pos != string::npos) {
    splits.push_back(input_string.substr(i, pos - i));

    i = pos + 1;
    pos = input_string.find(delimiter, i);
  }

  splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

  return splits;
}
