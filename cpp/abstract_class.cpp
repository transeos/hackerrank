// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/abstract-classes-polymorphism
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 11/05/19.
//
//*****************************************************************

#define CATCH_CONFIG_MAIN

#include <algorithm>
#include <cassert>
#include <catch2/catch.hpp>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

struct Node {
  Node* next;
  Node* prev;
  int value;
  int key;
  Node(Node* p, Node* n, int k, int val) : prev(p), next(n), key(k), value(val){};
  Node(int k, int val) : prev(NULL), next(NULL), key(k), value(val){};
};

class Cache {
 protected:
  map<int, Node*> mp;              // map the key to the node in the linked list
  int cp;                          // capacity
  Node* tail;                      // double linked list tail pointer
  Node* head;                      // double linked list head pointer
  virtual void set(int, int) = 0;  // set function
  virtual int get(int) = 0;        // get function
};

class LRUCache : public Cache {
 public:
  LRUCache(const int capacity) : Cache() {
    cp = capacity;
    tail = nullptr;
    head = nullptr;
  }
  virtual ~LRUCache() {}

  virtual void set(int key, int val) {
    if (auto iter = mp.find(key); iter != mp.end()) {
      Node* curNode = iter->second;
      curNode->value = val;

      if (curNode != head) {
        if (curNode == tail) {
          tail = tail->prev;
          tail->next = nullptr;
        } else {
          Node* curNodeNext = curNode->next;
          Node* curNodePrev = curNode->prev;

          curNodePrev->next = curNodeNext;
          curNodeNext->prev = curNodePrev;
        }

        head->prev = curNode;
        curNode->prev = nullptr;
        curNode->next = head;
        head = curNode;
      }
    } else {
      if (mp.size() == cp) {
        Node* newTail = tail->prev;
        newTail->next = nullptr;

        mp.erase(tail->key);
        delete tail;

        tail = newTail;
      }

      Node* newNode = new Node(nullptr, head, key, val);
      mp[key] = newNode;

      if (head != nullptr) {
        head->prev = newNode;
      } else {
        tail = newNode;
      }

      head = newNode;
    }
  }

  virtual int get(int key) override {
    if (auto iter = mp.find(key); iter != mp.end()) {
      return iter->second->value;
    } else {
      return -1;
    }
  }
};

TEST_CASE("abstract_class", "[cpp][hard]") {
  int n, capacity, i;
  cin >> n >> capacity;
  LRUCache l(capacity);
  for (i = 0; i < n; i++) {
    string command;
    cin >> command;
    if (command == "get") {
      int key;
      cin >> key;
      cout << l.get(key) << endl;
    } else if (command == "set") {
      int key, value;
      cin >> key >> value;
      l.set(key, value);
    }
  }
}
