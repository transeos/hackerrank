// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/maximum-xor/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 29/12/19.
//
//*****************************************************************

#include "utils.h"
#include <bits/stdc++.h>
#include <catch2/catch.hpp>
#include <iostream>

using namespace std;

class ElementTreeNode {
 public:
  ElementTreeNode(const int n) : depth_(n), val_(-1) {}
  ~ElementTreeNode() {}

  void Add(const int num) {
    Add(num, num);
  }

  int GetDepth() const {
    return depth_;
  }

  void PrintTree(const string& space = "") const {
    if (left_child_) {
      if (left_child_->depth_ > 0) {
        left_child_->PrintTree(space + " ");
      } else {
        cout << space << left_child_->val_ << endl;
      }
    }

    if (right_child_) {
      if (right_child_->depth_ > 0) {
        right_child_->PrintTree(space);
      } else {
        cout << space << right_child_->val_ << endl;
      }
    }
  }

  int FindMaxXorElement(int num) {
    int ret_val = 0;

    auto child = ((num & (1 << (depth_ - 1))) ? left_child_ : right_child_);
    if (child) {
      ret_val += (1 << (depth_ - 1));
    } else {
      child = (left_child_ ? left_child_ : right_child_);
    }

    if (depth_ > 1) {
      ret_val += child->FindMaxXorElement(num & ((1 << depth_) - 1));
    } else {
      // cout << child->val_;
    }

    return ret_val;
  }

 private:
  shared_ptr<ElementTreeNode> left_child_;
  shared_ptr<ElementTreeNode> right_child_;

  int depth_;

  int val_;

  void Add(const int num, const int orig_num) {
    if (depth_ > 0) {
      shared_ptr<ElementTreeNode>& child =
          ((num & (1 << (depth_ - 1))) ? right_child_ : left_child_);
      if (!child) {
        child = make_shared<ElementTreeNode>(depth_ - 1);
      }

      child->Add(num & ((1 << depth_) - 1), orig_num);
    } else {
      if (val_ == -1) {
        val_ = orig_num;
      } else {
        assert(val_ == orig_num);
      }
    }
  }
};

// Complete the maxXor function below.
vector<int> maxXor(const vector<int>& arr, const vector<int>& queries) {
  // solve here

  // root node
  ElementTreeNode root(30);

  // form binary tree
  for (int num : arr) {
    root.Add(num);
  }

  // root.PrintTree();

  vector<int> max_xor;  //(queries.size(), 0);

  for (int query : queries) {
    // cout << query << " ^ ";
    max_xor.push_back(root.FindMaxXorElement(query));
    // cout << " = " << max_xor.back() << endl;
  }

  return max_xor;
}

TEST_CASE("maximum_xor", "[interview_prep_kit][miscellaneous][medium][star]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  int n;
  cin >> n;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  string arr_temp_temp;
  getline(cin, arr_temp_temp);

  vector<string> arr_temp = split_string(arr_temp_temp);

  vector<int> arr(n);

  for (int i = 0; i < n; i++) {
    int arr_item = stoi(arr_temp[i]);

    arr[i] = arr_item;
  }

  int m;
  cin >> m;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  vector<int> queries(m);

  for (int i = 0; i < m; i++) {
    int queries_item;
    cin >> queries_item;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    queries[i] = queries_item;
  }

  vector<int> result = maxXor(arr, queries);

  for (int i = 0; i < result.size(); i++) {
    fout << result[i];

    if (i != result.size() - 1) {
      fout << "\n";
    }
  }

  fout << "\n";

  fout.close();
}
