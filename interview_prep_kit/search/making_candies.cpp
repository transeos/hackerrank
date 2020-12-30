// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/making-candies/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 21/12/20.
//
//*****************************************************************
//
// Test case 4 : 1 1 1000000000000 1000000000000, output: 1000000000000
// Test case 7 : 1 100 10000000000 1000000000000, output: 617737754
// Test case 8 : 123456789012 215987654321 50000000000 1000000000000, output: 1
// Test case 9 : 1 1 499999999999 1000000000000, output: 999999999999
// Test case 10: 4294967296 4294967296 10 10000, output: 1
// Test case 21*: 5361 3918 8447708 989936375520, output: 3577

#include "utils.h"
#include <bits/stdc++.h>
#include <catch2/catch.hpp>
#include <iostream>

using namespace std;

// r1 > r2
bool BalanceMachinesAndWorkers(const uint64_t r1, uint64_t& r2, uint64_t& c, const uint64_t p,
                               const uint64_t n, uint64_t& max_resource_increment) {
  assert(r1 > r2);

  if (r2 <= ((n - c) / p)) {
    // r1 is too high, increase r2 if possible

    if (max_resource_increment > (r1 - r2)) {
      max_resource_increment = (r1 - r2);
    }

    r2 += max_resource_increment;
    c -= (max_resource_increment * p);

    max_resource_increment = (c / p);

    return true;
  }
  return false;
}

// r1 = r2
bool FindMaxIncrement(uint64_t& r1, uint64_t& r2, uint64_t& c, const uint64_t p, const uint64_t n,
                      const uint64_t max_resource_increment) {
  assert(r1 == r2);

  double factor = (sqrt((c / (n - c)) + 1) + 1);
  factor = ((factor * (n - c)) / (2 * p));

  if (r1 < factor) {
    c -= (max_resource_increment * p);
    r2 += (max_resource_increment / 2);
    r1 = (r2 + (max_resource_increment % 2));

    return true;
  }
  return false;
}

// Complete the minimumPasses function below.
uint64_t minimumPasses(uint64_t m, uint64_t w, const uint64_t p, const uint64_t n) {
  if (!MultiplicationIsSafe(m, w)) {
    return 1;
  }
  // current number of candles
  uint64_t c = (m * w);

  if (p >= n) {
    return ((n + c - 1) / c);
  }

  uint64_t num_passes = 1;

  bool balance = true;
  bool find_max = true;

  while (c < n) {
    if (!find_max) {
      if (!MultiplicationIsSafe(m, w)) {
        return (num_passes + 1);
      }
      const uint64_t cur_pwr = (m * w);

      return (num_passes + ((n - c + cur_pwr - 1) / cur_pwr));
    }

    uint64_t max_resource_increment = (c / p);
    if (max_resource_increment) {
      if (balance) {
        if (m > w) {
          balance = BalanceMachinesAndWorkers(m, w, c, p, n, max_resource_increment);
        } else if (m < w) {
          balance = BalanceMachinesAndWorkers(w, m, c, p, n, max_resource_increment);
        }
      }

      if ((m == w) && max_resource_increment) {
        find_max = FindMaxIncrement(m, w, c, p, n, max_resource_increment);
      }

      if (!MultiplicationIsSafe(m, w)) {
        return (num_passes + 1);
      }
      c += (m * w);
      num_passes++;
    } else {
      if (!MultiplicationIsSafe(m, w)) {
        return (num_passes + 1);
      }
      const uint64_t cur_pwr = (m * w);

      const uint64_t new_passes = ((p - c + cur_pwr - 1) / cur_pwr);

      c += (cur_pwr * new_passes);
      num_passes += new_passes;
    }
  }

  return num_passes;
}

TEST_CASE("making_candies", "[interview_prep_kit][search][hard][star][incomplete][failed]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  string mwpn_temp;
  getline(cin, mwpn_temp);

  vector<string> mwpn = split_string(mwpn_temp);

  long m = stol(mwpn[0]);

  long w = stol(mwpn[1]);

  long p = stol(mwpn[2]);

  long n = stol(mwpn[3]);

  long result = minimumPasses(m, w, p, n);

  fout << result << "\n";

  fout.close();
}
