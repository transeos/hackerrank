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

#include <catch2/catch.hpp>
#include <iomanip>
#include <iostream>
#include <sstream>

using namespace std;

TEST_CASE("print_pretty", "[cpp][easy]") {
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

    printf("0x%lx\n", (int64_t)A);

    int int_B = B;
    int num_digits = 2;
    while (int_B > 0) {
      num_digits++;
      int_B /= 10;
    }

    for (size_t idx = (num_digits + 2); idx < 15; ++idx) {
      printf("%c", '_');
    }
    printf("%c", ((B > 0) ? '+' : '-'));

    stringstream ss_B;
    ss_B << std::setprecision(num_digits) << B;

    // cout creates extra padding
    printf("%s", ss_B.str().c_str());

    const int numB_length = ss_B.str().length();
    if (numB_length == (num_digits + 1)) {
      // 2 decimal points
      printf("\n");
    } else if (numB_length == num_digits) {
      // 1 decimal point
      printf("0\n");
    } else if (numB_length == (num_digits - 2)) {
      // no decimal point
      printf(".00\n");
    } else {
      printf("ERROR\n");
      exit(1);
    }

    int num_precision = 10;
    if (C < 0) {
      num_precision--;
      C *= (-1);
    }

    int exp = 0;
    while (C > 10) {
      exp++;
      C /= 10;
    }
    while (C < 1) {
      exp--;
      C *= 10;
    }

    stringstream ss_C;
    ss_C << std::setprecision(num_precision) << C;

    // cout creates extra padding
    printf("%s%s", ((num_precision == 10) ? "" : "-"), ss_C.str().c_str());

    for (size_t idx = ss_C.str().length(); idx < (num_precision + 1); ++idx) {
      printf("0");
    }

    printf("E%c%s%d\n", ((exp >= 0) ? '+' : '-'), ((exp < 10) ? "0" : ""), abs(exp));
  }
}
