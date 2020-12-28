// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/torque-and-development/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 28/12/19.
//
//*****************************************************************

#include "utils.h"
#include <bits/stdc++.h>
#include <catch2/catch.hpp>
#include <iostream>

using namespace std;

class City {
 public:
  City() : index_(-1) {}
  ~City() {}

  int32_t GetIndex() const {
    return index_;
  }
  void SetIndex(int32_t index) {
    assert(index_ == -1);
    index_ = index;
  }

  void AddAdjacency(const int city) {
    adjacency_.push_back(city);
  }

  void AdjacencyIter(std::function<void(int)> lambda) const {
    for (int32_t index : adjacency_) {
      lambda(index);
    }
  }

 private:
  vector<int32_t> adjacency_;

  int32_t index_;
};

class Country {
 public:
  Country(const long n) : cities_(n) {}
  ~Country() {}

  void AddRoad(const int city1, const int city2) {
    cities_[city1 - 1].AddAdjacency(city2 - 1);
    cities_[city2 - 1].AddAdjacency(city1 - 1);
  }

  int64_t BuildRoadsAndLibraries(const int c_lib, const int c_road) {
    // mark cities with highest connectivity as root
    int64_t disjoint_idx = -1;

    for (size_t idx = 0; idx < cities_.size(); ++idx) {
      if (cities_[idx].GetIndex() == -1) {
        disjoint_idx++;
        VisitAdjacentCities(idx, disjoint_idx);
      }
    }

    // cout << "Number of Libraries = " << (disjoint_idx + 1) << endl;
    const int64_t library_cost = ((disjoint_idx + 1) * c_lib);

    // cout << "Number of Roads = " << (cities_.size() - disjoint_idx - 1) << endl << endl;
    const int64_t road_cost = ((cities_.size() - disjoint_idx - 1) * c_road);

    return (road_cost + library_cost);
  }

 private:
  vector<City> cities_;

  // returns city with highest connectivity
  void VisitAdjacentCities(const int cur_idx, const int disjoint_idx) {
    if (cities_[cur_idx].GetIndex() == disjoint_idx) {
      return;
    }

    assert(cities_[cur_idx].GetIndex() == -1);
    cities_[cur_idx].SetIndex(disjoint_idx);

    cities_[cur_idx].AdjacencyIter(
        [g = this, disjoint_idx](int index) { g->VisitAdjacentCities(index, disjoint_idx); });
  }
};

// Complete the roadsAndLibraries function below.
long roadsAndLibraries(const int n, const int c_lib, const int c_road,
                       const vector<vector<int>>& cities) {
  if (c_lib <= c_road) {
    // special case: road building cost is more than library
    int64_t max_cost = ((int64_t)c_lib * (int64_t)n);
    return max_cost;
  }

  Country country(n);

  for (size_t idx = 0; idx < cities.size(); ++idx) {
    country.AddRoad(cities[idx][0], cities[idx][1]);
  }

  return country.BuildRoadsAndLibraries(c_lib, c_road);
}

TEST_CASE("roads_libraries", "[interview_prep_kit][graph][medium][star]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  int q;
  cin >> q;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  for (int q_itr = 0; q_itr < q; q_itr++) {
    string nmC_libC_road_temp;
    getline(cin, nmC_libC_road_temp);

    vector<string> nmC_libC_road = split_string(nmC_libC_road_temp);

    int n = stoi(nmC_libC_road[0]);

    int m = stoi(nmC_libC_road[1]);

    int c_lib = stoi(nmC_libC_road[2]);

    int c_road = stoi(nmC_libC_road[3]);

    vector<vector<int>> cities(m);
    for (int i = 0; i < m; i++) {
      cities[i].resize(2);

      for (int j = 0; j < 2; j++) {
        cin >> cities[i][j];
      }

      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    long result = roadsAndLibraries(n, c_lib, c_road, cities);

    fout << result << "\n";
  }

  fout.close();
}
