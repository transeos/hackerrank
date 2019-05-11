// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/c-tutorial-stringstream/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 12/05/19.
//
//*****************************************************************

#include <cassert>
#include <iostream>
#include <sstream>
#include <vector>

#include <catch2/catch.hpp>

using namespace std;

vector<int> parseInts(string str) {
  // Complete this function
  vector<int> nums;

  int num = -1;
  char ch = '\0';

  stringstream ss(str);

  // get first number
  ss >> num;
  nums.push_back(num);

  while (ss >> ch >> num) {
    assert(ch == ',');
    nums.push_back(num);
  }

  return nums;
}

TEST_CASE("stringstream", "[cpp][easy]") {
  string str;
  cin >> str;
  vector<int> integers = parseInts(str);
  for (int i = 0; i < integers.size(); i++) {
    cout << integers[i] << "\n";
  }
}
