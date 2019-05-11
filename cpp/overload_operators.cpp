// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/overload-operators/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 12/05/19.
//
//*****************************************************************

#include <iostream>

#include <catch2/catch.hpp>

using namespace std;

class Complex {
 public:
  int a, b;
  void input(string s) {
    int v1 = 0;
    int i = 0;
    while (s[i] != '+') {
      v1 = v1 * 10 + s[i] - '0';
      i++;
    }
    while (s[i] == ' ' || s[i] == '+' || s[i] == 'i') {
      i++;
    }
    int v2 = 0;
    while (i < s.length()) {
      v2 = v2 * 10 + s[i] - '0';
      i++;
    }
    a = v1;
    b = v2;
  }
};

// Overload operators + and << for the class complex
//+ should add two complex numbers as (a+ib) + (c+id) = (a+c) + i(b+d)
//<< should print a complex number in the format "a+ib"

Complex operator+(const Complex& x, const Complex& y) {
  Complex z;
  z.a = (x.a + y.a);
  z.b = (x.b + y.b);
  return z;
}

ostream& operator<<(ostream& os, const Complex& z) {
  os << z.a << "+i" << z.b;
  return os;
}

TEST_CASE("overload_operators", "[cpp][easy]") {
  Complex x, y;
  string s1, s2;
  cin >> s1;
  cin >> s2;
  x.input(s1);
  y.input(s2);
  Complex z = x + y;
  cout << z << endl;
}
