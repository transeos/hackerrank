// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/minimum-swaps-2/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 13/05/19.
//
//*****************************************************************

#include <bits/stdc++.h>
#include <iostream>

#include <catch2/catch.hpp>

using namespace std;

vector<string> split_string4(string);

// Complete the minimumSwaps function below.
int minimumSwaps(vector<int> arr) {
  int num_swaps = 0;
  const int num_arr = arr.size();

  for (size_t idx = 0; idx < num_arr; ++idx) {
    int cur_val = arr[idx];
    while (cur_val != (idx + 1)) {
      const int temp_val = arr[cur_val - 1];
      arr[cur_val - 1] = cur_val;
      arr[idx] = temp_val;
      cur_val = temp_val;

      num_swaps++;
    }
  }

  return num_swaps;
}

TEST_CASE("minimum_swaps", "[interview_prep_kit][array][medium]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  int n;
  cin >> n;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  string arr_temp_temp;
  getline(cin, arr_temp_temp);

  vector<string> arr_temp = split_string4(arr_temp_temp);

  vector<int> arr(n);

  for (int i = 0; i < n; i++) {
    int arr_item = stoi(arr_temp[i]);

    arr[i] = arr_item;
  }

  int res = minimumSwaps(arr);

  fout << res << "\n";

  fout.close();
}

vector<string> split_string4(string input_string) {
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
