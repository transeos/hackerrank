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

#define EDGE_LEN 6

class Graph {
 private:
  vector<vector<int32_t>> _adjacencyMatrix;

 public:
  Graph(int n) : _adjacencyMatrix(n) {}

  void add_edge(int u, int v) {
    _adjacencyMatrix[u].push_back(v);
    _adjacencyMatrix[v].push_back(u);
  }

  vector<int> shortest_reach(const int32_t start) {
    vector<int> distances(_adjacencyMatrix.size(), -1);

    std::queue<size_t> visitedNodes;

    distances[start] = 0;
    visitedNodes.push(start);

    while (visitedNodes.size() > 0) {
      const size_t curNodeIndex = visitedNodes.front();
      visitedNodes.pop();

      const int curDistance = distances[curNodeIndex];

      for_each(_adjacencyMatrix[curNodeIndex].begin(), _adjacencyMatrix[curNodeIndex].end(),
               [&visitedNodes, &distances, curDistance, curNodeIndex](int32_t nodeIndex) {
                 if (distances[nodeIndex] == -1) {
                   distances[nodeIndex] = curDistance + EDGE_LEN;
                   visitedNodes.push(nodeIndex);
                 }
               });
    }

    return distances;
  }
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
