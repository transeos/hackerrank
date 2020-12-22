// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/ctci-is-binary-search-tree/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 22/12/19.
//
//*****************************************************************

#include "utils.h"
#include <bits/stdc++.h>
#include <catch2/catch.hpp>
#include <iostream>

#define MAX_INT 2147483647
#define MIN_INT -2147483648

using namespace std;

/* Hidden stub code will pass a root argument to the function below. Complete the function to solve
the challenge. Hint: you may want to write one or more helper functions.

The Node struct is defined as follows: */
struct Node {
  int data;
  Node* left;
  Node* right;
};

bool checkBST(const Node* root, int max_val = MAX_INT, int min_val = MIN_INT) {
  if ((max_val == MAX_INT) && (min_val == MIN_INT)) {
    // root node
    if (!root) {
      return false;
    }
  }

  if (root->left) {
    if ((root->left->data >= root->data) || (root->left->data <= min_val)) {
      return false;
    }

    if (!checkBST(root->left, root->data, min_val)) {
      return false;
    }
  }

  if (root->right) {
    if ((root->right->data <= root->data) || (root->right->data >= max_val)) {
      return false;
    }
    return checkBST(root->right, max_val, root->data);
  }

  return true;
}

TEST_CASE("is_BST", "[interview_prep_kit][tree][medium]") {
  checkBST(nullptr);
}
