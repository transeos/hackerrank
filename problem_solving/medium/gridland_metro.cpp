// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/gridland-metro/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 27/05/22.
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

int32_t gridlandMetro(const int32_t n, const int32_t m, const int32_t k,
                      const vector<vector<int>>& tracks) {
  /*std::unordered_map<uint32_t, std::map<uint32_t, uint32_t>> grid;

  for (const vector<int>& track : tracks)
  {
    const uint32_t rowIndex = track[0] - 1;
    const uint32_t trackStart = track[1] - 1;
    const uint32_t trackEnd = track[2] - 1;

    auto gridIter = grid.find(rowIndex);
    if (gridIter == grid.end())
    {
      grid[rowIndex][trackStart] = trackEnd;
    }
    else
    {
      auto& row = gridIter->second;
      auto it = std::lower_bound(row.begin(), row.end(), trackStart);

      if (it == row.end())
      {
        if (row.back().second >= trackStart)
        {
          // merge
          row.back().second = std::max(row.back().second, trackEnd);
        }
        else
        {
          row[trackStart] = trackEnd;
        }
      }
      else
      {
        if (it.first == trackStart)
        {
          auto nextIter = it;
          while (nextIter.first

        }
      }
    }
  }*/

  return 0;
}

TEST_CASE("gridland_metro", "[problem_solving][medium][ToDo]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  string first_multiple_input_temp;
  getline(cin, first_multiple_input_temp);

  vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

  int n = stoi(first_multiple_input[0]);

  int m = stoi(first_multiple_input[1]);

  int k = stoi(first_multiple_input[2]);

  vector<vector<int>> track(k);

  for (int i = 0; i < k; i++) {
    track[i].resize(3);

    string track_row_temp_temp;
    getline(cin, track_row_temp_temp);

    vector<string> track_row_temp = split(rtrim(track_row_temp_temp));

    for (int j = 0; j < 3; j++) {
      int track_row_item = stoi(track_row_temp[j]);

      track[i][j] = track_row_item;
    }
  }

  int result = gridlandMetro(n, m, k, track);

  fout << result << "\n";

  fout.close();
}
