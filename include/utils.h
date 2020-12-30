// -*- C++ -*-
//
//*****************************************************************
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 19/05/19.
//
//*****************************************************************

#include <iostream>
#include <vector>

class SinglyLinkedListNode;
class DoublyLinkedListNode;

std::vector<std::string> split_string(std::string input_string, const char delimiter = ' ');

void print_singly_linked_list(SinglyLinkedListNode* node, std::string sep, std::ofstream& fout);
void free_singly_linked_list(SinglyLinkedListNode* node);
void print_doubly_linked_list(DoublyLinkedListNode* node, std::string sep, std::ofstream& fout);
void free_doubly_linked_list(DoublyLinkedListNode* node);

size_t HighestOneBitPosition(uint64_t a);
bool MultiplicationIsSafe(uint64_t a, uint64_t b);
