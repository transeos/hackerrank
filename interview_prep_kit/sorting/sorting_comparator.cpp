// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/ctci-comparator-sorting/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 26/05/19.
//
//*****************************************************************

#include <algorithm>
#include <catch2/catch.hpp>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

struct Player {
  int score;
  string name;
};

#include <string.h>

class Checker {
 public:
  // complete this method
  static int comparator(Player a, Player b) {
    if (a.score < b.score) {
      return -1;
    }

    if (a.score > b.score) {
      return 1;
    }

    const int str_comp_output = strcmp(a.name.c_str(), b.name.c_str());
    if (str_comp_output == 0) return 0;

    return ((str_comp_output > 0) ? -1 : 1);
  }
};

bool compare(Player a, Player b) {
  if (Checker::comparator(a, b) == -1) return false;
  return true;
}

TEST_CASE("sorting_comparator", "[interview_prep_kit][sorting][medium]") {
  int n;
  cin >> n;
  vector<Player> players;
  string name;
  int score;
  for (int i = 0; i < n; i++) {
    cin >> name >> score;
    Player player;
    player.name = name, player.score = score;
    players.push_back(player);
  }
  sort(players.begin(), players.end(), compare);
  for (int i = 0; i < players.size(); i++) {
    cout << players[i].name << " " << players[i].score << endl;
  }
}
