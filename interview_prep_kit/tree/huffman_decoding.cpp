// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/tree-huffman-decoding/problem
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

typedef struct node {
  int freq;
  char data;
  node* left;
  node* right;

} node;

struct deref : public binary_function<node*, node*, bool> {
  bool operator()(const node* a, const node* b) const {
    return a->freq > b->freq;
  }
};

typedef priority_queue<node*, vector<node*>, deref> spq;

node* huffman_hidden(string s) {
  spq pq;
  vector<int> count(256, 0);

  for (int i = 0; i < s.length(); i++) {
    count[s[i]]++;
  }

  for (int i = 0; i < 256; i++) {
    node* n_node = new node;
    n_node->left = NULL;
    n_node->right = NULL;
    n_node->data = (char)i;
    n_node->freq = count[i];

    if (count[i] != 0) pq.push(n_node);
  }

  while (pq.size() != 1) {
    node* left = pq.top();
    pq.pop();
    node* right = pq.top();
    pq.pop();
    node* comb = new node;
    comb->freq = left->freq + right->freq;
    comb->data = '\0';
    comb->left = left;
    comb->right = right;
    pq.push(comb);
  }

  return pq.top();
}

void print_codes_hidden(node* root, string code, map<char, string>& mp) {
  if (root == NULL) return;
  if (root->data != '\0') {
    mp[root->data] = code;
  }

  print_codes_hidden(root->left, code + '0', mp);
  print_codes_hidden(root->right, code + '1', mp);
}

/*
The structure of the node is

typedef struct node
{
    int freq;
    char data;
    node * left;
    node * right;

}node;

*/

void decode_huff_int(node* root, const string& prev_str, unordered_map<string, char>& encoding) {
  if (!root->left && !root->right) {
    // character found
    encoding[prev_str] = root->data;
    // cout << root->data << ":" << prev_str << endl;
    return;
  }

  if (root->left) {
    decode_huff_int(root->left, prev_str + "0", encoding);
  }

  if (root->right) {
    decode_huff_int(root->right, prev_str + "1", encoding);
  }
}

void decode_huff(node* root, const string& s) {
  unordered_map<string, char> encoding;

  decode_huff_int(root, "", encoding);

  string cur_buf = "";

  for (size_t idx = 0; idx < s.size(); ++idx) {
    cur_buf.push_back(s[idx]);

    auto iter = encoding.find(cur_buf);
    if (iter != encoding.end()) {
      cout << iter->second;
      cur_buf = "";
    }
  }
  cout << endl;
}

TEST_CASE("huffman_decoding", "[interview_prep_kit][tree][medium]") {
  string s;
  std::cin >> s;

  node* tree = huffman_hidden(s);
  string code = "";

  map<char, string> mp;
  print_codes_hidden(tree, code, mp);

  string coded;

  for (int i = 0; i < s.length(); i++) {
    coded += mp[s[i]];
  }

  decode_huff(tree, coded);
}
