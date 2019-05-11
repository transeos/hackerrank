// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/c-tutorial-struct/problem
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

/*
    add code for struct here.
*/
typedef struct {
  int age;
  string first_name;
  string last_name;
  int standard;
} Student;

TEST_CASE("struct", "[cpp][easy]") {
  Student st;

  cin >> st.age >> st.first_name >> st.last_name >> st.standard;
  cout << st.age << " " << st.first_name << " " << st.last_name << " " << st.standard;
}
