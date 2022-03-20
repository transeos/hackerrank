// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/c-tutorial-basic-data-types/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 20/03/22.
//
//*****************************************************************

#include <bits/stdc++.h>
#include <catch2/catch.hpp>
#include <cstdio>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::tuple;
using std::unordered_map;

unordered_map<string, const char*> PrintfTypes;

template <size_t T>
void GetTupleInput(auto& inputTuple) {
  if constexpr (T > 1) {
    GetTupleInput<T - 1>(inputTuple);
  }

  cin >> std::get<T - 1>(inputTuple);
}

template <size_t N, size_t T = 0>
void PrintTupleInput(auto& inputTuple) {
  printf(PrintfTypes.at(typeid(std::get<T>(inputTuple)).name()), std::get<T>(inputTuple));
  cout << endl;

  if constexpr ((T + 1) < N) {
    PrintTupleInput<N, T + 1>(inputTuple);
  }
}

TEST_CASE("basic_data_types", "[cpp][easy]") {
  tuple<int32_t, int64_t, char, float, double> items = {0, 0, '\0', 0, 0};

  PrintfTypes[typeid(std::get<0>(items)).name()] = "%d";
  PrintfTypes[typeid(std::get<1>(items)).name()] = "%ld";
  PrintfTypes[typeid(std::get<2>(items)).name()] = "%c";
  PrintfTypes[typeid(std::get<3>(items)).name()] = "%f";
  PrintfTypes[typeid(std::get<4>(items)).name()] = "%lf";

  GetTupleInput<std::tuple_size_v<decltype(items)>>(items);
  PrintTupleInput<std::tuple_size_v<decltype(items)>>(items);
}
