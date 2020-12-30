// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/crossword-puzzle/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 30/12/20.
//
//*****************************************************************

#include "utils.h"
#include <bits/stdc++.h>
#include <catch2/catch.hpp>
#include <iostream>

using namespace std;

class BlankCells {
 public:
  BlankCells() : word_idx_(-1) {}
  ~BlankCells() {}

  virtual bool IsHorizontal() const {
    return false;
  }
  virtual bool IsVertical() const {
    return false;
  }

  virtual int GetLength() const = 0;
  virtual int GetIndex() const = 0;
  virtual int GetStartPos() const = 0;
  virtual int GetEndPos() const = 0;

  virtual void CheckForInterSection(vector<shared_ptr<BlankCells>>& blanks,
                                    shared_ptr<BlankCells>& cur) {
    assert(0);
  }

  void AddInterSection(shared_ptr<BlankCells>& blank) {
    intersection_.insert(blank);
  }

  int GetWord() const {
    return word_idx_;
  }

  bool AddWord(const vector<string>& words, unordered_map<int, unordered_set<int>>& unmapped_words,
               const int parent_index = -1, const char c = '-') {
    assert(word_idx_ == -1);

    const int cur_char_pos = ((parent_index != -1) ? (parent_index - GetStartPos()) : -1);
    if (cur_char_pos >= GetLength()) {
      return false;
    }

    auto iter = unmapped_words.find(GetLength());
    if (iter == unmapped_words.end()) {
      return false;
    }

    unordered_set<int> word_idx_check = iter->second;

    for (int idx : word_idx_check) {
      if ((cur_char_pos == -1) || (words[idx][cur_char_pos] == c)) {
        // put word
        word_idx_ = idx;
        iter->second.erase(idx);

        const string& cur_word = words[idx];
        bool remove_word = false;

        for (auto& intersection : intersection_) {
          const int parent_char_pos = (intersection->GetIndex() - GetStartPos());
          const int intersect_char_pos = (GetIndex() - intersection->GetStartPos());

          if (intersection->GetWord() != -1) {
            if ((intersect_char_pos >= words[intersection->GetWord()].length()) ||
                (parent_char_pos >= cur_word.length()) ||
                (words[intersection->GetWord()][intersect_char_pos] != cur_word[parent_char_pos])) {
              remove_word = true;
              break;
            }
            continue;
          }

          if (!intersection->AddWord(words, unmapped_words, GetIndex(),
                                     cur_word[parent_char_pos])) {
            remove_word = true;
            break;
          }
        }

        if (remove_word) {
          word_idx_ = -1;
          iter->second.insert(idx);
        } else {
          break;
        }
      }
    }

    if (iter->second.size() == 0) {
      unmapped_words.erase(GetLength());
    }

    return (word_idx_ != -1);
  }

 protected:
  unordered_set<shared_ptr<BlankCells>> intersection_;

  int word_idx_;

 public:
  auto GetIntersections() const -> const decltype(intersection_)& {
    return intersection_;
  }
};

class HorizontalBlankCells : public BlankCells {
 public:
  HorizontalBlankCells(const int row, const int start_col, const int end_col)
      : BlankCells(), row_(row), start_col_(start_col), end_col_(end_col) {}
  virtual ~HorizontalBlankCells() {}

  virtual bool IsHorizontal() const {
    return true;
  }

  virtual int GetLength() const {
    return (end_col_ - start_col_ + 1);
  }
  virtual int GetIndex() const {
    return row_;
  }
  virtual int GetStartPos() const {
    return start_col_;
  }
  virtual int GetEndPos() const {
    return end_col_;
  }

 private:
  int row_;
  int start_col_;
  int end_col_;
};

class VerticalBlankCells : public BlankCells {
 public:
  VerticalBlankCells(const int col, const int start_row, const int end_row)
      : BlankCells(), col_(col), start_row_(start_row), end_row_(end_row) {}
  virtual ~VerticalBlankCells() {}

  virtual bool IsVertical() const {
    return true;
  }

  virtual int GetLength() const {
    return (end_row_ - start_row_ + 1);
  }
  virtual int GetIndex() const {
    return col_;
  }
  virtual int GetStartPos() const {
    return start_row_;
  }
  virtual int GetEndPos() const {
    return end_row_;
  }

  virtual void CheckForInterSection(vector<shared_ptr<BlankCells>>& blanks,
                                    shared_ptr<BlankCells>& cur) {
    for (auto& blank : blanks) {
      if (!blank->IsHorizontal()) {
        return;
      }

      if (blank->GetIndex() < start_row_) {
        continue;
      }

      if (blank->GetIndex() > end_row_) {
        return;
      }

      if ((blank->GetStartPos() <= GetIndex()) && (blank->GetEndPos() >= GetIndex())) {
        AddInterSection(blank);
        blank->AddInterSection(cur);
      }
    }
  }

 private:
  int col_;
  int start_row_;
  int end_row_;
};

bool CompareBlanksFn(const shared_ptr<BlankCells>& lhs, const shared_ptr<BlankCells>& rhs) {
  return (lhs->GetLength() >= rhs->GetLength());
}

