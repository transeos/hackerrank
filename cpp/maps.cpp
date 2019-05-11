// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/cpp-maps/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 12/05/19.
//
//*****************************************************************

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <vector>

#include <catch2/catch.hpp>

using namespace std;

TEST_CASE("maps", "[cpp][easy]") {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */

  map<string, int> marks_map;

  int num_queries = 0;
  cin >> num_queries;

  for (int idx = 0; idx < num_queries; ++idx) {
    int query_type = 0, marks = 0;
    string name;

    cin >> query_type >> name;
    map<string, int>::iterator marks_iter = marks_map.find(name);

    switch (query_type) {
      case 1:
        cin >> marks;
        if (marks_iter == marks_map.end()) {
          marks_map[name] = marks;
        } else {
          marks_iter->second += marks;
        }
        break;
      case 2:
        if (marks_iter != marks_map.end()) {
          marks_map.erase(marks_iter);
        }
        break;
      case 3:
        cout << ((marks_iter != marks_map.end()) ? marks_iter->second : 0) << endl;
        break;
      default:
        assert(0);
    }
  }
}
