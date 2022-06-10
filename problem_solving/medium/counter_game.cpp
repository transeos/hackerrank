// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/counter-game/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 24/05/22.
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
 * Complete the 'counterGame' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts LONG_INTEGER n as parameter.
 */

string counterGame(const uint64_t n) {
  bool louiseTurn = false;

  auto getPowerOf2Fn = [](uint64_t n) -> uint64_t {
    uint64_t power = 0;
    while (n > 1) {
      power++;
      n = n >> 1;
    }

    return power;
  };

  uint64_t curNum = n;
  uint64_t curMaxPower = 63;
  while (curNum != 1) {
    louiseTurn = !louiseTurn;

    const uint64_t powerOf2 = getPowerOf2Fn(curNum);
    const uint64_t nearestPowerOf2 = 1L << powerOf2;
    if (curNum == nearestPowerOf2) {
      if (powerOf2 % 2 == 0) {
        louiseTurn = !louiseTurn;
      }
      break;
    } else {
      curNum -= nearestPowerOf2;
    }
  }

  return louiseTurn ? "Louise" : "Richard";
}

TEST_CASE("counter_game", "[problem_solving][medium]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  string t_temp;
  getline(cin, t_temp);

  int t = stoi(ltrim(rtrim(t_temp)));

  for (int t_itr = 0; t_itr < t; t_itr++) {
    string n_temp;
    getline(cin, n_temp);

    long n = stol(ltrim(rtrim(n_temp)));

    string result = counterGame(n);

    fout << result << "\n";
  }

  fout.close();
}
