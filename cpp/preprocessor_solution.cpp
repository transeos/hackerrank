// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/preprocessor-solution/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 12/05/19.
//
//*****************************************************************

/* Enter your macros here */

#define toStr(x) "Result ="
#define io(x) cin >> x
#define INF 100000000

#define minimum(a, b) \
  {                   \
    if (b < a) a = b; \
  }
#define maximum(a, b) \
  {                   \
    if (b > a) a = b; \
  }

#define foreach(arr, i) for (int i = 0; i < arr.size(); ++i)

#define FUNCTION(a, b)

#include <catch2/catch.hpp>
#include <iostream>
#include <vector>

#if !defined toStr || !defined io || !defined FUNCTION || !defined INF
#error Missing preprocessor definitions
#endif

FUNCTION(minimum, <)
FUNCTION(maximum, >)

using namespace std;

TEST_CASE("preprocessor_solution", "[cpp][easy][star]") {
  int n;
  cin >> n;
  vector<int> v(n);
  foreach (v, i) { io(v)[i]; }
  int mn = INF;
  int mx = -INF;
  foreach (v, i) {
    minimum(mn, v[i]);
    maximum(mx, v[i]);
  }
  int ans = mx - mn;
  cout << toStr(Result =) << ' ' << ans;
}
