// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/virtual-functions/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 12/05/19.
//
//*****************************************************************

#include <algorithm>
#include <array>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <numeric>
#include <vector>

#include <catch2/catch.hpp>

using namespace std;

#define NUM_MARKS 6

class Person {
 public:
  Person() {}
  virtual ~Person() {}

 protected:
  string name_;
  int age_{0};

 public:
  virtual void getdata() = 0;
  virtual void putdata() const = 0;
};

class Professor : public Person {
 public:
  Professor() : Person() {
    cur_id_ = ++num_professors;
  }
  virtual ~Professor() {}

 private:
  int publications_{0};
  int cur_id_{0};

  static int num_professors;

 public:
  virtual void getdata() override {
    cin >> name_ >> age_ >> publications_;
  }

  virtual void putdata() const override {
    cout << name_ << " " << age_ << " " << publications_ << " " << cur_id_ << endl;
  }
};
int Professor::num_professors = 0;

class Student : public Person {
 public:
  Student() : Person() {
    cur_id_ = ++num_students;
  }
  ~Student() {}

 private:
  std::array<int, NUM_MARKS> marks_;
  int cur_id_;

  static int num_students;

 public:
  virtual void getdata() override {
    cin >> name_ >> age_;
    for (int idx = 0; idx < NUM_MARKS; ++idx) {
      cin >> marks_[idx];
    }
  }

  virtual void putdata() const override {
    cout << name_ << " " << age_ << " " << accumulate(marks_.begin(), marks_.end(), 0) << " "
         << cur_id_ << endl;
  }
};
int Student::num_students = 0;

TEST_CASE("virtual_functions", "[cpp][medium]") {
  int n, val;
  cin >> n;  // The number of objects that is going to be created.
  Person* per[n];

  for (int i = 0; i < n; i++) {
    cin >> val;
    if (val == 1) {
      // If val is 1 current object is of type Professor
      per[i] = new Professor;

    } else
      per[i] = new Student;  // Else the current object is of type Student

    per[i]->getdata();  // Get the data from the user.
  }

  for (int i = 0; i < n; i++) per[i]->putdata();  // Print the required output for each object.
}
