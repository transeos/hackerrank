// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/ctci-array-left-rotation/problem
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

vector<string> split_string3(string);

// Complete the rotLeft function below.
vector<int> rotLeft(const vector<int>& orig_arr, int d) {
  if (d == 0) return orig_arr;

  const int num = orig_arr.size();
  assert(d < num);

  vector<int> new_arr(num);

  for (size_t idx = 0; idx < (num - d); ++idx) {
    new_arr[idx] = orig_arr[idx + d];
  }

  for (size_t idx = (num - d); idx < num; ++idx) {
    new_arr[idx] = orig_arr[idx + d - num];
  }

  return new_arr;
}

TEST_CASE("array_left_rotation", "[array_left_rotation][array][easy]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  string nd_temp;
  getline(cin, nd_temp);

  vector<string> nd = split_string3(nd_temp);

  int n = stoi(nd[0]);

  int d = stoi(nd[1]);

  string a_temp_temp;
  getline(cin, a_temp_temp);

  vector<string> a_temp = split_string3(a_temp_temp);

  vector<int> a(n);

  for (int i = 0; i < n; i++) {
    int a_item = stoi(a_temp[i]);

    a[i] = a_item;
  }

  vector<int> result = rotLeft(a, d);

  for (int i = 0; i < result.size(); i++) {
    fout << result[i];

    if (i != result.size() - 1) {
      fout << " ";
    }
  }

  fout << "\n";

  fout.close();
}

vector<string> split_string3(string input_string) {
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
