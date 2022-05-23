// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/organizing-containers-of-balls/problem
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
 * Complete the 'organizingContainers' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts 2D_INTEGER_ARRAY container as parameter.
 */

string organizingContainers(const vector<vector<int>>& container) {
  vector<int32_t> containerSizes(container.size());
  vector<int32_t> balls(container.size(), 0);

  for (size_t containerIndex = 0; containerIndex < container.size(); ++containerIndex) {
    const vector<int>& currentBalls = container[containerIndex];

    for (size_t ballIndex = 0; ballIndex < currentBalls.size(); ++ballIndex) {
      balls[ballIndex] += currentBalls[ballIndex];
      containerSizes[containerIndex] += currentBalls[ballIndex];
    }
  }

  std::sort(containerSizes.begin(), containerSizes.end());
  std::sort(balls.begin(), balls.end());

  return (containerSizes == balls) ? "Possible" : "Impossible";
}

TEST_CASE("organizing_containers_of_balls", "[problem_solving][medium]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  string q_temp;
  getline(cin, q_temp);

  int q = stoi(ltrim(rtrim(q_temp)));

  for (int q_itr = 0; q_itr < q; q_itr++) {
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<vector<int>> container(n);

    for (int i = 0; i < n; i++) {
      container[i].resize(n);

      string container_row_temp_temp;
      getline(cin, container_row_temp_temp);

      vector<string> container_row_temp = split(rtrim(container_row_temp_temp));

      for (int j = 0; j < n; j++) {
        int container_row_item = stoi(container_row_temp[j]);

        container[i][j] = container_row_item;
      }
    }

    string result = organizingContainers(container);

    fout << result << "\n";
  }

  fout.close();
}
