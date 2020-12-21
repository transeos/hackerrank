// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/reverse-a-doubly-linked-list/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 21/12/19.
//
//*****************************************************************

#include "utils.h"
#include <bits/stdc++.h>
#include <catch2/catch.hpp>
#include <iostream>

using namespace std;

class DoublyLinkedListNode {
 public:
  int data;
  DoublyLinkedListNode* next;
  DoublyLinkedListNode* prev;

  DoublyLinkedListNode(int node_data) {
    this->data = node_data;
    this->next = nullptr;
    this->prev = nullptr;
  }
};

class DoublyLinkedList {
 public:
  DoublyLinkedListNode* head;
  DoublyLinkedListNode* tail;

  DoublyLinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
  }

  void insert_node(int node_data) {
    DoublyLinkedListNode* node = new DoublyLinkedListNode(node_data);

    if (!this->head) {
      this->head = node;
    } else {
      this->tail->next = node;
      node->prev = this->tail;
    }

    this->tail = node;
  }
};

// Complete the reverse function below.

/*
 * For your reference:
 *
 * DoublyLinkedListNode {
 *     int data;
 *     DoublyLinkedListNode* next;
 *     DoublyLinkedListNode* prev;
 * };
 *
 */
DoublyLinkedListNode* reverse(DoublyLinkedListNode* head) {
  if (!head) {
    return nullptr;
  }

  DoublyLinkedListNode* cur_node = head;

  while (cur_node->next) {
    DoublyLinkedListNode* temp_node = cur_node->next;
    cur_node->next = cur_node->prev;
    cur_node->prev = temp_node;
    cur_node = temp_node;
  }

  cur_node->next = cur_node->prev;
  cur_node->prev = nullptr;

  return cur_node;
}

TEST_CASE("reverse_doubly", "[interview_prep_kit][linked_list][easy]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  int t;
  cin >> t;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  for (int t_itr = 0; t_itr < t; t_itr++) {
    DoublyLinkedList* llist = new DoublyLinkedList();

    int llist_count;
    cin >> llist_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < llist_count; i++) {
      int llist_item;
      cin >> llist_item;
      cin.ignore(numeric_limits<streamsize>::max(), '\n');

      llist->insert_node(llist_item);
    }

    DoublyLinkedListNode* llist1 = reverse(llist->head);

    print_doubly_linked_list(llist1, " ", fout);
    fout << "\n";

    free_doubly_linked_list(llist1);
  }

  fout.close();
}
