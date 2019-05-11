// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/prettyprint/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 12/05/19.
//
//*****************************************************************

#include <iomanip>
#include <iostream>

#include <catch2/catch.hpp>

using namespace std;

TEST_CASE("print_pretty", "[cpp][easy][incomplete]") {
  int T;
  cin >> T;
  cout << setiosflags(ios::uppercase);
  cout << setw(0xf) << internal;
  while (T--) {
    double A;
    cin >> A;
    double B;
    cin >> B;
    double C;
    cin >> C;

    /* Enter your code here */

    const int hex_A = A;
    printf("0x%x\n", hex_A);
  }
}
