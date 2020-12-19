// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/attending-workshops/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 19/12/20.
//
//*****************************************************************

#include <bits/stdc++.h>
#include <catch2/catch.hpp>
#include <iostream>
#include <vector>

using namespace std;

// Define the structs Workshops and Available_Workshops.
// Implement the functions initialize and CalculateMaxWorkshops

class Workshop {
 public:
  Workshop(const int32_t start_time, const int32_t duration)
      : start_time_(start_time), end_time_(start_time + duration - 1) {}
  ~Workshop() {}

  int32_t GetStartTime() const {
    return start_time_;
  }
  int32_t GetEndTime() const {
    return end_time_;
  }

  friend ostream& operator<<(ostream& out, const Workshop& w) {
    out << "[" << w.GetStartTime() << "," << w.GetEndTime() << "]";
    return out;
  }

 private:
  int32_t start_time_;
  int32_t end_time_;
};

bool CompareWorkshopFn(const Workshop& lhs, const Workshop& rhs) {
  return ((lhs.GetEndTime() < rhs.GetEndTime()) ? true
                                                : ((lhs.GetEndTime() == rhs.GetEndTime()) &&
                                                   (lhs.GetStartTime() > rhs.GetStartTime())));
}

typedef vector<Workshop> Available_Workshops;

Available_Workshops* initialize(int* start_time_ptr, int* duration_ptr, const int num_workshops) {
  Available_Workshops* workshops = new Available_Workshops();

  for (size_t idx = 0; idx < num_workshops; ++idx) {
    workshops->push_back(Workshop(*start_time_ptr, *duration_ptr));
    start_time_ptr++;
    duration_ptr++;
  }

  return workshops;
}

int32_t CalculateMaxWorkshops(Available_Workshops* workshops) {
  // sort in increasing order of finish time
  sort(workshops->begin(), workshops->end(), CompareWorkshopFn);

  int32_t count = 1;
  int32_t cur_end_time = workshops->at(0).GetEndTime();

  // cout << workshops->at(0) << ", " << count << endl;

  for (size_t idx = 1; idx < workshops->size(); ++idx) {
    // cout << workshops->at(idx);

    if (workshops->at(idx).GetStartTime() > cur_end_time) {
      cur_end_time = workshops->at(idx).GetEndTime();
      count++;

      // cout << ", " << count;
    }

    // cout << endl;
  }

  return count;
}

TEST_CASE("attending_workshops", "[cpp][medium]") {
  int n;  // number of workshops
  cin >> n;
  // create arrays of unknown size n
  int* start_time = new int[n];
  int* duration = new int[n];

  for (int i = 0; i < n; i++) {
    cin >> start_time[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> duration[i];
  }

  Available_Workshops* ptr;
  ptr = initialize(start_time, duration, n);
  cout << CalculateMaxWorkshops(ptr) << endl;
  return;
}
