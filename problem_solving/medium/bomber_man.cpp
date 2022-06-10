// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/bomber-man/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 22/05/22.
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
 * Complete the 'bomberMan' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. STRING_ARRAY grid
 */

vector<string> bomberMan(const int32_t n, const vector<string>& grid) {
  vector<string> output;

  if (n <= 1) {
    output = grid;
    return output;
  }

  const size_t columnSize = grid[0].length();
  const string allbombsRow(columnSize, 'O');
  const int32_t state = (n - 2) % 4;

  auto explodeBombs = [&output, &columnSize](const int64_t i, const int64_t j) {
    if (i < 0 || i >= output.size() || j < 0 || j >= columnSize) {
      return;
    }

    output[i][j] = '.';
  };

  if (state == 0 || state == 2) {
    output.resize(grid.size(), allbombsRow);
  } else if (state == 1) {
    output.resize(grid.size(), allbombsRow);

    for (int64_t i = 0; i < grid.size(); ++i) {
      for (int64_t j = 0; j < columnSize; ++j) {
        if (grid[i][j] == 'O') {
          explodeBombs(i, j);
          explodeBombs(i - 1, j);
          explodeBombs(i + 1, j);
          explodeBombs(i, j - 1);
          explodeBombs(i, j + 1);
        }
      }
    }
  } else if (state == 3) {
    output = grid;
  }

  return output;
}

TEST_CASE("bomber_man", "[problem_solving][medium][ToDo]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  string first_multiple_input_temp;
  getline(cin, first_multiple_input_temp);

  vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

  int r = stoi(first_multiple_input[0]);

  int c = stoi(first_multiple_input[1]);

  int n = stoi(first_multiple_input[2]);

  vector<string> grid(r);

  for (int i = 0; i < r; i++) {
    string grid_item;
    getline(cin, grid_item);

    grid[i] = grid_item;
  }

  vector<string> result = bomberMan(n, grid);

  for (size_t i = 0; i < result.size(); i++) {
    fout << result[i];

    if (i != result.size() - 1) {
      fout << "\n";
    }
  }

  fout << "\n";

  fout.close();
}
