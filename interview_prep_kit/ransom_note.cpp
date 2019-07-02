// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/ctci-ransom-note/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 08/06/19.
//
//*****************************************************************

#include <bits/stdc++.h>
#include <iostream>

#include "utils.h"
#include <catch2/catch.hpp>

using namespace std;

// Complete the checkMagazine function below.
void checkMagazine(const vector<string>& magazine, const vector<string>& note) {
  unordered_map<string, int> source_words;

  const int num_words = magazine.size();
  for (int idx = 0; idx < num_words; ++idx) {
    const string& cur_word = magazine.at(idx);

    auto iter = source_words.find(cur_word);
    if (iter == source_words.end()) {
      source_words[cur_word] = 1;
    } else {
      iter->second++;
    }
  }

  const int num_note_words = note.size();
  for (int idx = 0; idx < num_note_words; ++idx) {
    auto iter = source_words.find(note[idx]);
    if (iter == source_words.end()) {
      cout << "No";
      return;
    } else {
      iter->second--;
      if (iter->second == 0) {
        source_words.erase(iter);
      }
    }
  }

  cout << "Yes";
}

TEST_CASE("ransom_note", "[interview_prep_kit][hashmaps][easy]") {
  string mn_temp;
  getline(cin, mn_temp);

  vector<string> mn = split_string(mn_temp);

  int m = stoi(mn[0]);

  int n = stoi(mn[1]);

  string magazine_temp_temp;
  getline(cin, magazine_temp_temp);

  vector<string> magazine_temp = split_string(magazine_temp_temp);

  vector<string> magazine(m);

  for (int i = 0; i < m; i++) {
    string magazine_item = magazine_temp[i];

    magazine[i] = magazine_item;
  }

  string note_temp_temp;
  getline(cin, note_temp_temp);

  vector<string> note_temp = split_string(note_temp_temp);

  vector<string> note(n);

  for (int i = 0; i < n; i++) {
    string note_item = note_temp[i];

    note[i] = note_item;
  }

  checkMagazine(magazine, note);
}
