// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/find-the-nearest-clone/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 27/12/19.
//
//*****************************************************************

#include "utils.h"
#include <bits/stdc++.h>
#include <catch2/catch.hpp>
#include <iostream>

using namespace std;

class ColorNode {
 public:
  ColorNode(const long color, const int d = numeric_limits<int>::max(), const int label = -1)
      : color_(color), distance_(d), visited_label_(label) {}
  ~ColorNode() {}

  long GetColor() const {
    return color_;
  }
  int GetDistance() const {
    return distance_;
  }

  void SetDistance(const int d, const int label) {
    assert(!IsVisited());
    distance_ = d;
  }

  bool IsVisited() const {
    return (visited_label_ != -1);
  }

  int GetVisitedLabel() const {
    return visited_label_;
  }
  void SetVisitedLabel(const int node_idx) {
    assert(visited_label_ == -1);
    visited_label_ = node_idx;
  }

  void AddAdjacentNode(const int node) {
    adjacent_nodes_.push_back(node);
  }
  int AddInQueue(std::function<int(int)> lambda) const {
    int distance = numeric_limits<int>::max();

    for (size_t idx = 0; idx < adjacent_nodes_.size(); ++idx) {
      distance = lambda(idx);
      if (distance < numeric_limits<int>::max()) {
        return distance;
      }
    }

    return distance;
  }

 private:
  long color_;

  int distance_;
  int visited_label_;

  vector<int> adjacent_nodes_;
};

bool MinPriorityColorNodeFn(const ColorNode* lhs, const ColorNode* rhs) {
  // dijkstra

  return (lhs->GetDistance() > rhs->GetDistance());
}

/*
 * For the unweighted graph, <name>:
 *
 * 1. The number of nodes is <name>_nodes.
 * 2. The number of edges is <name>_edges.
 * 3. An edge exists between <name>_from[i] to <name>_to[i].
 *
 */

int findShortest(const int num_graph_nodes, const vector<int>& graph_from,
                 const vector<int>& graph_to, const vector<long>& ids, const int val) {
  // solve here

  vector<ColorNode> nodes;

  priority_queue<ColorNode*, vector<ColorNode*>,
                 std::function<bool(const ColorNode*, const ColorNode*)>>
      visited_nodes(MinPriorityColorNodeFn);

  int num_target_color_nodes = 0;

  for (size_t idx = 0; idx < ids.size(); ++idx) {
    const int cur_color = ids[idx];
    if (cur_color == val) {
      nodes.emplace_back(cur_color, 0, idx);

      num_target_color_nodes++;
    } else {
      nodes.emplace_back(cur_color);
    }
  }

  if (num_target_color_nodes < 2) {
    return -1;
  }

  for (size_t idx = 0; idx < graph_from.size(); ++idx) {
    nodes[graph_from[idx] - 1].AddAdjacentNode(graph_to[idx] - 1);
    nodes[graph_to[idx] - 1].AddAdjacentNode(graph_from[idx] - 1);
  }

  // add nodes in priority queue
  for (size_t idx = 0; idx < ids.size(); ++idx) {
    ColorNode& node = nodes[idx];
    if (node.GetColor() == val) {
      visited_nodes.push(&node);
    }
  }

  while (!visited_nodes.empty()) {
    ColorNode* cur_node = visited_nodes.top();
    // cout << cur_node->GetColor() << " : ";
    // cout << cur_node->GetDistance() << " (" << cur_node->GetVisitedLabel() << ")" << endl;

    visited_nodes.pop();

    const int distance = cur_node->AddInQueue([&nodes, &visited_nodes, cur_node](int node_idx) {
      ColorNode& next_node = nodes[node_idx];
      if (next_node.IsVisited()) {
        if (next_node.GetVisitedLabel() != cur_node->GetVisitedLabel()) {
          return (next_node.GetDistance() + cur_node->GetDistance() + 1);
        } else {
          return numeric_limits<int>::max();
        }
      }

      next_node.SetDistance((cur_node->GetDistance() + 1), cur_node->GetVisitedLabel());
      ;
      visited_nodes.push(&next_node);
      return numeric_limits<int>::max();
    });

    if (distance < numeric_limits<int>::max()) {
      return distance;
    }
  }

  assert(0);
  return 0;
}

TEST_CASE("nearest_clone", "[interview_prep_kit][graph][medium]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  int graph_nodes;
  int graph_edges;

  cin >> graph_nodes >> graph_edges;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  vector<int> graph_from(graph_edges);
  vector<int> graph_to(graph_edges);

  for (int i = 0; i < graph_edges; i++) {
    cin >> graph_from[i] >> graph_to[i];
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }

  string ids_temp_temp;
  getline(cin, ids_temp_temp);

  vector<string> ids_temp = split_string(ids_temp_temp);

  vector<long> ids(graph_nodes);

  for (int i = 0; i < graph_nodes; i++) {
    long ids_item = stol(ids_temp[i]);

    ids[i] = ids_item;
  }

  int val;
  cin >> val;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  int ans = findShortest(graph_nodes, graph_from, graph_to, ids, val);

  fout << ans << "\n";

  fout.close();
}
