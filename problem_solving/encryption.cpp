// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/encryption/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 22/05/22.
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
 * Complete the 'encryption' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string encryption(const string& s) {
  const size_t inputLen = s.length();
  if (inputLen <= 1) {
    return s;
  }

  // max word length
  size_t maxWordLen = std::sqrt(inputLen);
  // number of words
  size_t numWords = maxWordLen + 1;

  if ((maxWordLen * maxWordLen) == inputLen) {
    numWords = maxWordLen;
  } else if (maxWordLen * numWords < inputLen) {
    maxWordLen++;
  }

  const size_t shortWordIndexStart = numWords - ((maxWordLen * numWords) - inputLen);

  string output(inputLen + numWords - 1, ' ');

  for (size_t i = 0; i < inputLen; ++i) {
    const size_t wordIndex = i % numWords;
    const size_t posInWord = i / numWords;

    size_t encryptedIndex = (wordIndex * (maxWordLen + 1)) + posInWord;
    if (wordIndex > shortWordIndexStart) {
      encryptedIndex -= wordIndex - shortWordIndexStart;
    }

    assert(output[encryptedIndex] == ' ');
    output[encryptedIndex] = s[i];
  }

  return output;
}

TEST_CASE("encryption", "[problem_solving][medium]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  string s;
  getline(cin, s);

  string result = encryption(s);

  fout << result << "\n";

  fout.close();
}
