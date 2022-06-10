// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/zig-zag-sequence/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 24/05/22.
//
//*****************************************************************

#include "utils.h"
#include <bits/stdc++.h>
#include <catch2/catch.hpp>

using std::cin;
using std::cout;
using std::endl;
using std::ofstream;
using std::string;
using std::swap;
using std::vector;

void findZigZagSequence(vector<int>& a, const int32_t n) {
  sort(a.begin(), a.end());
  int mid = n / 2;
  swap(a[mid], a[n - 1]);

  int st = mid + 1;
  int ed = n - 2;
  while (st < ed) {
    swap(a[st], a[ed]);
    st = st + 1;
    ed = ed - 1;
  }
  for (int i = 0; i < n; i++) {
    if (i > 0) cout << " ";
    cout << a[i];
  }
  cout << endl;
}

TEST_CASE("zig_zag_sequence", "[problem_solving][medium][ToDo]") {
  int n, x;
  int test_cases;
  cin >> test_cases;

  for (int cs = 1; cs <= test_cases; cs++) {
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++) {
      cin >> x;
      a.push_back(x);
    }
    findZigZagSequence(a, n);
  }
}
