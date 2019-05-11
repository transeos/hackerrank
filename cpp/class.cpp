// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/c-tutorial-class/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 12/05/19.
//
//*****************************************************************

#include <iostream>
#include <sstream>

#include <catch2/catch.hpp>

using namespace std;

/*
Enter code for class Student here.
Read statement for specification.
*/
class Student {
 public:
  Student() {}
  ~Student() {}

 private:
  int age_{0};
  string first_name_;
  string last_name_;
  int standard_{0};

 public:
  void set_age(int age) {
    age_ = age;
  }
  int get_age() const {
    return age_;
  }

  void set_first_name(const string& first_name) {
    first_name_ = first_name;
  }
  const string& get_first_name() const {
    return first_name_;
  }

  void set_last_name(const string& last_name) {
    last_name_ = last_name;
  }
  const string& get_last_name() const {
    return last_name_;
  }

  void set_standard(int standard) {
    standard_ = standard;
  }
  int get_standard() const {
    return standard_;
  }

  string to_string() const {
    return std::to_string(age_) + "," + first_name_ + "," + last_name_ + "," +
           std::to_string(standard_);
  }
};

TEST_CASE("class", "[cpp][easy]") {
  int age, standard;
  string first_name, last_name;

  cin >> age >> first_name >> last_name >> standard;

  Student st;
  st.set_age(age);
  st.set_standard(standard);
  st.set_first_name(first_name);
  st.set_last_name(last_name);

  cout << st.get_age() << "\n";
  cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
  cout << st.get_standard() << "\n";
  cout << "\n";
  cout << st.to_string();
}
