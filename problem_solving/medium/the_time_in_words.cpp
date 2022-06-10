// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/the-time-in-words/problem
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
 * Complete the 'timeInWords' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. INTEGER h
 *  2. INTEGER m
 */

string timeInWords(const int32_t h, const int32_t m) {
  assert(h > 0 && h <= 12 && m >= 0 && m < 60);

  string result = "";

  std::unordered_map<int32_t, string> numToString;
  numToString[1] = "one";
  numToString[2] = "two";
  numToString[3] = "three";
  numToString[4] = "four";
  numToString[5] = "five";
  numToString[6] = "six";
  numToString[7] = "seven";
  numToString[8] = "eight";
  numToString[9] = "nine";
  numToString[10] = "ten";
  numToString[11] = "eleven";
  numToString[12] = "twelve";
  numToString[13] = "thirteen";
  numToString[20] = "twenty";

  int32_t min = m;
  int32_t hour = h;
  string middlePart = " past ";

  if (m > 30) {
    min = 60 - m;
    hour = h == 12 ? 1 : h + 1;
    middlePart = " to ";
  }

  if (min == 0) {
    result = numToString[hour] + " o' clock";
    return result;
  }

  if (min == 15) {
    result = "quarter";
  } else if (min == 30) {
    result = "half";
  } else {
    middlePart = (min == 1 ? " minute" : " minutes") + middlePart;

    if (min < 14 || min == 20) {
      result = numToString[min];
    } else if (min < 20) {
      result = numToString[min % 10] + "teen";
    } else {
      result = numToString[20] + " " + numToString[min % 10];
    }
  }

  result += middlePart + numToString[hour];

  return result;
}

TEST_CASE("the_time_in_words", "[problem_solving][medium]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  string h_temp;
  getline(cin, h_temp);

  int h = stoi(ltrim(rtrim(h_temp)));

  string m_temp;
  getline(cin, m_temp);

  int m = stoi(ltrim(rtrim(m_temp)));

  string result = timeInWords(h, m);

  fout << result << "\n";

  fout.close();
}
