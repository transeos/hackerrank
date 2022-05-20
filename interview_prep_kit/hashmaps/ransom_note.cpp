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

#include "utils.h"
#include <bits/stdc++.h>
#include <catch2/catch.hpp>
#include <iostream>

using namespace std;

// Complete the checkMagazine function below.
void checkMagazine(const vector<string>& magazine, const vector<string>& note) {
  std::unordered_map<string, size_t> magazineWords;

  std::for_each(magazine.begin(), magazine.end(), [&magazineWords](const string& word) {
    if (auto it = magazineWords.try_emplace(word, 1); it.second == false) {
      it.first->second++;
    }
  });

  for (auto& word : note) {
    if (auto it = magazineWords.find(word); it == magazineWords.end()) {
      cout << "No" << endl;
      return;
    } else {
      it->second--;
      if (it->second == 0) {
        magazineWords.erase(it);
      }
    }
  }

  cout << "Yes" << endl;
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
