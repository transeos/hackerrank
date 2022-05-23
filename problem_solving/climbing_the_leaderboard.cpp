// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem
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
 * Complete the 'climbingLeaderboard' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY ranked
 *  2. INTEGER_ARRAY player
 */

vector<int> climbingLeaderboard(const vector<int>& ranked, const vector<int>& player) {
  vector<int> result(player.size());

  vector<int> leaderBoard(ranked.size());
  leaderBoard[0] = ranked.back();
  size_t numPopupatedRanks = 1;

  for (int64_t i = ranked.size() - 2; i >= 0; --i) {
    if (ranked[i] != leaderBoard[numPopupatedRanks - 1]) {
      leaderBoard[numPopupatedRanks] = ranked[i];
      numPopupatedRanks++;
    }
  }
  leaderBoard.resize(numPopupatedRanks);

  auto leaderBoardBegin = leaderBoard.begin();

  for (size_t i = 0; i < player.size(); ++i) {
    const int currentScore = player[i];
    leaderBoardBegin = std::lower_bound(leaderBoardBegin, leaderBoard.end(), currentScore);

    if (leaderBoardBegin == leaderBoard.end()) {
      for (size_t j = i; j < player.size(); ++j) {
        result[j] = 1;
      }
      return result;
    }

    if (*leaderBoardBegin == currentScore) {
      result[i] = std::distance(leaderBoardBegin, leaderBoard.end());
    } else if (leaderBoardBegin == leaderBoard.begin()) {
      result[i] = leaderBoard.size() + 1;
    } else {
      result[i] = std::distance(leaderBoardBegin, leaderBoard.end()) + 1;
    }
  }

  return result;
}

TEST_CASE("climbing_the_leaderboard", "[problem_solving][medium]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  string ranked_count_temp;
  getline(cin, ranked_count_temp);

  int ranked_count = stoi(ltrim(rtrim(ranked_count_temp)));

  string ranked_temp_temp;
  getline(cin, ranked_temp_temp);

  vector<string> ranked_temp = split(rtrim(ranked_temp_temp));

  vector<int> ranked(ranked_count);

  for (int i = 0; i < ranked_count; i++) {
    int ranked_item = stoi(ranked_temp[i]);

    ranked[i] = ranked_item;
  }

  string player_count_temp;
  getline(cin, player_count_temp);

  int player_count = stoi(ltrim(rtrim(player_count_temp)));

  string player_temp_temp;
  getline(cin, player_temp_temp);

  vector<string> player_temp = split(rtrim(player_temp_temp));

  vector<int> player(player_count);

  for (int i = 0; i < player_count; i++) {
    int player_item = stoi(player_temp[i]);

    player[i] = player_item;
  }

  vector<int> result = climbingLeaderboard(ranked, player);

  for (size_t i = 0; i < result.size(); i++) {
    fout << result[i];

    if (i != result.size() - 1) {
      fout << "\n";
    }
  }

  fout << "\n";

  fout.close();
}
