// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/tree-height-of-a-binary-tree/problem
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

class Node {
 public:
  int data;
  Node* left;
  Node* right;
  Node(int d) {
    data = d;
    left = NULL;
    right = NULL;
  }
};

class Solution {
 public:
  Node* insert(Node* root, int data) {
    if (root == NULL) {
      return new Node(data);
    } else {
      Node* cur;
      if (data <= root->data) {
        cur = insert(root->left, data);
        root->left = cur;
      } else {
        cur = insert(root->right, data);
        root->right = cur;
      }

      return root;
    }
  }

  /*The tree node has data, left child and right child
  class Node {
      int data;
      Node* left;
      Node* right;
  };

  */
  int height(Node* root) {
    // Write your code here.

    if (!root || (!root->left && !root->right)) {
      return 0;
    }

    const int left_subtree_height = (1 + height(root->left));
    const int right_subtree_height = (1 + height(root->right));

    return ((left_subtree_height > right_subtree_height) ? left_subtree_height
                                                         : right_subtree_height);
  }

};  // End of Solution

TEST_CASE("binary_tree_height", "[interview_prep_kit][tree][easy]") {
  Solution myTree;
  Node* root = NULL;

  int t;
  int data;

  cin >> t;

  while (t-- > 0) {
    cin >> data;
    root = myTree.insert(root, data);
  }

  int height = myTree.height(root);
  cout << height;
}
