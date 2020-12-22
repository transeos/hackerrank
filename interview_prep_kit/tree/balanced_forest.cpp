// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/balanced-forest/problem
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

//#define DEBUG_BALANCED_FOREST

using namespace std;

class ForestNode {
 public:
  ForestNode(const int index, const int64_t data)
      : index_(index), data_(data), parent_(-1), tree_sum_(data) {}
  ~ForestNode() {}

  int GetIndex() const {
    return index_;
  }
  int64_t GetData() const {
    return data_;
  }

  int GetParentIndex() const {
    return parent_;
  }

  void AddChild(const int index) {
    assert(index);
    children_.insert(index);
  }
  const unordered_set<int>& GetChildren() {
    return children_;
  }

  void UpdateParentIndex(vector<ForestNode>& nodes) {
    children_.erase(GetParentIndex());

    for (int child_idx : children_) {
      nodes[child_idx].SetParentIndex(index_);
      nodes[child_idx].UpdateParentIndex(nodes);
    }
  }

  void UpdateTreeSum(vector<ForestNode>& nodes) {
    for (int child_idx : children_) {
      nodes[child_idx].UpdateTreeSum(nodes);
      tree_sum_ += nodes[child_idx].GetTreeSum();
    }
  }
  void ReduceTreeSum(int64_t val) {
    tree_sum_ -= val;
  }
  void RestoreTreeSum(int64_t val) {
    tree_sum_ += val;
  }

  int64_t GetTreeSum() const {
    return tree_sum_;
  }

  bool FindTreeSum(int64_t target_sum, const vector<ForestNode>& nodes, const int cut_parent_idx,
                   const int cut_child_idx) const {
    for (int child_idx : children_) {
      if (child_idx == cut_child_idx) {
        assert(index_ == cut_parent_idx);
        continue;
      }

      if (nodes[child_idx].GetTreeSum() == target_sum) {
        return true;
      }
      if (nodes[child_idx].GetTreeSum() > target_sum) {
        if (nodes[child_idx].FindTreeSum(target_sum, nodes, cut_parent_idx, cut_child_idx)) {
          return true;
        }
      }
    }
    return false;
  }

 private:
  int index_;
  int64_t data_;

  int parent_;
  unordered_set<int> children_;

  int64_t tree_sum_;

  void SetParentIndex(const int index) {
    assert(parent_ == -1);
    parent_ = index;
  }
};

vector<ForestNode> g_nodes;

int64_t GetNewNodeCutVal(const int node_idx) {
  int64_t val = (g_nodes[0].GetTreeSum() - (3 * g_nodes[node_idx].GetTreeSum()));
  return (((val < 0) || (val % 2)) ? -1 : (val / 2));
}

int64_t GetNoNewNodeCutVal(const int node_idx) {
  int64_t val = ((3 * g_nodes[node_idx].GetTreeSum()) - g_nodes[0].GetTreeSum());
  return ((val < 0) ? -1 : val);
}

bool CompareCutFn(const array<int64_t, 4>& lhs, const array<int64_t, 4>& rhs) {
  return (lhs[3] < rhs[3]);
}

