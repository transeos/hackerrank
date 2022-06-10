// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/queens-attack-2/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 25/05/22.
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
 * Complete the 'queensAttack' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER k
 *  3. INTEGER r_q
 *  4. INTEGER c_q
 *  5. 2D_INTEGER_ARRAY obstacles
 */

enum class ChessDirection : uint8_t {
  East = 0,
  West,
  North,
  South,
  NorthEast,
  NorthWest,
  SouthEast,
  SouthWest,
  NumDirection
};

int32_t queensAttack(const int32_t n, const int32_t k, const int32_t r_q, const int32_t c_q,
                     const vector<vector<int>>& obstacles) {
  //  : NW   N  NE
  //  : W    x  E(0)
  // y: SW   S  SE
  // x: .....

  std::array<int32_t, static_cast<uint8_t>(ChessDirection::NumDirection)> maxDistance = {};

  maxDistance[static_cast<uint8_t>(ChessDirection::West)] = c_q - 1;
  maxDistance[static_cast<uint8_t>(ChessDirection::East)] =
      n - maxDistance[static_cast<uint8_t>(ChessDirection::West)] - 1;

  maxDistance[static_cast<uint8_t>(ChessDirection::South)] = r_q - 1;
  maxDistance[static_cast<uint8_t>(ChessDirection::North)] =
      n - maxDistance[static_cast<uint8_t>(ChessDirection::South)] - 1;

  maxDistance[static_cast<uint8_t>(ChessDirection::NorthEast)] =
      std::min(maxDistance[static_cast<uint8_t>(ChessDirection::North)],
               maxDistance[static_cast<uint8_t>(ChessDirection::East)]);
  maxDistance[static_cast<uint8_t>(ChessDirection::NorthWest)] =
      std::min(maxDistance[static_cast<uint8_t>(ChessDirection::North)],
               maxDistance[static_cast<uint8_t>(ChessDirection::West)]);
  maxDistance[static_cast<uint8_t>(ChessDirection::SouthEast)] =
      std::min(maxDistance[static_cast<uint8_t>(ChessDirection::South)],
               maxDistance[static_cast<uint8_t>(ChessDirection::East)]);
  maxDistance[static_cast<uint8_t>(ChessDirection::SouthWest)] =
      std::min(maxDistance[static_cast<uint8_t>(ChessDirection::South)],
               maxDistance[static_cast<uint8_t>(ChessDirection::West)]);

  auto UpdateDistance = [&maxDistance](const size_t direction, const int32_t distance) {
    assert(distance > 0);
    maxDistance[direction] = std::min(maxDistance[direction], distance - 1);
  };

  for (const vector<int>& obstacle : obstacles) {
    if (obstacle[0] == r_q) {
      // obstacle on at queen's position
      if (obstacle[1] == c_q) {
        return 0;
      }

      if (obstacle[1] > c_q) {
        UpdateDistance(static_cast<uint8_t>(ChessDirection::East), obstacle[1] - c_q);
      } else {
        UpdateDistance(static_cast<uint8_t>(ChessDirection::West), c_q - obstacle[1]);
      }
    } else if (obstacle[1] == c_q) {
      if (obstacle[0] > r_q) {
        UpdateDistance(static_cast<uint8_t>(ChessDirection::North), obstacle[0] - r_q);
      } else {
        UpdateDistance(static_cast<uint8_t>(ChessDirection::South), r_q - obstacle[0]);
      }
    } else {
      const int32_t xDiff = obstacle[1] - c_q;
      const int32_t yDiff = obstacle[0] - r_q;
      if (std::abs(xDiff) == std::abs(yDiff)) {
        if (xDiff > 0) {
          if (yDiff > 0) {
            UpdateDistance(static_cast<uint8_t>(ChessDirection::NorthEast), xDiff);
          } else {
            UpdateDistance(static_cast<uint8_t>(ChessDirection::SouthEast), xDiff);
          }
        } else {
          if (yDiff > 0) {
            UpdateDistance(static_cast<uint8_t>(ChessDirection::NorthWest), xDiff * (-1));
          } else {
            UpdateDistance(static_cast<uint8_t>(ChessDirection::SouthWest), xDiff * (-1));
          }
        }
      }
    }
  }

  // std::for_each(maxDistance.begin(), maxDistance.end(), [](const int32_t distance) { cout <<
  // distance << ","; }); cout << endl;

  int32_t numAttackPos = std::accumulate(maxDistance.begin(), maxDistance.end(), 0);
  return numAttackPos;
}

TEST_CASE("queens_attack_2", "[problem_solving][medium]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  string first_multiple_input_temp;
  getline(cin, first_multiple_input_temp);

  vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

  int n = stoi(first_multiple_input[0]);

  int k = stoi(first_multiple_input[1]);

  string second_multiple_input_temp;
  getline(cin, second_multiple_input_temp);

  vector<string> second_multiple_input = split(rtrim(second_multiple_input_temp));

  int r_q = stoi(second_multiple_input[0]);

  int c_q = stoi(second_multiple_input[1]);

  vector<vector<int>> obstacles(k);

  for (int i = 0; i < k; i++) {
    obstacles[i].resize(2);

    string obstacles_row_temp_temp;
    getline(cin, obstacles_row_temp_temp);

    vector<string> obstacles_row_temp = split(rtrim(obstacles_row_temp_temp));

    for (int j = 0; j < 2; j++) {
      int obstacles_row_item = stoi(obstacles_row_temp[j]);

      obstacles[i][j] = obstacles_row_item;
    }
  }

  int result = queensAttack(n, k, r_q, c_q, obstacles);

  fout << result << "\n";

  fout.close();
}
