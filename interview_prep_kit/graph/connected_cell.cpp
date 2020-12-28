// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/ctci-connected-cell-in-a-grid/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 28/12/19.
//
//*****************************************************************

#include "utils.h"
#include <bits/stdc++.h>
#include <catch2/catch.hpp>
#include <iostream>

using namespace std;

void IncreseRegionSize(vector<int>& regions, const unordered_map<int, int>& renamed_regions,
                       const int col_idx, const int increment = 1) {
  // check for rename

  int increment_col = col_idx;

  auto iter = renamed_regions.find(col_idx);
  if (iter != renamed_regions.end()) {
    increment_col = iter->second;
    iter = renamed_regions.find(increment_col);
  }
  assert(iter == renamed_regions.end());

  regions[increment_col] += increment;
}

// Complete the maxRegion function below.
int maxRegion(const vector<vector<int>>& grid) {
  const int num_row = grid.size();
  const int num_col = grid[0].size();

  int max_region = 0;

  vector<int> col_region(num_col, -1);
  vector<int> cur_region(num_col, -1);

  vector<int> regions;
  unordered_map<int, int> renamed_regions;

  for (size_t i = 0; i < num_row; ++i) {
    for (size_t j = 0; j < num_col; ++j) {
      if (grid[i][j] == 0) {
        cur_region[j] = -1;
        // cout << "(-1,0) ";
        continue;
      }

      if (i == 0) {
        // first line

        if ((j > 0) && (cur_region[j - 1] != -1)) {
          cur_region[j] = cur_region[j - 1];
        } else {
          // new region
          cur_region[j] = regions.size();
          regions.push_back(0);
        }

        IncreseRegionSize(regions, renamed_regions, cur_region[j]);
      } else {
        if (col_region[j] != -1) {
          cur_region[j] = col_region[j];
        } else if ((j > 0) && (col_region[j - 1] != -1)) {
          cur_region[j] = col_region[j - 1];
        } else if ((j < (num_col - 1)) && (col_region[j + 1] != -1)) {
          cur_region[j] = col_region[j + 1];
        } else {
          // new region
          cur_region[j] = regions.size();
          regions.push_back(0);
        }

        IncreseRegionSize(regions, renamed_regions, cur_region[j]);

        if ((j > 0) && (cur_region[j - 1] != -1) && (cur_region[j - 1] != cur_region[j])) {
          // merge regions
          int new_region_idx = cur_region[j - 1];
          auto iter = renamed_regions.find(new_region_idx);
          new_region_idx = ((iter != renamed_regions.end()) ? iter->second : new_region_idx);

          if (new_region_idx != cur_region[j]) {
            IncreseRegionSize(regions, renamed_regions, new_region_idx, regions[cur_region[j]]);
            regions[cur_region[j]] = 0;
            assert(renamed_regions.find(new_region_idx) == renamed_regions.end());
            renamed_regions[cur_region[j]] = new_region_idx;
            cur_region[j] = new_region_idx;
          }
        }
      }

      max_region = std::max(regions[cur_region[j]], max_region);
      // cout << "(" << cur_region[j] << "," << regions[cur_region[j]] << ") ";
    }

    col_region = cur_region;
    // cout << endl;
  }

  return max_region;
}

TEST_CASE("connected_cell", "[interview_prep_kit][graph][hard]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  int n;
  cin >> n;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  int m;
  cin >> m;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  vector<vector<int>> grid(n);
  for (int i = 0; i < n; i++) {
    grid[i].resize(m);

    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }

  int res = maxRegion(grid);

  fout << res << "\n";

  fout.close();
}
