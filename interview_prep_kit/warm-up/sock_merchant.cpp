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

#include "utils.h"
#include <bits/stdc++.h>
#include <catch2/catch.hpp>
#include <iostream>
#include <unordered_set>

using namespace std;

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

TEST_CASE("sock_merchant", "[interview_prep_kit][warm-up][easy]") {
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
