// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/cpp-class-template-specialization/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 19/05/19.
//
//*****************************************************************

#include <iostream>

#include <catch2/catch.hpp>

using namespace std;

enum class Fruit { apple, orange, pear };
enum class Color { red, green, orange };

template <typename T>
struct Traits;

string printFruitName(int index) {
  switch (static_cast<Fruit>(index)) {
    case Fruit::apple:
      return "apple";
    case Fruit::orange:
      return "orange";
    case Fruit::pear:
      return "pear";
    default:
      return "unknown";
  }
}

string printColorName(int index) {
  switch (static_cast<Color>(index)) {
    case Color::red:
      return "red";
    case Color::green:
      return "green";
    case Color::orange:
      return "orange";
    default:
      return "unknown";
  }
}

// Define specializations for the Traits class template here.
template <typename T>
struct Traits {
  // std::function<const char*(int)> name;
  static string (*name)(int);
};

template <>
string (*Traits<Fruit>::name)(int) = printFruitName;
template <>
string (*Traits<Color>::name)(int) = printColorName;

TEST_CASE("class_template_specialization", "[cpp][medium]") {
  int t = 0;
  std::cin >> t;

  for (int i = 0; i != t; ++i) {
    int index1;
    std::cin >> index1;
    int index2;
    std::cin >> index2;
    cout << Traits<Color>::name(index1) << " ";
    cout << Traits<Fruit>::name(index2) << "\n";
  }
}
