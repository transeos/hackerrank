// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/decibinary-numbers/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 03/01/21.
//
//*****************************************************************

#include "utils.h"
#include <bits/stdc++.h>
#include <catch2/catch.hpp>
#include <iostream>

using namespace std;

int64_t FindNextDecibinary(const int64_t decimal_val, const int64_t offset) {
  int64_t cur_num = decimal_val;

  for (int64_t idx = 0; idx < offset; ++idx) {
    int64_t power = -1;
    int64_t lsb = 0;

    while (lsb < 2) {
      power++;
      lsb = (cur_num / pow(10, power));
      lsb %= 10;
    }

    cur_num += pow(10, (power + 1));

    if ((power > 0) && (lsb >= 2)) {
      cur_num -= ((lsb * pow(10, power)) - (2 * (lsb - 2) * pow(10, (power - 1))));
    } else {
      cur_num -= (2 * pow(10, power));
    }
  }

  return cur_num;
}

// Complete the decibinaryNumbers function below.
int64_t decibinaryNumbers(const int64_t x) {
  if (x == 1) {
    return 0;
  }
  if (x == 2) {
    return 1;
  }

  unordered_map<int64_t, int64_t> identical_decimal;
  identical_decimal[0] = 1;
  identical_decimal[1] = 1;
  identical_decimal[2] = 2;

  int64_t num = 4;
  int64_t prev_num = 2;
  int64_t decimal_val = 2;

  while (num < x) {
    prev_num = num;

    decimal_val++;

    num++;

    int64_t start_val = (decimal_val / 2);
    if (start_val & 0x1) {
      start_val -= 1;
    }
    for (int64_t idx = start_val; idx >= 2; idx -= 2) {
      num += (decimal_val / idx);
    }

    for (int64_t idx = (start_val + 1); idx >= 0; idx -= 2) {
      num += ((decimal_val >> idx) - (decimal_val >> (idx + 1)));
    }

    identical_decimal[decimal_val] = (num - prev_num);

    // cout << decimal_val << " : " << num << endl;
  }

  if (x == (prev_num + 1)) {
    return decimal_val;
  }

  int64_t offset = (x - prev_num - 1);

  return FindNextDecibinary(decimal_val, offset);

  /*assert(offset > 0);

  vector<int64_t> offsets;
  offsets.push_back(1);

  int64_t max_power = 1;
  while (offset >= offsets.back()) {
    if (decimal_val >= (1 << max_power)) {
      offsets.push_back(offsets.back() + (decimal_val / (1 << max_power)));
      max_power++;
    }
    else {
      break;
    }
  }

  int64_t ret_val = 0;
  int64_t remaining_num = decimal_val;

  for (int64_t idx = max_power; idx >= 1; --idx) {
    if (offset < offsets[idx - 1]) {
      continue;
    }

    int64_t cur_digit = 1;
    remaining_num -= (cur_digit * (1 << idx));
    assert(remaining_num >= 0);

    while ((offset - offsets[idx - 1] - cur_digit + 2) >= identical_decimal[remaining_num]) {
      cur_digit++;
      remaining_num -= (cur_digit * (1 << idx));
      assert(remaining_num >= 0);
    }

    ret_val += (cur_digit * pow(10, idx));
    remaining_num -= (cur_digit * (1 << idx));
    assert(remaining_num >= 0);

    offset -= offsets[idx - 1];
  }
  ret_val += remaining_num;

  return ret_val;*/
}

TEST_CASE("decibinary_numbers", "[interview_prep_kit][DP][hard][star][incomplete][timeout]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  int q;
  cin >> q;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  for (int q_itr = 0; q_itr < q; q_itr++) {
    long x;
    cin >> x;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int64_t result = decibinaryNumbers(x);

    fout << result << "\n";
  }

  fout.close();
}
