// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/overloading-ostream-operator/problem
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

class Person {
 public:
  Person(const string& first_name, const string& last_name)
      : first_name_(first_name), last_name_(last_name) {}
  const string& get_first_name() const {
    return first_name_;
  }
  const string& get_last_name() const {
    return last_name_;
  }

 private:
  string first_name_;
  string last_name_;
};
// Enter your code here.

ostream& operator<<(ostream& os, const Person& p) {
  cout << "first_name=" << p.get_first_name() << ",last_name=" << p.get_last_name();
  return os;
}

TEST_CASE("overloading_ostream_operator", "[cpp][medium]") {
  string first_name, last_name, event;
  cin >> first_name >> last_name >> event;
  auto p = Person(first_name, last_name);
  cout << p << " " << event << endl;
}
