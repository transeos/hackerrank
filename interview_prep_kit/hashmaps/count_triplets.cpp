// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/count-triplets-1/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 01/01/21.
//
//*****************************************************************

#include "utils.h"
#include <bits/stdc++.h>
#include <catch2/catch.hpp>
#include <iostream>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);
vector<string> split(const string&);

// Complete the countTriplets function below.
long countTriplets(const vector<long>& arr, const long r) {
  uint64_t num_triplets = 0;

  // special case: r = 1
  if (r == 1) {
    unordered_map<long, uint64_t> elements;

    for (const long num : arr) {
      auto iter = elements.find(num);
      if (iter != elements.end()) {
        iter->second++;
        if (iter->second > 2) {
          num_triplets += ((iter->second - 2) * (iter->second - 1));
        }
      } else {
        elements[num] = 1;
      }
    }
    num_triplets >>= 1;
    return num_triplets;
  }

  map<long, int> powers;

  long max_power_val = 1;
  int max_power = 0;
  powers[1] = 0;

  map<long, vector<int>> sequence;
  sequence[1] = vector<int>();
  long max_key = 1;

  for (const long num : arr) {
    while ((num > max_power_val) && MultiplicationIsSafe(max_power_val, r)) {
      max_power_val *= r;
      max_power++;
      powers[max_power_val] = max_power;
    }

    auto iter = powers.find(num);
    if (iter != powers.end()) {
      sequence[1].push_back(iter->second);
    } else {
      long key = num;
      int value = 0;

      for (auto& power_iter : powers) {
        const long possible_key = (num / power_iter.first);
        if ((possible_key * power_iter.first) == num) {
          key = possible_key;
          value = power_iter.second;
        } else {
          break;
        }
      }

      auto iter2 = sequence.find(key);
      if (iter2 != sequence.end()) {
        iter2->second.push_back(value);
      } else {
        sequence[key] = vector<int>(1, value);
      }
    }
  }

  for (auto& iter : sequence) {
    // key : power, value = count
    unordered_map<int, uint64_t> singles;

    // key : (power - 1) << 8 + power, value = count
    unordered_map<int, uint64_t> pairs;

    // key : (power - 2) << 16 + (power - 1) << 8 + power, value = count
    unordered_map<int, uint64_t> triplets;

    for (int power : iter.second) {
      auto iter1 = singles.find(power);
      if (iter1 == singles.end()) {
        singles[power] = 1;
      } else {
        iter1->second++;
      }

      if (power < 1) {
        continue;
      }

      iter1 = singles.find(power - 1);
      if (iter1 == singles.end()) {
        continue;
      }

      int key2 = (((power - 1) << 8) + power);
      auto iter2 = pairs.find(key2);

      if (iter2 == pairs.end()) {
        pairs[key2] = iter1->second;
      } else {
        iter2->second += iter1->second;
      }

      if (power < 2) {
        continue;
      }

      key2 = (((power - 2) << 8) + (power - 1));
      iter2 = pairs.find(key2);
      if (iter2 == pairs.end()) {
        continue;
      }

      int key3 = ((key2 << 8) + power);
      auto iter3 = triplets.find(key3);

      if (iter3 == triplets.end()) {
        triplets[key3] = iter2->second;
      } else {
        iter3->second += iter2->second;
      }
    }

    for (auto iter3 : triplets) {
      num_triplets += iter3.second;
    }
  }

  return num_triplets;
}

TEST_CASE("count_triplets", "[interview_prep_kit][recursion][medium][star]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  string nr_temp;
  getline(cin, nr_temp);

  vector<string> nr = split(rtrim(nr_temp));

  int n = stoi(nr[0]);

  long r = stol(nr[1]);

  string arr_temp_temp;
  getline(cin, arr_temp_temp);

  vector<string> arr_temp = split(rtrim(arr_temp_temp));

  vector<long> arr(n);

  for (int i = 0; i < n; i++) {
    long arr_item = stol(arr_temp[i]);

    arr[i] = arr_item;
  }

  long ans = countTriplets(arr, r);

  fout << ans << "\n";

  fout.close();
}

string ltrim(const string& str) {
  string s(str);

  s.erase(s.begin(), find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

  return s;
}

string rtrim(const string& str) {
  string s(str);

  s.erase(find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(), s.end());

  return s;
}

vector<string> split(const string& str) {
  vector<string> tokens;

  string::size_type start = 0;
  string::size_type end = 0;

  while ((end = str.find(" ", start)) != string::npos) {
    tokens.push_back(str.substr(start, end - start));

    start = end + 1;
  }

  tokens.push_back(str.substr(start));

  return tokens;
}
