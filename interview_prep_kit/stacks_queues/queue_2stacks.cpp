// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/ctci-queue-using-two-stacks/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 23/12/19.
//
//*****************************************************************

#include "utils.h"
#include <bits/stdc++.h>
#include <catch2/catch.hpp>
#include <iostream>

using namespace std;

class MyQueue {
 private:
  std::stack<int> _newestOnTop;
  std::stack<int> _oldestOnTop;

  void PopulateOldestOnTopStack() {
    while (!_newestOnTop.empty()) {
      _oldestOnTop.push(_newestOnTop.top());
      _newestOnTop.pop();
    }
  }

 public:
  void push(const int x) {
    _newestOnTop.push(x);
  }

  void pop() {
    if (_oldestOnTop.empty()) {
      PopulateOldestOnTopStack();
    }

    if (!_oldestOnTop.empty()) {
      _oldestOnTop.pop();
    }
  }

  int front() {
    if (_oldestOnTop.empty()) {
      PopulateOldestOnTopStack();
    }

    if (!_oldestOnTop.empty()) {
      return _oldestOnTop.top();
    } else {
      return -1;
    }
  }
};

TEST_CASE("queue_2stacks", "[interview_prep_kit][stacks_queues][medium]") {
  MyQueue q1;
  int q, type, x;
  cin >> q;

  for (int i = 0; i < q; i++) {
    cin >> type;
    if (type == 1) {
      cin >> x;
      q1.push(x);
    } else if (type == 2) {
      q1.pop();
    } else
      cout << q1.front() << endl;
  }
}
