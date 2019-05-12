// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/sock-merchant/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 12/05/19.
//
//*****************************************************************

#include <bits/stdc++.h>
#include <iostream>
#include <unordered_set>

#include <catch2/catch.hpp>

using namespace std;

vector<string> split_string(string);

// Complete the sockMerchant function below.
int sockMerchant(int n, const vector<int>& ar) {
  unordered_set<int> single_pair_socks;
  int pair_count = 0;

  for (size_t idx = 0; idx < n; ++idx) {
    const int sock = ar.at(idx);

    auto iter = single_pair_socks.find(sock);
    if (iter == single_pair_socks.end()) {
      single_pair_socks.insert(sock);
    } else {
      single_pair_socks.erase(iter);
      // cout << "pair found : " << sock << endl;
      pair_count++;
    }
  }

  return pair_count;
}

TEST_CASE("sock_merchant", "[interview_prep_kit][easy]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  int n;
  cin >> n;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  string ar_temp_temp;
  getline(cin, ar_temp_temp);

  vector<string> ar_temp = split_string(ar_temp_temp);

  vector<int> ar(n);

  for (int i = 0; i < n; i++) {
    int ar_item = stoi(ar_temp[i]);

    ar[i] = ar_item;
  }

  int result = sockMerchant(n, ar);

  fout << result << "\n";

  fout.close();
}

vector<string> split_string(string input_string) {
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
