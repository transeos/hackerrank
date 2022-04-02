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

#include <catch2/catch.hpp>
#include <iostream>
#include <string>

using namespace std;

TEST_CASE("strings", "[cpp][easy]") {
  // Complete the program

  string str1 = "";
  string str2 = "";
  cin >> str1;
  cin >> str2;

  string_view str1View(str1);
  string_view str2View(str2);

  cout << str1.length() << " " << str2.length() << endl;
  cout << str1 << str2 << endl;
  cout << str2[0] << str1View.substr(1) << " " << str1[0] << str2View.substr(1) << endl;
}
