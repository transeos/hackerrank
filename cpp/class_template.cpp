// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/c-class-templates/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 11/05/19.
//
//*****************************************************************

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>

#include <catch2/catch.hpp>

using namespace std;

/*Write the class AddElements here*/
template <typename T>
class AddElements {
 public:
  AddElements(const T& element) : element_(element) {}
  ~AddElements() {}

 private:
  T element_;

 public:
  T add(const T& element);
  const T& concatenate(const T&);
};

// TODO: use SFINAE

template <>
int AddElements<int>::add(const int& element) {
  element_ += element;
  return element_;
}

template <>
double AddElements<double>::add(const double& element) {
  element_ += element;
  return element_;
}

template <>
const string& AddElements<string>::concatenate(const string& element) {
  element_.append(element);
  return element_;
}

TEST_CASE("class_template", "[cpp][easy][incomplete]") {
  int n, i;
  cin >> n;
  for (i = 0; i < n; i++) {
    string type;
    cin >> type;
    if (type == "float") {
      double element1, element2;
      cin >> element1 >> element2;
      AddElements<double> myfloat(element1);
      cout << myfloat.add(element2) << endl;
    } else if (type == "int") {
      int element1, element2;
      cin >> element1 >> element2;
      AddElements<int> myint(element1);
      cout << myint.add(element2) << endl;
    } else if (type == "string") {
      string element1, element2;
      cin >> element1 >> element2;
      AddElements<string> mystring(element1);
      cout << mystring.concatenate(element2) << endl;
    }
  }
}
