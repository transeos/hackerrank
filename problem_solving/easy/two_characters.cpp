// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/two-characters/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 11/06/22.
//
//*****************************************************************

#include "utils.h"
#include <bits/stdc++.h>
#include <catch2/catch.hpp>

using std::cin;
using std::cout;
using std::endl;
using std::ofstream;
using std::string;
using std::vector;

/*
 * Complete the 'alternate' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

class StringParse {
 private:
  char _c1;
  char _c2;

  int32_t _maxLen;

 public:
  StringParse(const char c1, const char c2, int32_t maxLen) : _c1(c1), _c2(c2), _maxLen(maxLen) {}

  int32_t GetMaxLen() const {
    return _maxLen;
  }

  bool IsValid(const string& origStr) const {
    size_t origStrLen = origStr.length();
    size_t startIndex = 0;

    while (origStr[startIndex] != _c1) {
      startIndex++;
      if (startIndex >= origStrLen - 1) {
        return false;
      }

      if (origStr[startIndex] == _c2) {
        return false;
      }
    }

    char skipChar = _c1;
    char matchChar = _c2;

    startIndex++;
    while (startIndex < origStrLen) {
      if (origStr[startIndex] == skipChar) {
        return false;
      }

      if (origStr[startIndex] == matchChar) {
        std::swap(skipChar, matchChar);
      }

      startIndex++;
    }

    return true;
  }

  bool operator>(const StringParse& rhs) const {
    if (_maxLen > rhs._maxLen) {
      return true;
    } else if (_maxLen < rhs._maxLen) {
      return false;
    } else {
      return ((_c1 << 5) + _c2) > ((rhs._c1 << 5) + rhs._c2);
    }
  }
  bool operator<(const StringParse& rhs) const {
    return !(*this > rhs);
  }
};

int32_t alternate(const string& s) {
  if (s.length() < 2) {
    return 0;
  }

  std::array<int32_t, 26> letterCount = {};

  for (const char c : s) {
    letterCount[c - 'a']++;
  }

  vector<StringParse> chunks;

  for (size_t i = 0; i < 26; ++i) {
    if (letterCount[i] == 0) {
      continue;
    }

    for (size_t j = 0; j < 26; ++j) {
      if (letterCount[j] == 0 || i == j) {
        continue;
      }

      chunks.emplace_back('a' + i, 'a' + j, letterCount[i] + letterCount[j]);
    }
  }

  std::sort(chunks.begin(), chunks.end(), std::greater<StringParse>());

  for (auto& chunk : chunks) {
    if (chunk.IsValid(s)) {
      return chunk.GetMaxLen();
    }
  }

  return 0;
}

TEST_CASE("two_characters", "[problem_solving][easy]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  string l_temp;
  getline(cin, l_temp);

  int l = stoi(ltrim(rtrim(l_temp)));

  string s;
  getline(cin, s);

  int result = alternate(s);

  fout << result << "\n";

  fout.close();
}
