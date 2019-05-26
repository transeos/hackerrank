// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/triple-sum/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 27/05/19.
//
//*****************************************************************

#include <bits/stdc++.h>
#include <iostream>

#include "utils.h"
#include <catch2/catch.hpp>

using namespace std;

vector<int> getPrunnedSet(const vector<int>& arr) {
  set<int> s;
  for (int num : arr) {
    s.insert(num);
  }

  vector<int> prunned_arr;
  for (int num : s) {
    prunned_arr.push_back(num);
  }

  return prunned_arr;
}

int getEndIdx(const vector<int>& arr, const int limit) {
  auto iter = lower_bound(arr.begin(), arr.end(), limit);
  if (iter == arr.end()) {
    return (arr.size() - 1);
  }

  int end = (iter - arr.begin());
  return ((arr[end] > limit) ? (end - 1) : end);
}

// Complete the triplets function below.
long triplets(vector<int>& a, vector<int>& b, vector<int>& c) {
  vector<int>&& a_prunned = getPrunnedSet(a);
  vector<int>&& b_prunned = getPrunnedSet(b);
  vector<int>&& c_prunned = getPrunnedSet(c);

  long int_triplets = 0;

  for (const int elem_b : b_prunned) {
    const long end_a = getEndIdx(a_prunned, elem_b);
    if (end_a < 0) {
      continue;
    }

    const long end_c = getEndIdx(c_prunned, elem_b);
    if (end_c < 0) {
      continue;
    }

    int_triplets += ((end_a + 1) * (end_c + 1));
  }

  return int_triplets;
}

TEST_CASE("triple_sum", "[interview_prep_kit][search][medium]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  string lenaLenbLenc_temp;
  getline(cin, lenaLenbLenc_temp);

  vector<string> lenaLenbLenc = split_string(lenaLenbLenc_temp);

  int lena = stoi(lenaLenbLenc[0]);

  int lenb = stoi(lenaLenbLenc[1]);

  int lenc = stoi(lenaLenbLenc[2]);

  string arra_temp_temp;
  getline(cin, arra_temp_temp);

  vector<string> arra_temp = split_string(arra_temp_temp);

  vector<int> arra(lena);

  for (int i = 0; i < lena; i++) {
    int arra_item = stoi(arra_temp[i]);

    arra[i] = arra_item;
  }

  string arrb_temp_temp;
  getline(cin, arrb_temp_temp);

  vector<string> arrb_temp = split_string(arrb_temp_temp);

  vector<int> arrb(lenb);

  for (int i = 0; i < lenb; i++) {
    int arrb_item = stoi(arrb_temp[i]);

    arrb[i] = arrb_item;
  }

  string arrc_temp_temp;
  getline(cin, arrc_temp_temp);

  vector<string> arrc_temp = split_string(arrc_temp_temp);

  vector<int> arrc(lenc);

  for (int i = 0; i < lenc; i++) {
    int arrc_item = stoi(arrc_temp[i]);

    arrc[i] = arrc_item;
  }

  long ans = triplets(arra, arrb, arrc);

  fout << ans << "\n";

  fout.close();
}
