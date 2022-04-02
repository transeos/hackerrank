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
#include <catch2/catch.hpp>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

TEST_CASE("maps", "[cpp][easy]") {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */

  map<string, int32_t> data;

  uint32_t numQueries = 0;
  cin >> numQueries;

  for (size_t i = 0; i < numQueries; ++i) {
    uint32_t query;
    string name;
    uint32_t marks;

    cin >> query >> name;

    switch (query) {
      case 1:
        cin >> marks;
        if (auto iter2 = data.try_emplace(name, marks); !iter2.second) {
          iter2.first->second += marks;
        }
        break;
      case 2:
        data.erase(name);
        break;
      case 3:
        if (auto iter = data.find(name); iter != data.end()) {
          cout << iter->second;
        } else {
          cout << 0;
        }
        cout << endl;
        break;
      default:
        assert(0);
    }
  }
}
