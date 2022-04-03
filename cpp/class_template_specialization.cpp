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

#include <catch2/catch.hpp>
#include <iostream>

using namespace std;

enum class Fruit { apple, orange, pear };
enum class Color { red, green, orange };

template <typename T>
struct Traits;

template <typename T>
struct Traits {
  static string name(const int index) {
    if ((index < 0) || (index > 2)) {
      return "unknown";
    }

    if constexpr (std::is_same_v<T, Fruit> || std::is_same_v<T, Color>) {
      return output[index];
    } else {
      return "unknown";
    }
  }

 private:
  static array<string, 3> output;
};

template <>
array<string, 3> Traits<Fruit>::output = {"apple", "orange", "pear"};
template <>
array<string, 3> Traits<Color>::output = {"red", "green", "orange"};

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
