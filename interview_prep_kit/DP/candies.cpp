// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/candies/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 03/01/21.
//
//*****************************************************************

#include "utils.h"
#include <bits/stdc++.h>
#include <catch2/catch.hpp>
#include <iostream>

using namespace std;

class CandiNode {
 public:
  CandiNode(const int index, const int val) : index_(index), val_(val), num_candies_(0) {}
  ~CandiNode() {}

  int GetIndex() const {
    return index_;
  }
  int GetVal() const {
    return val_;
  }

  int GetNumCandies() const {
    return num_candies_;
  }
  void SetNumCandies(const int num_candies) {
    num_candies_ = num_candies;
  }

  bool operator<(const CandiNode& rhs) const {
    if (val_ < rhs.val_) {
      return true;
    } else if (val_ == rhs.val_) {
      return index_ < rhs.index_;
    } else
      return false;
  }

  bool ProcessAdjacentNode(CandiNode& adjacent_node) {
    if (adjacent_node.GetNumCandies() == 0) {
      if (adjacent_node.GetVal() <= GetVal()) {
        return false;
      }

      adjacent_node.SetNumCandies(GetNumCandies() + 1);
      // cout << adjacent_node << endl;
      return true;
    }

    if ((adjacent_node.GetVal() > GetVal()) && (adjacent_node.GetNumCandies() <= GetNumCandies())) {
      // increase candies
      adjacent_node.SetNumCandies(GetNumCandies() + 1);
      // cout << adjacent_node << endl;
    }
    return false;
  }

  friend ostream& operator<<(ostream& out, const CandiNode& node) {
    out << node.GetIndex() << "," << node.GetVal() << " : " << node.GetNumCandies();
    return out;
  }

 private:
  int index_;
  int val_;

  int num_candies_;
};

// Complete the candies function below.
long candies(const int n, const vector<int>& arr) {
  vector<CandiNode> candi_nodes;
  vector<int> node_index_map(n);

  for (size_t idx = 0; idx < n; ++idx) {
    candi_nodes.emplace_back(idx, arr[idx]);
  }

  sort(candi_nodes.begin(), candi_nodes.end());

  // update index map
  for (size_t idx = 0; idx < n; ++idx) {
    node_index_map[candi_nodes[idx].GetIndex()] = idx;
  }

  for (auto& candi_node : candi_nodes) {
    if (candi_node.GetNumCandies() > 0) {
      // already visited
      continue;
    }

    candi_node.SetNumCandies(1);
    // cout << candi_node << endl;

    // visit left nodes
    int prev_candi_index = node_index_map[candi_node.GetIndex()];
    for (int idx = (candi_node.GetIndex() - 1); idx >= 0; --idx) {
      CandiNode& left_candi_node = candi_nodes[node_index_map[idx]];
      CandiNode& prev_candi_node = candi_nodes[prev_candi_index];

      if (prev_candi_node.ProcessAdjacentNode(left_candi_node)) {
        prev_candi_index = node_index_map[idx];
      } else {
        break;
      }
    }

    // visit right nodes
    prev_candi_index = node_index_map[candi_node.GetIndex()];
    for (int idx = (candi_node.GetIndex() + 1); idx < n; ++idx) {
      CandiNode& right_candi_node = candi_nodes[node_index_map[idx]];
      CandiNode& prev_candi_node = candi_nodes[prev_candi_index];

      if (prev_candi_node.ProcessAdjacentNode(right_candi_node)) {
        prev_candi_index = node_index_map[idx];
      } else {
        break;
      }
    }
  }

  long num_candies = 0;
  for (auto& candi_node : candi_nodes) {
    num_candies += (long)candi_node.GetNumCandies();
  }

  return num_candies;
}

TEST_CASE("candies", "[interview_prep_kit][DP][medium]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  int n;
  cin >> n;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  vector<int> arr(n);

  for (int i = 0; i < n; i++) {
    int arr_item;
    cin >> arr_item;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    arr[i] = arr_item;
  }

  long result = candies(n, arr);

  fout << result << "\n";

  fout.close();
}