bool CompareWordLenFn(const string& lhs, const string& rhs) {
  return (lhs.length() >= rhs.length());
}

// Complete the crosswordPuzzle function below.
vector<string> crosswordPuzzle(const vector<string>& crossword, const string& word_str) {
  vector<shared_ptr<BlankCells>> blanks;

  // populate blanks
  for (size_t i = 0; i < 10; ++i) {
    int blank = -1;
    for (size_t j = 0; j < 10; ++j) {
      if (blank == -1) {
        if (crossword[i][j] == '-') {
          blank = j;
        }
      } else if (crossword[i][j] != '-') {
        if (j > (blank + 1)) {
          blanks.push_back(make_shared<HorizontalBlankCells>(i, blank, (j - 1)));
        }
        blank = -1;
      }
    }

    if ((blank != -1) && (blank < 9)) {
      blanks.push_back(make_shared<HorizontalBlankCells>(i, blank, 9));
    }
  }
  for (size_t j = 0; j < 10; ++j) {
    int blank = -1;
    for (size_t i = 0; i < 10; ++i) {
      if (blank == -1) {
        if (crossword[i][j] == '-') {
          blank = i;
        }
      } else if (crossword[i][j] != '-') {
        if (i > (blank + 1)) {
          blanks.push_back(make_shared<VerticalBlankCells>(j, blank, (i - 1)));
          blanks.back()->CheckForInterSection(blanks, blanks.back());
        }
        blank = -1;
      }
    }

    if ((blank != -1) && (blank < 9)) {
      blanks.push_back(make_shared<VerticalBlankCells>(j, blank, 9));
      blanks.back()->CheckForInterSection(blanks, blanks.back());
    }
  }

  sort(blanks.begin(), blanks.end(), CompareBlanksFn);

  /*for (auto& blank : blanks) {
    cout << (blank->IsHorizontal() ? "Row " : "Col ") << blank->GetIndex() << " : " <<
  blank->GetLength(); auto& intersection = blank->GetIntersections(); for (auto& intersection :
  intersection) { cout << (intersection->IsHorizontal() ? ", (Row " : ", (Col ") <<
  intersection->GetIndex() << ")";
    }
    cout << endl;
  }*/

  vector<string> words = split_string(word_str, ';');

  sort(words.begin(), words.end(), CompareWordLenFn);

  assert(blanks.size() == words.size());
  for (size_t idx = 0; idx < words.size(); ++idx) {
    assert(blanks[idx]->GetLength() == words[idx].length());
  }

  unordered_map<int, unordered_set<int>> unmapped_words;
  for (size_t idx = 0; idx < words.size(); ++idx) {
    const int cur_word_len = words[idx].length();
    auto iter = unmapped_words.find(cur_word_len);
    if (iter == unmapped_words.end()) {
      unmapped_words[cur_word_len] = unordered_set<int>();
      unmapped_words[cur_word_len].insert(idx);
    } else {
      iter->second.insert(idx);
    }
  }

  // fill blanks
  for (size_t i = 0; i < blanks.size(); ++i) {
    auto& blank = blanks[i];
    if (blank->GetWord() != -1) {
      continue;
    }

    const bool ret_val = blank->AddWord(words, unmapped_words);
    assert(ret_val);

    // cout << (blank->IsHorizontal() ? "Row " : "Col ") << blank->GetIndex() << " : ";
    // cout << words[blank->GetWord()] << endl;

    assert(blank->GetWord() != -1);
  }

  string default_str = "";

  for (size_t i = 0; i < 10; ++i) {
    for (size_t j = 0; j < 10; ++j) {
      if (crossword[i][j] != '-') {
        default_str = string(10, crossword[i][j]);
        break;
      }
    }
    if (!default_str.empty()) {
      break;
    }
  }

  vector<string> filled_crossword(10, default_str);

  for (const auto& blank : blanks) {
    if (blank->IsHorizontal()) {
      const int row = blank->GetIndex();
      const string& word = words[blank->GetWord()];

      for (size_t idx = 0; idx < blank->GetLength(); ++idx) {
        filled_crossword[row][idx + blank->GetStartPos()] = word[idx];
      }
    } else {
      const int col = blank->GetIndex();
      const string& word = words[blank->GetWord()];

      for (size_t idx = 0; idx < blank->GetLength(); ++idx) {
        filled_crossword[idx + blank->GetStartPos()][col] = word[idx];
      }
    }
  }

  return filled_crossword;
}

TEST_CASE("crossword_puzzle", "[interview_prep_kit][recursion][medium]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  vector<string> crossword(10);

  for (int i = 0; i < 10; i++) {
    string crossword_item;
    getline(cin, crossword_item);

    crossword[i] = crossword_item;
  }

  string words;
  getline(cin, words);

  vector<string> result = crosswordPuzzle(crossword, words);

  for (int i = 0; i < result.size(); i++) {
    fout << result[i];

    if (i != result.size() - 1) {
      fout << "\n";
    }
  }

  fout << "\n";

  fout.close();
}
