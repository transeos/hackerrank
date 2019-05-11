// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/c-tutorial-basic-data-types/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 12/05/19.
//
//*****************************************************************

#include <cstdio>
#include <iostream>
#include <tuple>

#include <catch2/catch.hpp>

using namespace std;

TEST_CASE("basic_data_types", "[cpp][easy]") {
  // Complete the code.

  tuple<int, long, char, float, double> items = {0, 0, '\0', 0, 0};
  scanf("%d %ld %c %f %lf", &(get<0>(items)), &(get<1>(items)), &(get<2>(items)), &(get<3>(items)),
        &(get<4>(items)));
  printf("%d\n%ld\n%c\n%f\n%lf\n", get<0>(items), get<1>(items), get<2>(items), get<3>(items),
         get<4>(items));
}
