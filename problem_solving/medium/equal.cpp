// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/equal/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 30/05/22.
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
 * Complete the 'equal' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

int32_t equal(const vector<int32_t>& arr) {
  int32_t maxVal = arr[0];
  for (size_t i = 1; i < arr.size(); ++i) {
    maxVal = std::max(maxVal, arr[i]);
  }

  auto getIncrements = [](const int32_t curVal,
                          const int32_t targetVal) -> std::tuple<int32_t, int32_t, int32_t> {
    // 1, 2, 5 count
    std::tuple<int32_t, int32_t, int32_t> result(0, 0, 0);

    const int32_t diff = targetVal - curVal;

    std::get<2>(result) = diff / 5;

    switch (diff % 5) {
      case 1:
      case 2:
        std::get<0>(result) = 1;
        break;
      case 3:
      case 4:
        std::get<1>(result) = 1;
        break;
    }

    return result;
  };

  std::array<std::tuple<int32_t, int32_t, int32_t>, 5> numRounds;
  std::for_each(numRounds.begin(), numRounds.end(), [](auto& round) {
    std::get<0>(round) = 0;
    std::get<1>(round) = 0;
    std::get<2>(round) = 0;
  });

  for (const int32_t num : arr) {
    for (size_t i = 0; i < 5; ++i) {
      auto round = getIncrements(num, maxVal + i);
      auto& maxRound = numRounds[i];
      std::get<0>(maxRound) = std::max(std::get<0>(maxRound), std::get<0>(round));
      std::get<1>(maxRound) = std::max(std::get<1>(maxRound), std::get<1>(round));
      std::get<2>(maxRound) = std::max(std::get<2>(maxRound), std::get<2>(round));
    }
  }

  int32_t numRoundCount = std::numeric_limits<int32_t>::max();
  std::for_each(numRounds.begin(), numRounds.end(), [&numRoundCount](auto& round) {
    numRoundCount =
        std::min(numRoundCount, std::get<0>(round) + std::get<1>(round) + std::get<2>(round));
  });
  return numRoundCount;
}

TEST_CASE("equal", "[problem_solving][medium][ToDo]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  string t_temp;
  getline(cin, t_temp);

  int t = stoi(ltrim(rtrim(t_temp)));

  for (int t_itr = 0; t_itr < t; t_itr++) {
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
      int arr_item = stoi(arr_temp[i]);

      arr[i] = arr_item;
    }

    int result = equal(arr);

    fout << result << "\n";
  }

  fout.close();
}
