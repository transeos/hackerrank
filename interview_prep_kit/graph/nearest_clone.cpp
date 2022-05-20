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

/*
 * For the unweighted graph, <name>:
 *
 * 1. The number of nodes is <name>_nodes.
 * 2. The number of edges is <name>_edges.
 * 3. An edge exists between <name>_from[i] to <name>_to[i].
 *
 */
class Node {
 private:
  vector<int32_t> _adjacentNodes;
  int32_t _color;
  int32_t _distance;
  int32_t _startTargetNode;

 public:
  Node() : _distance(-1), _color(-1), _startTargetNode(-1) {}

  void SetColor(int32_t color) {
    assert(_color == -1);
    _color = color;
  }
  int32_t GetColor() const {
    return _color;
  }

  void AddAdjacentNode(int32_t nodeIndex) {
    _adjacentNodes.push_back(nodeIndex);
  }
  const vector<int32_t>& GetAdjacentNodes() const {
    return _adjacentNodes;
  }

  void SetDistance(int32_t distance, int32_t startTargetNode) {
    assert((_distance == -1) && (_startTargetNode == -1));
    _distance = distance;
    _startTargetNode = startTargetNode;
  }
  int32_t GetDistance() const {
    return _distance;
  }

  int32_t GetStartTargetNode() const {
    return _startTargetNode;
  }
};

int32_t findShortest(const int32_t graph_nodes, const vector<int>& graph_from,
                     const vector<int>& graph_to, const vector<long>& ids, const int32_t val) {
  std::queue<int32_t> visitedNodes;
  vector<Node> nodes(graph_nodes);

  int32_t numNodesofInputColor = 0;

  for (size_t i = 0; i < graph_nodes; ++i) {
    nodes[i].SetColor(ids[i]);

    if (ids[i] == val) {
      nodes[i].SetDistance(0, i);
      visitedNodes.push(i);
      numNodesofInputColor++;
    }
  }

  if (numNodesofInputColor < 2) {
    return -1;
  }

  for (size_t i = 0; i < graph_from.size(); ++i) {
    nodes[graph_from[i] - 1].AddAdjacentNode(graph_to[i] - 1);
    nodes[graph_to[i] - 1].AddAdjacentNode(graph_from[i] - 1);
  }

  while (visitedNodes.size() > 0) {
    const int32_t curNodeIndex = visitedNodes.front();
    const int32_t curDistance = nodes[curNodeIndex].GetDistance();
    const int32_t startTargetNode = nodes[curNodeIndex].GetStartTargetNode();
    visitedNodes.pop();

    const auto& adjacentNodes = nodes[curNodeIndex].GetAdjacentNodes();
    for (int32_t nodeIndex : adjacentNodes) {
      if (nodes[nodeIndex].GetDistance() != -1) {
        if (nodes[nodeIndex].GetStartTargetNode() != startTargetNode) {
          return curDistance + nodes[nodeIndex].GetDistance() + 1;
        }
      } else {
        nodes[nodeIndex].SetDistance(curDistance + 1, startTargetNode);
        visitedNodes.push(nodeIndex);
      }
    };
  }

  return -1;
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
