// -*- C++ -*-
//
//*****************************************************************
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 11/05/19.
//
//*****************************************************************

#define CATCH_CONFIG_MAIN

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>

#include <catch2/catch.hpp>

using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};

class LRUCache : public Cache {
  public:
    LRUCache(int cap) : Cache() {
      cp = cap;
      tail = nullptr;
      head = nullptr;
    }
    ~LRUCache() { }

    virtual void set(int key, int val) override {
      auto iter = mp.find(key);
      if (iter == mp.end()) {
        struct Node* new_node = new Node(key, val);
        mp[key] = new_node;

        if (!tail) {
          tail = new_node;
        }

        if (head) {
          new_node->next = head;
          head->prev = new_node;
        }
        head = new_node;

        if (mp.size() > cp) {
          Node* new_tail = tail->prev;
          
          mp.erase(tail->key);
          delete tail;

          new_tail->next = nullptr;
          tail = new_tail;
        }
      }
      else {
        Node* new_head = iter->second;
        new_head->value = val;

        if (new_head != head) {
          if (new_head == tail) {            
            tail = tail->prev;
            tail->next = nullptr;            
          }
          else {
            Node* prev_left = new_head->prev;
            Node* prev_right = new_head->next;

            prev_left->next = prev_right;
            prev_right->prev = prev_left;         
          }

          head->prev = new_head;
          new_head->next = head;
          new_head = head;
        }
      }

      assert(mp.size() <= cp);
    }
    virtual int get(int key) override {
      auto iter = mp.find(key);
      return ((iter != mp.end()) ? iter->second->value : -1);
    }
};

TEST_CASE("abstract_class", "[cpp][hard]") {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
}
