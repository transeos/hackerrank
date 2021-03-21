// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/the-grid-search/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 21/03/21.
//
//*****************************************************************

#include "utils.h"
#include <bits/stdc++.h>
#include <catch2/catch.hpp>

using namespace std;

// Complete the gridSearch function below.
string gridSearch(const vector<string>& G, vector<string>& P) {
  if (G.size() < P.size()) {
    return "NO";
  }

  const size_t G_word_len = G[0].size();
  const size_t P_word_len = P[0].size();

  if (G_word_len < P_word_len) {
    return "NO";
  }

  const size_t P_num_rows = P.size();

  const size_t max_distance = std::max(P_num_rows, P_word_len);

  for (size_t row_idx = 0; row_idx <= (G.size() - P.size()); ++row_idx) {
    for (size_t col_idx = 0; col_idx <= (G_word_len - P_word_len); ++col_idx) {
      if (G[row_idx][col_idx] != P[0][0]) {
        continue;
      }

      bool break_loop = false;

      for (size_t distance = 2; distance <= max_distance; ++distance) {
        if (distance <= P_word_len) {
          const size_t row_limit = std::min((distance - 1), P_num_rows);

          for (size_t idx = 0; idx < row_limit; ++idx) {
            if (G[row_idx + idx][col_idx + distance - 1] != P[idx][distance - 1]) {
              break_loop = true;
              break;
            }
          }

          if (break_loop) {
            break;
          }
        }

        if (distance <= P_num_rows) {
          const size_t col_limit = std::min(distance, P_word_len);

          for (size_t idx = 0; idx < col_limit; ++idx) {
            if (G[row_idx + distance - 1][col_idx + idx] != P[distance - 1][idx]) {
              break_loop = true;
              break;
            }
          }

          if (break_loop) {
            break;
          }
        }
      }

      if (!break_loop) {
        return "YES";
      }
    }
  }

  return "NO";
}

TEST_CASE("grid_pattern_search", "[problem_solving][medium]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  int t;
  cin >> t;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  for (int t_itr = 0; t_itr < t; t_itr++) {
    string RC_temp;
    getline(cin, RC_temp);

    vector<string> RC = split_string(RC_temp);

    int R = stoi(RC[0]);

    int C = stoi(RC[1]);

    vector<string> G(R);

    for (int i = 0; i < R; i++) {
      string G_item;
      getline(cin, G_item);

      G[i] = G_item;
    }

    string rc_temp;
    getline(cin, rc_temp);

    vector<string> rc = split_string(rc_temp);

    int r = stoi(rc[0]);

    int c = stoi(rc[1]);

    vector<string> P(r);

    for (int i = 0; i < r; i++) {
      string P_item;
      getline(cin, P_item);

      P[i] = P_item;
    }

    string result = gridSearch(G, P);

    fout << result << "\n";
  }

  fout.close();
}
