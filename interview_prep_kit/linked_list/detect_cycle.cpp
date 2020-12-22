// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/ctci-linked-list-cycle/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 21/12/19.
//
//*****************************************************************

#include "utils.h"
#include <bits/stdc++.h>
#include <catch2/catch.hpp>
#include <iostream>

using namespace std;

// A Node is defined as:
struct Node {
  int data;
  struct Node* next;
};

/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.
*/
bool has_cycle(const Node* head) {
  // Complete this function
  // Do not write the main method

  unordered_set<const Node*> nodes;

  const Node* cur_node = head;

  while (cur_node) {
    if (nodes.find(cur_node) != nodes.end()) {
      return true;
    }

    nodes.insert(cur_node);
    cur_node = cur_node->next;
  }

  return false;
}

TEST_CASE("detect_cycle", "[interview_prep_kit][linked_list][easy]") {
  has_cycle(nullptr);
}
