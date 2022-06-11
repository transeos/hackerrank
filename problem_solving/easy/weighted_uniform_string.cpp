// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/weighted-uniform-string/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 11/06/22.
//
//*****************************************************************

#include "utils.h"
#include <bits/stdc++.h>
#include <catch2/catch.hpp>

using std::cin;
using std::cout;
using std::endl;
using std::ofstream;
using std::string;
using std::vector;

/*
 * Complete the 'weightedUniformStrings' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. INTEGER_ARRAY queries
 */

vector<string> weightedUniformStrings(const string& s, const vector<int>& queries) {
  vector<string> output;
  std::set<int64_t> weights;

  auto getWeightFn = [](const char c) -> int32_t { return c - 'a' + 1; };

  weights.insert(getWeightFn(s[0]));
  int64_t duplicateCount = 1;

  for (size_t i = 1; i < s.length(); ++i) {
    duplicateCount = (s[i] != s[i - 1]) ? 1 : (duplicateCount + 1);
    weights.insert((int64_t)getWeightFn(s[i]) * duplicateCount);
  }

  for (const int query : queries) {
    if (weights.find(query) == weights.end()) {
      output.emplace_back("No");
    } else {
      output.emplace_back("Yes");
    }
  }

  return output;
}

TEST_CASE("weighted_uniform_string", "[problem_solving][easy]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  string s;
  getline(cin, s);

  string queries_count_temp;
  getline(cin, queries_count_temp);

  int queries_count = stoi(ltrim(rtrim(queries_count_temp)));

  vector<int> queries(queries_count);

  for (int i = 0; i < queries_count; i++) {
    string queries_item_temp;
    getline(cin, queries_item_temp);

    int queries_item = stoi(ltrim(rtrim(queries_item_temp)));

    queries[i] = queries_item;
  }

  vector<string> result = weightedUniformStrings(s, queries);

  for (size_t i = 0; i < result.size(); i++) {
    fout << result[i];

    if (i != result.size() - 1) {
      fout << "\n";
    }
  }

  fout << "\n";

  fout.close();
}
