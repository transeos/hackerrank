// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/c-tutorial-strings/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 12/05/19.
//
//*****************************************************************

#include <iostream>
#include <string>

#include <catch2/catch.hpp>

using namespace std;

TEST_CASE("strings", "[cpp][easy]") {
  // Complete the program

  string str1, str2;

  cin >> str1;
  cin >> str2;

  cout << str1.size() << " " << str2.size() << endl;
  cout << (str1 + str2) << endl;
  cout << str2[0] << str1.substr(1) << " " << str1[0] << str2.substr(1) << endl;
}
