// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/castle-on-the-grid/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 23/12/19.
//
//*****************************************************************

#include "utils.h"
#include <bits/stdc++.h>
#include <catch2/catch.hpp>
#include <iostream>

using namespace std;

int g_goalX = 0;
int g_goalY = 0;

class GridPoint {
 public:
  GridPoint(const int x, const int y, const int d = -1)
      : x_(x), y_(y), src_distance_(d), visited_(false) {}
  ~GridPoint() {}

  int GetX() const {
    return x_;
  }
  int GetY() const {
    return y_;
  }

  int GetSrcDistance() const {
    return src_distance_;
  }
  void SetSrcDistance(const int d) {
    assert(visited_ || (src_distance_ == -1));
    src_distance_ = d;
  }

  bool IsVisited() const {
    return visited_;
  }
  void SetVisited() {
    visited_ = true;
  }

 private:
  int x_;
  int y_;

  int src_distance_;

  bool visited_;
};

bool MinPriorityGridPointFn(const GridPoint* lhs, const GridPoint* rhs) {
  // a*
  int lhs_priority = (abs(lhs->GetX() - g_goalX) + abs(lhs->GetY() - g_goalY));
  assert((lhs_priority >> 10) == 0);
  lhs_priority += (lhs->GetSrcDistance() << 10);

  int rhs_priority = (abs(rhs->GetX() - g_goalX) + abs(rhs->GetY() - g_goalY));
  assert((rhs_priority >> 10) == 0);
  rhs_priority += (rhs->GetSrcDistance() << 10);

  return (lhs_priority > rhs_priority);
}

bool AddInQueue(priority_queue<GridPoint*, vector<GridPoint*>,
                               std::function<bool(const GridPoint*, const GridPoint*)>>& points,
                GridPoint& point, const int src_distance) {
  if (point.GetSrcDistance() == numeric_limits<int>::max()) {
    return false;
  }

  if (!point.IsVisited()) {
    point.SetSrcDistance(src_distance);
    point.SetVisited();
    points.push(&point);

    return true;
  } else if (point.GetSrcDistance() <= src_distance) {
    return true;
  }

  // re-build priority queue
  vector<GridPoint*> temp_queue;

  while (!points.empty()) {
    GridPoint* cur_pos = points.top();
    points.pop();

    if (cur_pos == &point) {
      break;
    }

    temp_queue.push_back(cur_pos);
  }

  point.SetSrcDistance(src_distance);
  points.push(&point);

  for (GridPoint* cur_pos : temp_queue) {
    points.push(cur_pos);
  }

  return true;
}

// Complete the minimumMoves function below.
int minimumMoves(const vector<string>& grid_str, const int startY, const int startX,
                 const int goalY, const int goalX) {
  g_goalX = goalX;
  g_goalY = goalY;

  vector<vector<GridPoint>> grid;
  grid.resize(grid_str.size());

  for (size_t row_idx = 0; row_idx < grid_str.size(); ++row_idx) {
    for (size_t ch_idx = 0; ch_idx < grid_str[row_idx].length(); ++ch_idx) {
      if (grid_str[row_idx][ch_idx] == 'X') {
        grid[row_idx].emplace_back(ch_idx, row_idx, numeric_limits<int>::max());
      } else {
        grid[row_idx].emplace_back(ch_idx, row_idx, -1);
      }
    }
  }

  /*for (auto& row : grid) {
    for (auto& point : row) {
      cout << ((point.GetSrcDistance() != numeric_limits<int>::max()) ? 1 : 0) << " ";
    }
    cout << endl;
  }*/

  priority_queue<GridPoint*, vector<GridPoint*>,
                 std::function<bool(const GridPoint*, const GridPoint*)>>
      points(MinPriorityGridPointFn);

  AddInQueue(points, grid[startY][startX], 0);

  while (!points.empty()) {
    GridPoint* cur_pos = points.top();
    // cout << cur_pos->GetX() << "," << cur_pos->GetY() << " : src distance=" <<
    // cur_pos->GetSrcDistance() << endl;

    if ((cur_pos->GetX() == goalX) && (cur_pos->GetY() == goalY)) {
      return cur_pos->GetSrcDistance();
    }

    points.pop();

    for (int col = (cur_pos->GetX() - 1); col >= 0; --col) {
      if (!AddInQueue(points, grid[cur_pos->GetY()][col], (cur_pos->GetSrcDistance() + 1))) {
        break;
      }
    }
    for (int col = (cur_pos->GetX() + 1); col < grid_str[cur_pos->GetY()].size(); ++col) {
      if (!AddInQueue(points, grid[cur_pos->GetY()][col], (cur_pos->GetSrcDistance() + 1))) {
        break;
      }
    }
    for (int row = (cur_pos->GetY() - 1); row >= 0; --row) {
      if (!AddInQueue(points, grid[row][cur_pos->GetX()], (cur_pos->GetSrcDistance() + 1))) {
        break;
      }
    }
    for (int row = (cur_pos->GetY() + 1); row < grid_str.size(); ++row) {
      if (!AddInQueue(points, grid[row][cur_pos->GetX()], (cur_pos->GetSrcDistance() + 1))) {
        break;
      }
    }
  }

  return -1;
}

TEST_CASE("castle_on_the_grid", "[interview_prep_kit][stacks_queues][medium]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  int n;
  cin >> n;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  vector<string> grid(n);

  for (int i = 0; i < n; i++) {
    string grid_item;
    getline(cin, grid_item);

    grid[i] = grid_item;
  }

  string startXStartY_temp;
  getline(cin, startXStartY_temp);

  vector<string> startXStartY = split_string(startXStartY_temp);

  int startX = stoi(startXStartY[0]);

  int startY = stoi(startXStartY[1]);

  int goalX = stoi(startXStartY[2]);

  int goalY = stoi(startXStartY[3]);

  int result = minimumMoves(grid, startX, startY, goalX, goalY);

  fout << result << "\n";

  fout.close();
}
