// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank:
// https://www.hackerrank.com/challenges/binary-search-tree-lowest-common-ancestor/problem
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

  Node* lca(Node* root, const int v1, const int v2) {
    // Write your code here.
    if (!root) {
      return nullptr;
    }

    if ((root->data == v1) || (root->data == v2)) {
      return root;
    }

    Node* next_node1 = ((v1 < root->data) ? root->left : root->right);
    Node* next_node2 = ((v2 < root->data) ? root->left : root->right);
    if (next_node1 != next_node2) {
      return root;
    }

    return lca(next_node1, v1, v2);
  }

};  // End of Solution

TEST_CASE("lowest_common_ancestor", "[interview_prep_kit][tree][easy]") {
  Solution myTree;
  Node* root = NULL;

  int t;
  int data;

  cin >> t;

  while (t-- > 0) {
    cin >> data;
    root = myTree.insert(root, data);
  }

  int v1, v2;
  cin >> v1 >> v2;

  Node* ans = myTree.lca(root, v1, v2);

  cout << ans->data << endl;
}
