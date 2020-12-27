// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/ctci-bfs-shortest-reach/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 28/12/19.
//
//*****************************************************************

#include "utils.h"
#include <bits/stdc++.h>
#include <catch2/catch.hpp>
#include <deque>
#include <iostream>

using namespace std;

class Graph {
 public:
  Graph(int n) {
    adjacency_.resize(n);
  }
  ~Graph() {}

  void add_edge(const int u, const int v) {
    adjacency_[u].push_back(v);
    adjacency_[v].push_back(u);
  }

  vector<int> shortest_reach(int start) {
    vector<int> distances(adjacency_.size(), -1);

    distances[start] = 0;
    deque<int> visited_nodes(1, start);

    while (!visited_nodes.empty()) {
      const int cur_node_idx = visited_nodes.front();
      const int cur_dist = distances[cur_node_idx];
      visited_nodes.pop_front();

      for (auto& node_idx : adjacency_[cur_node_idx]) {
        if (distances[node_idx] == -1) {
          // not visited before
          distances[node_idx] = (cur_dist + 6);
          visited_nodes.push_back(node_idx);
        }
      }
    }

    return distances;
  }

 private:
  vector<vector<int>> adjacency_;
};

TEST_CASE("bfs_shortest_reach", "[interview_prep_kit][graph][medium]") {
  int queries;
  cin >> queries;

  for (int t = 0; t < queries; t++) {
    int n, m;
    cin >> n;
    // Create a graph of size n where each edge weight is 6:
    Graph graph(n);
    cin >> m;
    // read and set edges
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      // add each edge to the graph
      graph.add_edge(u, v);
    }
    int startId;
    cin >> startId;
    startId--;
    // Find shortest reach from node s
    vector<int> distances = graph.shortest_reach(startId);

    for (int i = 0; i < distances.size(); i++) {
      if (i != startId) {
        cout << distances[i] << " ";
      }
    }
    cout << endl;
  }
}
