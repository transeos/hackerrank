// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/cpp-variadics/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 12/05/19.
//
//*****************************************************************

#include <iostream>

#include <catch2/catch.hpp>

using namespace std;

// Enter your code for reversed_binary_value<bool...>()

template <bool b = false>
int reversed_binary_value() {
  return b;
}

template <bool b1, bool b2, bool... digits>
int reversed_binary_value() {
  static_assert(sizeof...(digits) < 5);
  const int z = ((b1 << (4 - sizeof...(digits))) + (b2 << (5 - sizeof...(digits))) +
                 reversed_binary_value<digits...>());
  return z;
}

template <int n, bool... digits>
struct CheckValues {
  static void check(int x, int y) {
    CheckValues<n - 1, 0, digits...>::check(x, y);
    CheckValues<n - 1, 1, digits...>::check(x, y);
  }
};

template <bool... digits>
struct CheckValues<0, digits...> {
  static void check(int x, int y) {
    int z = reversed_binary_value<digits...>();
    std::cout << (z + 64 * y == x);
  }
};

TEST_CASE("variadics", "[cpp][hard]") {
  int t;
  std::cin >> t;

  for (int i = 0; i != t; ++i) {
    int x, y;
    cin >> x >> y;
    CheckValues<6>::check(x, y);
    cout << "\n";
  }
}
