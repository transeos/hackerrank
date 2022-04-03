// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/cpp-exception-handling/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 12/05/19.
//
//*****************************************************************

#include <catch2/catch.hpp>
#include <iostream>
#include <stdexcept>

using namespace std;

int largest_proper_divisor(int n) {
  if (n == 0) {
    throw invalid_argument("largest proper divisor is not defined for n=0");
  }
  if (n == 1) {
    throw invalid_argument("largest proper divisor is not defined for n=1");
  }
  for (int i = n / 2; i >= 1; --i) {
    if (n % i == 0) {
      return i;
    }
  }
  return -1;  // will never happen
}

void process_input(int n) {
  try {
    int d = largest_proper_divisor(n);
    cout << "result=" << d << endl;
  } catch (const std::invalid_argument& e) {
    cout << e.what() << endl;
  } catch (...) {
  }

  cout << "returning control flow to caller" << endl;
}

TEST_CASE("exception_handling", "[cpp][medium]") {
  int n;
  cin >> n;
  process_input(n);
}
