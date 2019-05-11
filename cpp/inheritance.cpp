// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/inheritance-introduction/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 12/05/19.
//
//*****************************************************************

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>

#include <catch2/catch.hpp>

using namespace std;

class Triangle {
 public:
  void triangle() {
    cout << "I am a triangle\n";
  }
};

class Isosceles : public Triangle {
 public:
  void isosceles() {
    cout << "I am an isosceles triangle\n";
  }
  // Write your code here.
  void description() const {
    cout << "In an isosceles triangle two sides are equal\n";
  }
};

TEST_CASE("inheritance", "[cpp][easy]") {
  Isosceles isc;
  isc.isosceles();
  isc.description();
  isc.triangle();
}
