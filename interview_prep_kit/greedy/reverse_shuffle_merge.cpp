// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/reverse-shuffle-merge/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 02/01/21.
//
//*****************************************************************

#include "utils.h"
#include <bits/stdc++.h>
#include <catch2/catch.hpp>
#include <iostream>

using namespace std;

char FindNextMinChar(const array<int, 26>& letters, const char cur_char = 'a') {
  for (size_t idx = (cur_char - 'a'); idx < 26; ++idx) {
    if (letters[idx] > 0) {
      return (idx + 'a');
    }
  }
  return 'z';
}

// Complete the reverseShuffleMerge function below.
string reverseShuffleMerge(const string& s) {
  array<int, 26> letters = {};
  for (char c : s) {
    letters[c - 'a']++;
  }
  for (int idx = 25; idx >= 0; --idx) {
    int& count = letters[idx];
    if (count > 0) {
      count /= 2;
    }
  }

  array<int, 26> reverse_letters = letters;

  string result = "";

  map<char, int> letter_stack;
  char next_reverse_char = FindNextMinChar(reverse_letters);

  for (int idx = (s.length() - 1); idx >= 0; --idx) {
    const char c = s[idx];

    if (c <= next_reverse_char) {
      if (reverse_letters[c - 'a'] > 0) {
        reverse_letters[c - 'a']--;
        result.push_back(c);
        next_reverse_char = FindNextMinChar(reverse_letters, next_reverse_char);
        letter_stack.clear();
      } else {
        letters[c - 'a']--;
      }
    } else {
      if (letters[c - 'a'] > 0) {
        letters[c - 'a']--;

        auto iter = letter_stack.find(c);
        if (iter != letter_stack.end()) {
          iter->second++;
        } else {
          letter_stack[c] = 1;
        }
        iter = letter_stack.find(c);
        ++iter;
        letter_stack.erase(iter, letter_stack.end());
      } else {
        reverse_letters[c - 'a']--;

        for (auto& iter : letter_stack) {
          const char next_char = iter.first;
          if (next_char < c) {
            while ((reverse_letters[next_char - 'a'] > 0) && (iter.second > 0)) {
              reverse_letters[next_char - 'a']--;
              letters[next_char - 'a']++;
              result.push_back(next_char);
              iter.second--;
            }
          } else {
            break;
          }
        }

        result.push_back(c);
        next_reverse_char = FindNextMinChar(reverse_letters, next_reverse_char);

        auto iter = letter_stack.find(c);
        const int num_current = ((iter != letter_stack.end()) ? iter->second : 0);
        letter_stack.clear();
        if (num_current) {
          letter_stack[c] = num_current;
        }
      }
    }

    if (result.length() == (s.length() / 2)) {
      return result;
    }
  }

  assert(0);
  return result;
}

TEST_CASE("reverse_shuffle_merge", "[interview_prep_kit][greedy][hard][star]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  string s;
  getline(cin, s);

  string result = reverseShuffleMerge(s);

  fout << result << "\n";

  fout.close();
}
