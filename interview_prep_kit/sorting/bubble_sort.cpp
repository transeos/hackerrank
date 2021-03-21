// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/ctci-bubble-sort/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 26/05/19.
//
//*****************************************************************

#include "utils.h"
#include <bits/stdc++.h>
#include <catch2/catch.hpp>
#include <iostream>

using namespace std;

// Complete the countSwaps function below.
void countSwaps(vector<int>& a) {
  int num_swaps = 0;

  const int num_elements = a.size();
  for (int i = 0; i < (num_elements - 1); i++) {
    for (int j = 0; j < (num_elements - i - 1); j++) {
      // Swap adjacent elements if they are in decreasing order
      if (a[j] > a[j + 1]) {
        swap(a[j], a[j + 1]);
        num_swaps++;
      }
    }
  }

  cout << "Array is sorted in " << num_swaps << " swaps.\n";
  cout << "First Element: " << a[0] << endl;
  cout << "Last Element: " << a[num_elements - 1];
}

TEST_CASE("bubble_sort", "[interview_prep_kit][sorting][easy]") {
  int n;
  cin >> n;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  string a_temp_temp;
  getline(cin, a_temp_temp);

  vector<string> a_temp = split_string(a_temp_temp);

  vector<int> a(n);

  for (int i = 0; i < n; i++) {
    int a_item = stoi(a_temp[i]);

    a[i] = a_item;
  }

  countSwaps(a);
}
