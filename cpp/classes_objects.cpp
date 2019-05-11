// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/classes-objects/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 12/05/19.
//
//*****************************************************************

#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <numeric>
#include <vector>

#include <catch2/catch.hpp>

using namespace std;

#define NUM_EXAMS 5

// Write your Student class here
class Student {
 public:
  Student() {
    for (int idx = 0; idx < NUM_EXAMS; ++idx) {
      scores_[idx] = 0;
    }
  }
  ~Student() {}

 private:
  array<int, NUM_EXAMS> scores_;

 public:
  void input() {
    for (int idx = 0; idx < NUM_EXAMS; ++idx) {
      cin >> scores_[idx];
    }
  }

  int calculateTotalScore() const {
    return accumulate(scores_.begin(), scores_.end(), 0);
  }
};

TEST_CASE("classes_objects", "[cpp][easy]") {
  int n;  // number of students
  cin >> n;
  Student* s = new Student[n];  // an array of n students

  for (int i = 0; i < n; i++) {
    s[i].input();
  }

  // calculate kristen's score
  int kristen_score = s[0].calculateTotalScore();

  // determine how many students scored higher than kristen
  int count = 0;
  for (int i = 1; i < n; i++) {
    int total = s[i].calculateTotalScore();
    if (total > kristen_score) {
      count++;
    }
  }

  // print result
  cout << count;
}
