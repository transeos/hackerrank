// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/friend-circle-queries/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 29/12/19.
//
//*****************************************************************

#include "utils.h"
#include <bits/stdc++.h>
#include <catch2/catch.hpp>
#include <iostream>

using namespace std;

void FindMaxMappedCircleLength(const unordered_map<int, int>& mapped_circles) {
  int max_chain = 0;

  for (auto& iter1 : mapped_circles) {
    int cur_chain = 1;
    auto iter2 = mapped_circles.find(iter1.second);

    while (iter2 != mapped_circles.end()) {
      iter2 = mapped_circles.find(iter2->second);
      cur_chain++;
    }

    max_chain = std::max(cur_chain, max_chain);
  }

  cout << "Max circle chain length = " << max_chain << endl;
}

int GetFinalMappedCircle(const unordered_map<int, int>& mapped_circles, const int circle_idx) {
  int cur_circle_idx = circle_idx;

  auto iter = mapped_circles.find(cur_circle_idx);
  while (iter != mapped_circles.end()) {
    cur_circle_idx = iter->second;
    iter = mapped_circles.find(cur_circle_idx);
  }

  return cur_circle_idx;
}

void PrintCircles(const unordered_map<int, int>& people,
                  const unordered_map<int, int>& mapped_circles) {
  unordered_map<int, vector<int>> circles;

  for (auto& iter : people) {
    const int circle_idx = GetFinalMappedCircle(mapped_circles, iter.second);

    auto circle_iter = circles.find(circle_idx);
    if (circle_iter == circles.end()) {
      circles[circle_idx] = {iter.first};
    } else {
      circle_iter->second.push_back(iter.first);
    }
  }

  for (auto& iter : circles) {
    cout << "Circle " << iter.first << " (" << iter.second.size() << ") : ";

    for (int person : iter.second) {
      cout << person << ",";
    }

    cout << endl;
  }
  cout << endl;
}

// Complete the maxCircle function below.
vector<int> maxCircle(const vector<vector<int>>& queries) {
  vector<int> max_circle_sizes;

  unordered_map<int, int> people;
  vector<int> circle_sizes;
  unordered_map<int, int> mapped_circles;

  for (auto& query : queries) {
    const int person_a = query[0];
    const int person_b = query[1];

    auto iter_a = people.find(person_a);
    auto iter_b = people.find(person_b);

    int cur_circle_idx = -1;

    if ((iter_a == people.end()) && (iter_b == people.end())) {
      // new circle;
      cur_circle_idx = circle_sizes.size();
      people[person_a] = cur_circle_idx;
      people[person_b] = cur_circle_idx;
      circle_sizes.push_back(2);

      if (max_circle_sizes.empty()) {
        max_circle_sizes.push_back(2);

        // PrintCircles(people, mapped_circles);
        continue;
      }
    } else if (iter_a == people.end()) {
      cur_circle_idx = GetFinalMappedCircle(mapped_circles, iter_b->second);

      people[person_a] = cur_circle_idx;
      circle_sizes[cur_circle_idx]++;
    } else if (iter_b == people.end()) {
      cur_circle_idx = GetFinalMappedCircle(mapped_circles, iter_a->second);

      people[person_b] = cur_circle_idx;
      circle_sizes[cur_circle_idx]++;
    } else {
      if (iter_a == iter_b) {
        // both persons are already present in the same circle
        max_circle_sizes.push_back(max_circle_sizes.back());
        continue;
      }

      const int mapped_idx_a = GetFinalMappedCircle(mapped_circles, iter_a->second);
      const int mapped_idx_b = GetFinalMappedCircle(mapped_circles, iter_b->second);

      if (mapped_idx_a == mapped_idx_b) {
        // same circle
        max_circle_sizes.push_back(max_circle_sizes.back());
        continue;
      }

      mapped_circles[mapped_idx_b] = mapped_idx_a;
      circle_sizes[mapped_idx_a] += circle_sizes[mapped_idx_b];
      circle_sizes[mapped_idx_b] = 0;
      cur_circle_idx = mapped_idx_a;

      if (mapped_idx_b != iter_b->second) {
        mapped_circles[iter_b->second] = mapped_idx_a;
      }
    }

    const int max_circle_size = std::max(max_circle_sizes.back(), circle_sizes[cur_circle_idx]);
    max_circle_sizes.push_back(max_circle_size);

    // PrintCircles(people, mapped_circles);
  }

  // FindMaxMappedCircleLength(mapped_circles);

  return max_circle_sizes;
}

TEST_CASE("friend_circle", "[interview_prep_kit][miscellaneous][medium]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  // start
  const chrono::high_resolution_clock::time_point start_time = chrono::high_resolution_clock::now();

  int q;
  cin >> q;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  vector<vector<int>> queries(q);
  for (int i = 0; i < q; i++) {
    queries[i].resize(2);

    for (int j = 0; j < 2; j++) {
      cin >> queries[i][j];
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }

  vector<int> ans = maxCircle(queries);

  for (int i = 0; i < ans.size(); i++) {
    fout << ans[i];

    if (i != ans.size() - 1) {
      fout << "\n";
    }
  }

  fout << "\n";

  fout.close();

  // end
  const chrono::high_resolution_clock::time_point end_time = chrono::high_resolution_clock::now();

  // run time
  const int run_time = chrono::duration_cast<chrono::seconds>(end_time - start_time).count();
  cout << "Time taken : " << run_time << " sec\n";
}
