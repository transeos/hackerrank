// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/multi-level-inheritance-cpp/problem
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
};

// Write your code here.
class Equilateral : public Isosceles {
 public:
  Equilateral() : Isosceles() {}
  ~Equilateral() {}

  void equilateral() const {
    cout << "I am an equilateral triangle\n";
  }
};

TEST_CASE("multi_level_inheritance", "[cpp][easy]") {
  Equilateral eqr;
  eqr.equilateral();
  eqr.isosceles();
  eqr.triangle();
}
