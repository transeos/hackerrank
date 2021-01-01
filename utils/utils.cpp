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

#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using std::min;
using std::ptr_fun;
using std::string;
using std::unique;
using std::vector;

vector<string> split_string(string input_string, const char delimiter) {
  string::iterator new_end =
      unique(input_string.begin(), input_string.end(),
             [delimiter](const char& x, const char& y) { return x == y and x == delimiter; });

  input_string.erase(new_end, input_string.end());

  while (input_string[input_string.length() - 1] == delimiter) {
    input_string.pop_back();
  }

  vector<string> splits;

  size_t i = 0;
  size_t pos = input_string.find(delimiter);

  while (pos != string::npos) {
    splits.push_back(input_string.substr(i, pos - i));

    i = pos + 1;
    pos = input_string.find(delimiter, i);
  }

  splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

  return splits;
}

string ltrim(const string& str) {
  string s(str);

  s.erase(s.begin(), find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

  return s;
}

string rtrim(const string& str) {
  string s(str);

  s.erase(find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(), s.end());

  return s;
}

vector<string> split(const string& str) {
  vector<string> tokens;

  string::size_type start = 0;
  string::size_type end = 0;

  while ((end = str.find(" ", start)) != string::npos) {
    tokens.push_back(str.substr(start, end - start));

    start = end + 1;
  }

  tokens.push_back(str.substr(start));

  return tokens;
}

size_t HighestOneBitPosition(uint64_t a) {
  size_t bits = 0;

  while (a != 0) {
    ++bits;
    a >>= 1;
  };

  return bits;
}

bool MultiplicationIsSafe(uint64_t a, uint64_t b) {
  size_t a_bits = HighestOneBitPosition(a);
  size_t b_bits = HighestOneBitPosition(b);
  return ((a_bits + b_bits) <= 64);
}
