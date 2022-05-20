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
 private:
  int32_t _depth;
  int32_t _data;

  int32_t _left;
  int32_t _right;

 public:
  TreeNode() : _data(0), _depth(0), _left(-1), _right(-1) {}

  void SetDepth(int32_t depth) {
    assert(_depth == 0);
    _depth = depth;
  }
  int32_t GetDepth() const {
    return _depth;
  }

  void SetData(int32_t data) {
    assert(_data == 0);
    _data = data;
  }

  void SetLeft(int32_t left) {
    assert(_left == -1);
    _left = left;
  }
  void SetRight(int32_t right) {
    assert(_right == -1);
    _right = right;
  }

  void PrintTree(const vector<TreeNode>& nodes, vector<int>& result) const {
    if (_left != -1) {
      nodes[_left].PrintTree(nodes, result);
    }

    result.push_back(_data);

    if (_right != -1) {
      nodes[_right].PrintTree(nodes, result);
    }
  }

  void SwapNodes(vector<TreeNode>& nodes, const int32_t depthMultiplier) {
    if (_depth % depthMultiplier == 0) {
      std::swap(_left, _right);
    }

    if (_left != -1) {
      nodes[_left].SwapNodes(nodes, depthMultiplier);
    }

    if (_right != -1) {
      nodes[_right].SwapNodes(nodes, depthMultiplier);
    }
  }
};

/*
 * Complete the swapNodes function below.
 */
vector<vector<int>> swapNodes(const vector<vector<int>>& indexes, const vector<int>& queries) {
  /*
   * Write your code here.
   */

  vector<vector<int>> result(queries.size());

  vector<TreeNode> nodes(indexes.size());
  for (size_t i = 0; i < nodes.size(); ++i) {
    nodes[i].SetData(i + 1);
  }

  nodes[0].SetDepth(1);

  for (size_t i = 0; i < indexes.size(); ++i) {
    const int32_t leftChildIndex = indexes[i][0] - 1;
    if (leftChildIndex != -2) {
      nodes[i].SetLeft(leftChildIndex);
      nodes[leftChildIndex].SetDepth(nodes[i].GetDepth() + 1);
    }

    const int32_t rightChildIndex = indexes[i][1] - 1;
    if (rightChildIndex != -2) {
      nodes[i].SetRight(rightChildIndex);
      nodes[rightChildIndex].SetDepth(nodes[i].GetDepth() + 1);
    }
  }

  for (size_t i = 0; i < queries.size(); ++i) {
    nodes[0].SwapNodes(nodes, queries[i]);
    nodes[0].PrintTree(nodes, result[i]);
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
