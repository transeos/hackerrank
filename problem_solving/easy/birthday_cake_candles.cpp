// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/birthday-cake-candles/problem
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
 * Complete the 'birthdayCakeCandles' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY candles as parameter.
 */

int32_t birthdayCakeCandles(const vector<int>& candles) {
  int32_t maxHeight = candles[0];
  int32_t candleCount = 1;

  for (size_t i = 1; i < candles.size(); ++i) {
    if (candles[i] > maxHeight) {
      maxHeight = candles[i];
      candleCount = 1;
    } else if (candles[i] == maxHeight) {
      candleCount++;
    }
  }

  return candleCount;
}

TEST_CASE("birthday_cake_candles", "[problem_solving][easy]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  string candles_count_temp;
  getline(cin, candles_count_temp);

  int candles_count = stoi(ltrim(rtrim(candles_count_temp)));

  string candles_temp_temp;
  getline(cin, candles_temp_temp);

  vector<string> candles_temp = split(rtrim(candles_temp_temp));

  vector<int> candles(candles_count);

  for (int i = 0; i < candles_count; i++) {
    int candles_item = stoi(candles_temp[i]);

    candles[i] = candles_item;
  }

  int result = birthdayCakeCandles(candles);

  fout << result << "\n";

  fout.close();
}
