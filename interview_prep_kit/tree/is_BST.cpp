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

using namespace std;

/* Hidden stub code will pass a root argument to the function below. Complete the function to solve
the challenge. Hint: you may want to write one or more helper functions.

The Node struct is defined as follows: */
struct Node {
  int data;
  Node* left;
  Node* right;
};

bool checkBST(Node* root, const int minVal = -1, int maxVal = 10001) {
  if ((root->data >= maxVal) || (root->data <= minVal)) {
    return false;
  }

  if (root->left) {
    if (!checkBST(root->left, minVal, root->data)) {
      return false;
    }
  }

  if (root->right) {
    if (!checkBST(root->right, root->data, maxVal)) {
      return false;
    }
  }

  return true;
}

TEST_CASE("is_BST", "[interview_prep_kit][tree][medium]") {
  checkBST(nullptr);
}
