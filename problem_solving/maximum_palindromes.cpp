// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/maximum-palindromes/problem
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

#define MODNUM 1000000007L

/*
 * Complete the 'initialize' function below.
 *
 * The function accepts STRING s as parameter.
 */

string input = "";

class Factorial {
 private:
  static vector<uint64_t> _factorials;

  const size_t _n;

 public:
  Factorial(const uint64_t n) : _n(n) {
    if (_factorials.size() <= n) {
      const size_t prevSize = _factorials.size();
      _factorials.resize(n + 1);

      for (size_t i = prevSize; i <= n; ++i) {
        _factorials[i] = _factorials[i - 1] * i;
      }
    }
  }

  operator uint64_t() const {
    return _factorials[_n];
  }
};

vector<uint64_t> Factorial::_factorials(1, 0);

void initialize(const string& s) {
  // This function is called once before all queries.
  input = s;
}

/*
 * Complete the 'answerQuery' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER l
 *  2. INTEGER r
 */

constexpr int32_t answerQuery(const int32_t l, const int32_t r) {
  // Return the answer for this query modulo 1000000007.

  if (l >= r) {
    return 0;
  }

  std::array<int32_t, 26> letters = {};

  for (size_t i = l - 1; i < r; ++i) {
    letters[input[i] - 'a']++;
  }

  int32_t elmWithOddCount = 0;
  for (int32_t count : letters) {
    if (count % 2) {
      elmWithOddCount++;
    }
  }

  uint64_t numeratorFactorial = 0;
  uint64_t denominator = 1;

  for (int32_t count : letters) {
    const uint64_t countByHalf = count / 2;
    if (countByHalf != 0) {
      numeratorFactorial += countByHalf;
      denominator *= Factorial(countByHalf);
    }
  }

  if (numeratorFactorial == 0) {
    return elmWithOddCount;
  }

  uint64_t result = Factorial(numeratorFactorial) / denominator;
  result *= elmWithOddCount;

  return result % MODNUM;
}

TEST_CASE("maximum_palindromes", "[problem_solving][medium][ToDo]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  string s;
  getline(cin, s);

  initialize(s);

  string q_temp;
  getline(cin, q_temp);

  int q = stoi(ltrim(rtrim(q_temp)));

  for (int q_itr = 0; q_itr < q; q_itr++) {
    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int l = stoi(first_multiple_input[0]);

    int r = stoi(first_multiple_input[1]);

    int result = answerQuery(l, r);

    fout << result << "\n";
  }

  fout.close();
}