// Complete the balancedForest function below.
int64_t balancedForest(const vector<int64_t>& c, const vector<vector<int>>& edges) {
  g_nodes.clear();

  for (int idx = 0; idx < c.size(); ++idx) {
    g_nodes.push_back({idx, c[idx]});
  }

  // root index = 0

  for (auto& edge : edges) {
    // cout << "Edge: " << edge[0] << " " << edge[1] << "," << endl;

    int parent_idx = (edge[0] - 1);
    int child_idx = (edge[1] - 1);

    // right now parent-child relationship is not known except for node index 0
    if (edge[0] != 1) {
      g_nodes[edge[1] - 1].AddChild(edge[0] - 1);
    }
    if (edge[1] != 1) {
      g_nodes[edge[0] - 1].AddChild(edge[1] - 1);
    }
  }

  // update parent-child relationship
  g_nodes[0].UpdateParentIndex(g_nodes);

  // update tree sum
  g_nodes[0].UpdateTreeSum(g_nodes);

#ifdef DEBUG_BALANCED_FOREST
  cout << endl;
  for (ForestNode& node : g_nodes) {
    cout << node.GetIndex() << ":" << node.GetData();

    auto& children = node.GetChildren();
    if (children.size()) {
      cout << ", children: ";
      for (int child_idx : children) {
        cout << g_nodes[child_idx].GetIndex() << "," << g_nodes[child_idx].GetData() << " ";
      }
    }

    cout << ", tree sum: " << node.GetTreeSum() << endl;
  }
  cout << endl;
#endif

  // 0: parent, 1: child, 2: 1 for new node cut, 0 for no new node cut
  // 3: cut value
  vector<array<int64_t, 4>> edge_cuts;

  for (auto edge : edges) {
    int parent_idx = (edge[0] - 1);
    int child_idx = (edge[1] - 1);
    if (g_nodes[child_idx].GetParentIndex() != parent_idx) {
      // reverse edge
      assert(g_nodes[parent_idx].GetParentIndex() == child_idx);
      child_idx = parent_idx;
      parent_idx = (edge[1] - 1);
    }

    int64_t val = GetNewNodeCutVal(child_idx);
    if (val != -1) {
      edge_cuts.push_back({parent_idx, child_idx, 1, val});
    }

    val = GetNoNewNodeCutVal(child_idx);
    if (val != -1) {
      edge_cuts.push_back({parent_idx, child_idx, 0, val});
    }
  }

  sort(edge_cuts.begin(), edge_cuts.end(), CompareCutFn);

  int64_t ret_val = -1;

  for (auto& edge_cut : edge_cuts) {
    const int64_t reduce_tree_sum = g_nodes[edge_cut[1]].GetTreeSum();

    // temporarily change tree sum of ancessor nodes
    int cur_node_idx = edge_cut[0];
    while (cur_node_idx != -1) {
      g_nodes[cur_node_idx].ReduceTreeSum(reduce_tree_sum);
      cur_node_idx = g_nodes[cur_node_idx].GetParentIndex();
    }

    bool found = false;

    if (edge_cut[2] == 1) {
      // new node will be added in current cut
      const int64_t tree_cut_sum = (g_nodes[0].GetTreeSum() / 2);
      found = g_nodes[0].FindTreeSum(tree_cut_sum, g_nodes, edge_cut[0], edge_cut[1]);
    } else {
      // check if the node needs to be added on root and cut as well
      if (g_nodes[0].GetTreeSum() == reduce_tree_sum) {
        found = true;
      } else {
        // new node will not be added in current cut
        const int64_t tree_cut_sum1 = reduce_tree_sum;
        const int64_t tree_cut_sum2 = (reduce_tree_sum - edge_cut[3]);
        found = (g_nodes[0].FindTreeSum(tree_cut_sum1, g_nodes, edge_cut[0], edge_cut[1]) ||
                 g_nodes[0].FindTreeSum(tree_cut_sum2, g_nodes, edge_cut[0], edge_cut[1]));
      }
    }

    if (found) {
#ifdef DEBUG_BALANCED_FOREST
      cout << "found cut : " << edge_cut[0] << " " << edge_cut[1];
      cout << ((edge_cut[2] == 1) ? ", New node : " : ", No new node : ");
      cout << edge_cut[3] << endl;

      if (ret_val == -1) {
        ret_val = edge_cut[3];
      }
#else
      return edge_cut[3];
#endif
    }

    // restore original tree sum of ancessor nodes
    cur_node_idx = edge_cut[0];
    while (cur_node_idx != -1) {
      g_nodes[cur_node_idx].RestoreTreeSum(reduce_tree_sum);
      cur_node_idx = g_nodes[cur_node_idx].GetParentIndex();
    }

#ifdef DEBUG_BALANCED_FOREST
    if (!found) {
      cout << "failed cut : " << edge_cut[0] << " " << edge_cut[1];
      cout << ((edge_cut[2] == 1) ? ", New node : " : ", No new node : ");
      cout << edge_cut[3] << endl;
    }
#endif
  }

  return ret_val;
}

TEST_CASE("balanced_forest", "[interview_prep_kit][tree][hard][star]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  int q;
  cin >> q;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  for (int q_itr = 0; q_itr < q; q_itr++) {
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string c_temp_temp;
    getline(cin, c_temp_temp);

    vector<string> c_temp = split_string(c_temp_temp);

    vector<int64_t> c(n);

    for (int i = 0; i < n; i++) {
      int64_t c_item = stol(c_temp[i]);

      c[i] = c_item;
    }

    vector<vector<int>> edges(n - 1);
    for (int i = 0; i < n - 1; i++) {
      edges[i].resize(2);

      for (int j = 0; j < 2; j++) {
        cin >> edges[i][j];
      }

      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // cout << "Query: " << q_itr << endl;
    int64_t result = balancedForest(c, edges);

    fout << result << "\n";
  }

  fout.close();
}
