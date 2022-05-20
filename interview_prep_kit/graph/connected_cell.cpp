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

int32_t maxRegion(const vector<vector<int>>& grid) {
  const size_t numRows = grid.size();
  if (numRows == 0) {
    return 0;
  }

  const size_t numColumns = grid[0].size();

  vector<vector<int>> groupIds(numRows);
  for (size_t i = 0; i < numRows; ++i) {
    groupIds[i].resize(numColumns);
    std::fill(groupIds[i].begin(), groupIds[i].end(), std::numeric_limits<int32_t>::max());
  }

  int32_t numGroups = 0;
  vector<int32_t> groupSize;

  std::unordered_map<int32_t, int32_t> groupMap;
  groupMap[std::numeric_limits<int32_t>::max()] = std::numeric_limits<int32_t>::max();

  auto addItemFn = [&grid, numRows, numColumns](auto& neighbours, int32_t rowIndex,
                                                int32_t columnIndex) {
    if (rowIndex >= 0 && columnIndex >= 0 && rowIndex < numRows && columnIndex < numColumns) {
      if (grid[rowIndex][columnIndex] == 1) {
        neighbours.emplace_back(rowIndex, columnIndex);
      }
    }
  };

  for (int32_t i = 0; i < numRows; ++i) {
    for (int32_t j = 0; j < numColumns; ++j) {
      if (grid[i][j] == 0) {
        continue;
      }

      vector<std::pair<int32_t, int32_t>> neighbours;

      addItemFn(neighbours, i - 1, j - 1);
      addItemFn(neighbours, i - 1, j);
      addItemFn(neighbours, i - 1, j + 1);
      addItemFn(neighbours, i, j - 1);
      addItemFn(neighbours, i, j);
      addItemFn(neighbours, i, j + 1);
      addItemFn(neighbours, i + 1, j - 1);
      addItemFn(neighbours, i + 1, j);
      addItemFn(neighbours, i + 1, j + 1);

      int32_t minGroupId = std::numeric_limits<int32_t>::max();

      for_each(neighbours.begin(), neighbours.end(),
               [&minGroupId, &groupMap, &groupIds](std::pair<int32_t, int32_t>& cell) {
                 minGroupId = min(minGroupId, groupMap[groupIds[cell.first][cell.second]]);
               });

      if (minGroupId == std::numeric_limits<int32_t>::max()) {
        numGroups++;
        minGroupId = numGroups;
        groupMap[numGroups] = numGroups;
        groupSize.push_back(0);
      }

      for (auto& cell : neighbours) {
        const int32_t prevGroupId = groupIds[cell.first][cell.second];
        if (prevGroupId != minGroupId) {
          groupIds[cell.first][cell.second] = minGroupId;
          groupSize[minGroupId - 1]++;

          if (prevGroupId != std::numeric_limits<int32_t>::max()) {
            groupMap[prevGroupId] = minGroupId;
            groupSize[prevGroupId - 1]--;
          }
        }
      };
    }
  }

  int32_t maxRegionSize = 0;

  for (int32_t groupId = groupSize.size(); groupId > 0; --groupId) {
    const int32_t mappedGroupId = groupMap[groupId];
    if (mappedGroupId == groupId) {
      maxRegionSize = max(maxRegionSize, groupSize[groupId - 1]);
    } else {
      const int32_t letfOver = groupSize[groupId - 1];
      if (letfOver > 0) {
        groupSize[mappedGroupId - 1] += letfOver;
        groupSize[groupId - 1] = 0;
      }
    }
  }

  return maxRegionSize;
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
