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

#include <catch2/catch.hpp>
#include <iostream>

using namespace std;

// Enter your code for reversed_binary_value<bool...>()
template <bool b, bool... digits>
int reversed_binary_value() {
  int result = 0;
  if constexpr (sizeof...(digits)) {
    result = reversed_binary_value<digits...>();
  }
  result = (result * 2) + b;

  return result;
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
