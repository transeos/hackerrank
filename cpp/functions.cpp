// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/c-tutorial-functions/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 12/05/19.
//
//*****************************************************************

#include <algorithm>
#include <catch2/catch.hpp>
#include <cstdio>
#include <iostream>

using namespace std;

template <typename T0, typename... Ts>
const T0& MaxOf(const T0& t0, const Ts&... ts) {
  if constexpr (sizeof...(ts)) {
    return std::max(t0, MaxOf(ts...));
  } else {
    return t0;
  }
}

TEST_CASE("functions", "[cpp][easy]") {
  int a, b, c, d;
  scanf("%d %d %d %d", &a, &b, &c, &d);
  int ans = MaxOf(a, b, c, d);
  printf("%d\n", ans);
}
