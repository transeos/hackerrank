// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/cpp-sets/problem
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

TEST_CASE("sets", "[cpp][easy]") {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */

  set<int> nums;

  int num_queries = 0;
  cin >> num_queries;

  for (int idx = 0; idx < num_queries; ++idx) {
    int num = 0, query_type = 0;

    cin >> query_type >> num;

    switch (query_type) {
      case 1:
        nums.insert(num);
        break;
      case 2:
        nums.erase(num);
        break;
      case 3:
        cout << ((nums.find(num) != nums.end()) ? "Yes" : "No") << endl;
        break;
      default:
        assert(0);
    }
  }
}
