// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/frequency-queries/problem
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

// Complete the freqQuery function below.
vector<int> freqQuery(const vector<vector<int>>& queries) {
  vector<int> results;

  // key = number from user, value = count
  unordered_map<int, int> numbers;

  // key = frequency, value = count
  unordered_map<int, int> freq;
  freq[1] = 0;

  for (auto& query : queries) {
    if (query[0] == 1) {
      // add
      auto iter = numbers.find(query[1]);
      if (iter != numbers.end()) {
        freq[iter->second]--;

        iter->second++;

        auto iter2 = freq.find(iter->second);
        if (iter2 != freq.end()) {
          iter2->second++;
        } else {
          freq[iter->second] = 1;
        }
      } else {
        numbers[query[1]] = 1;
        freq[1]++;
      }
    } else if (query[0] == 2) {
      // remove
      auto iter = numbers.find(query[1]);
      if (iter != numbers.end()) {
        freq[iter->second]--;

        iter->second--;
        if (iter->second == 0) {
          numbers.erase(iter);
        } else {
          freq[iter->second]++;
        }
      }
    } else if (query[0] == 3) {
      auto iter = freq.find(query[1]);
      if (iter != freq.end()) {
        results.push_back((iter->second > 0) ? 1 : 0);
      } else {
        results.push_back(0);
      }
    } else {
      assert(0);
    }
  }

  return results;
}

TEST_CASE("frequency_queries", "[interview_prep_kit][hashmaps][medium]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  string q_temp;
  getline(cin, q_temp);

  int q = stoi(ltrim(rtrim(q_temp)));

  vector<vector<int>> queries(q);

  for (int i = 0; i < q; i++) {
    queries[i].resize(2);

    string queries_row_temp_temp;
    getline(cin, queries_row_temp_temp);

    vector<string> queries_row_temp = split(rtrim(queries_row_temp_temp));

    for (int j = 0; j < 2; j++) {
      int queries_row_item = stoi(queries_row_temp[j]);

      queries[i][j] = queries_row_item;
    }
  }

  vector<int> ans = freqQuery(queries);

  for (int i = 0; i < ans.size(); i++) {
    fout << ans[i];

    if (i != ans.size() - 1) {
      fout << "\n";
    }
  }

  fout << "\n";

  fout.close();
}
