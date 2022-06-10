// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/sansa-and-xor/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 21/03/21.
//
//*****************************************************************

#include "utils.h"
#include <bits/stdc++.h>
#include <catch2/catch.hpp>

using namespace std;

// Complete the sansaXor function below.
int sansaXor(const vector<int>& arr) {
  const size_t N = arr.size();

  // count of ith element in xor expr = (i + 1)(N + i), i <= (N-1/2)
  // i = odd, total count is even
  // i = even, N = even, total count is even
  // i = even, N = odd, toal count is odd

  if ((N % 2) == 0) {
    return 0;
  }

  int xor_out = 0;

  for (size_t idx = 0; idx < N; idx += 2) {
    xor_out ^= arr[idx];
  }

  return xor_out;
}

TEST_CASE("sansa_xor", "[problem_solving][medium]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  int t;
  cin >> t;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  for (int t_itr = 0; t_itr < t; t_itr++) {
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
      int arr_item = stoi(arr_temp[i]);

      arr[i] = arr_item;
    }

    int result = sansaXor(arr);

    fout << result << "\n";
  }

  fout.close();
}
