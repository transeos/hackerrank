// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/richie-rich/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 26/05/22.
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
 * Complete the 'highestValuePalindrome' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. INTEGER n
 *  3. INTEGER k
 */

string highestValuePalindrome(const string& s, const int32_t n, const int32_t k) {
  string output(s);

  if (k >= n) {
    std::for_each(output.begin(), output.end(), [](char& ch) { ch = '9'; });
    return output;
  }

  const size_t mid = n / 2;
  int32_t numChanges = 0;

  for (size_t i = 0; i < mid; ++i) {
    if (output[i] != output[n - i - 1]) {
      if (numChanges == k) {
        output = "-1";
        return output;
      }

      output[i] = std::max(output[i], output[n - i - 1]);
      output[n - i - 1] = output[i];
      numChanges++;
    }
  }

  for (size_t i = 0; i < mid; ++i) {
    if (output[i] != '9') {
      if ((output[i] != s[i]) || (output[n - i - 1] != s[n - i - 1])) {
        if (numChanges == k) {
          return output;
        }

        numChanges++;
      } else {
        if (numChanges >= (k - 1)) {
          continue;
        }

        numChanges += 2;
      }

      output[i] = '9';
      output[n - i - 1] = '9';

      if (numChanges == k) {
        return output;
      }
    }
  }

  if (n % 2) {
    if (numChanges < k) {
      output[mid] = '9';
    }
  }

  return output;
}

TEST_CASE("richie_rich", "[problem_solving][medium]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  string first_multiple_input_temp;
  getline(cin, first_multiple_input_temp);

  vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

  int n = stoi(first_multiple_input[0]);

  int k = stoi(first_multiple_input[1]);

  string s;
  getline(cin, s);

  string result = highestValuePalindrome(s, n, k);

  fout << result << "\n";

  fout.close();
}
