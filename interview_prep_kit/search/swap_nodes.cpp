// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/swap-nodes-algo/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 20/12/20.
//
//*****************************************************************

#include <bits/stdc++.h>
#include <catch2/catch.hpp>
#include <iostream>

using namespace std;

class TreeNode {
 public:
  TreeNode(int value, int depth) : val_(value), depth_(depth) {}
  ~TreeNode() {}

  int GetValue() const {
    return val_;
  }
  int GetDepth() const {
    return depth_;
  }

  shared_ptr<TreeNode>& GetLeftChild() {
    return left_child_;
  }
  shared_ptr<TreeNode>& GetRightChild() {
    return right_child_;
  }

  void SetLeftChild(shared_ptr<TreeNode>& node) {
    left_child_ = node;
  }
  void SetRightChild(shared_ptr<TreeNode>& node) {
    right_child_ = node;
  }

  void GetTree(vector<int>& arr) const {
    if (left_child_) {
      left_child_->GetTree(arr);
    }

    arr.push_back(val_);

    if (right_child_) {
      right_child_->GetTree(arr);
    }
  }

  void Swap(const int target_depth) {
    if ((depth_ % target_depth) == 0) {
      shared_ptr<TreeNode> temp = left_child_;
      left_child_ = right_child_;
      right_child_ = temp;
    }
    if (left_child_) {
      left_child_->Swap(target_depth);
    }
    if (right_child_) {
      right_child_->Swap(target_depth);
    }
  }

 private:
  int val_;

  shared_ptr<TreeNode> left_child_;
  shared_ptr<TreeNode> right_child_;

  int depth_;
};

/*
 * Complete the swapNodes function below.
 */
vector<vector<int>> swapNodes(const vector<vector<int>>& indexes, const vector<int>& queries) {
  /*
   * Write your code here.
   */

  vector<vector<int>> result;

  // create root node
  auto root = make_shared<TreeNode>(1, 1);

  deque<shared_ptr<TreeNode>> nodes;
  nodes.push_back(root);

  for (size_t row_idx = 0; row_idx < indexes.size(); ++row_idx) {
    shared_ptr<TreeNode> cur_node = nodes.front();
    nodes.pop_front();
    assert(cur_node);

    const int left_child_val = indexes[row_idx][0];
    if (left_child_val != -1) {
      auto left_child = make_shared<TreeNode>(left_child_val, (cur_node->GetDepth() + 1));
      cur_node->SetLeftChild(left_child);
      nodes.push_back(left_child);
    }

    const int right_child_val = indexes[row_idx][1];
    if (right_child_val != -1) {
      auto right_child = make_shared<TreeNode>(right_child_val, (cur_node->GetDepth() + 1));
      cur_node->SetRightChild(right_child);
      nodes.push_back(right_child);
    }
  }

  result.resize(queries.size());
  for (size_t idx = 0; idx < queries.size(); ++idx) {
    root->Swap(queries[idx]);
    root->GetTree(result[idx]);
  }

  return result;
}

TEST_CASE("swap_nodes", "[interview_prep_kit][search][medium]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  int n;
  cin >> n;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  vector<vector<int>> indexes(n);
  for (int indexes_row_itr = 0; indexes_row_itr < n; indexes_row_itr++) {
    indexes[indexes_row_itr].resize(2);

    for (int indexes_column_itr = 0; indexes_column_itr < 2; indexes_column_itr++) {
      cin >> indexes[indexes_row_itr][indexes_column_itr];
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }

  int queries_count;
  cin >> queries_count;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  vector<int> queries(queries_count);

  for (int queries_itr = 0; queries_itr < queries_count; queries_itr++) {
    int queries_item;
    cin >> queries_item;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    queries[queries_itr] = queries_item;
  }

  vector<vector<int>> result = swapNodes(indexes, queries);

  for (int result_row_itr = 0; result_row_itr < result.size(); result_row_itr++) {
    for (int result_column_itr = 0; result_column_itr < result[result_row_itr].size();
         result_column_itr++) {
      fout << result[result_row_itr][result_column_itr];

      if (result_column_itr != result[result_row_itr].size() - 1) {
        fout << " ";
      }
    }

    if (result_row_itr != result.size() - 1) {
      fout << "\n";
    }
  }

  fout << "\n";

  fout.close();
}
