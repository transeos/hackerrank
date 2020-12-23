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

/*
class MyQueue {
public:
  MyQueue() { }
  ~MyQueue() { }

  void push(const int x) {
    TransferFromOldToNew();

    stack_newest_on_top.push(x);
  }

  void pop() {
    TransferFromNewToOld();

    stack_oldest_on_top.pop();
  }

  int front() {
    TransferFromNewToOld();

    return stack_oldest_on_top.top();
  }

private:
  stack<int> stack_newest_on_top;
  stack<int> stack_oldest_on_top;

  inline void TransferFromNewToOld() {
    while (!stack_newest_on_top.empty()) {
      stack_oldest_on_top.push(stack_newest_on_top.top());
      stack_newest_on_top.pop();
    }
  }

  inline void TransferFromOldToNew() {
    while (!stack_oldest_on_top.empty()) {
      stack_newest_on_top.push(stack_oldest_on_top.top());
      stack_oldest_on_top.pop();
    }
  }
};*/

typedef queue<int> MyQueue;

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
