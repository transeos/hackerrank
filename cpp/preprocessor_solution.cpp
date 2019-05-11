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

#define toStr(x) "x"
#define io(x) cin >> x
#define INF 100000000
#define FUNCTION(a, b) a b 1

#include <iostream>
#include <vector>

#include <catch2/catch.hpp>

#if !defined toStr || !defined io || !defined FUNCTION || !defined INF
#error Missing preprocessor definitions
#endif

/*
FUNCTION(minimum, <)
FUNCTION(maximum, >)*/

using namespace std;

TEST_CASE("preprocessor_solution", "[cpp][easy][incomplete]") {
  /*
  int n; cin >> n;
        vector<int> v(n);
        foreach(v, i) {
                io(v)[i];
        }
        int mn = INF;
        int mx = -INF;
        foreach(v, i) {
                minimum(mn, v[i]);
                maximum(mx, v[i]);
        }
        int ans = mx - mn;
        cout << toStr(Result =) <<' '<< ans;*/
}
