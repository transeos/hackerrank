// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/matrix/problem
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

//#define DEBUG_MATRIX_ZION

using namespace std;

bool IsNumber(const std::string& s) {
  return (!s.empty() && std::find_if(s.begin(), s.end(),
                                     [](unsigned char c) { return !std::isdigit(c); }) == s.end());
}

class City {
 public:
  City() : machine_(false), visited_(false) {}
  ~City() {}

  array<int32_t, 3> min_cut_;
  bool HasMachine() const {
    return machine_;
  }
  void SetMachine() {
    machine_ = true;
  }

  void AddRoad(const int road) {
    roads_.insert(road);
  }
  void RemoveRoad(const int road) {
    roads_.erase(road);
  }

  bool IsVisited() const {
    return visited_;
  }
  void SetVisited() {
    visited_ = true;
  }

 private:
  unordered_set<int> roads_;

  bool machine_;

  bool visited_;

 public:
  auto GetRoads() const -> const decltype(roads_)& {
    return roads_;
  }
};

class Road {
 public:
  Road(const int city1, const int city2, int time) : city1_(city1), city2_(city2), time_(time) {}
  ~Road() {}

  int GetCity1() const {
    return city1_;
  }
  int GetCity2() const {
    return city2_;
  }
  int GetOtherCity(const int city) const {
    return ((city == city1_) ? city2_ : city1_);
  }

  long GetTime() const {
    return time_;
  }

  bool operator==(const Road& rhs) {
    return (time_ == rhs.time_);
  }
  bool operator<(const Road& rhs) {
    return (time_ < rhs.time_);
  }
  bool operator>(const Road& rhs) {
    return (time_ > rhs.time_);
  }

 private:
  int city1_;
  int city2_;
  int time_;
};

#ifdef DEBUG_MATRIX_ZION
int g_num_visited_nodes = 0;
#endif

class Zion {
 public:
  Zion(const long n) : cities_(n) {}
  ~Zion() {}

  void AddRoad(const int city1, const int city2, const int time) {
    roads_.emplace_back(city1, city2, time);
  }

  void AddMachine(const int city) {
    cities_[city].SetMachine();
  }

  long DestroyRoads(const vector<int>& machines) {
    // sort roads in increasing order
    sort(roads_.begin(), roads_.end());

    // populate roads on cities
    for (size_t idx = 0; idx < roads_.size(); ++idx) {
      cities_[roads_[idx].GetCity1()].AddRoad(idx);
      cities_[roads_[idx].GetCity2()].AddRoad(idx);
    }

    int num_roads_left = (machines.size() - 1);
    long cost = 0;

    for (size_t idx = 0; idx < roads_.size(); ++idx) {
      Road& road = roads_[idx];

      // look for machines in both directions
      if (FindMachine(road.GetCity1(), road.GetCity2()) &&
          FindMachine(road.GetCity2(), road.GetCity1())) {
        // this road will be destroyed

#ifdef DEBUG_MATRIX_ZION
        cout << "[" << idx << "] ";
        cout << road.GetCity1() << "," << road.GetCity2() << " = " << road.GetTime();
        cout << ", cities visited: " << g_num_visited_nodes << endl;
#endif

        cost += road.GetTime();
        num_roads_left--;
        if (num_roads_left == 0) {
          return cost;
        }

        // remove this road
        cities_[road.GetCity1()].RemoveRoad(idx);
        cities_[road.GetCity2()].RemoveRoad(idx);
      }
    }

    assert(0);
    return 0;
  }

 private:
  vector<City> cities_;

  vector<Road> roads_;

  bool FindMachine(const int city_idx, const int parent_idx) {
#ifdef DEBUG_MATRIX_ZION
    g_num_visited_nodes++;
#endif

    City& city = cities_[city_idx];
    if (city.IsVisited()) {
      return false;
    }
    if (city.HasMachine()) {
      return true;
    }

    const auto& roads = city.GetRoads();
    for (int road : roads) {
      const int next_city_idx = roads_[road].GetOtherCity(city_idx);
      if ((next_city_idx != parent_idx) && FindMachine(next_city_idx, city_idx)) {
        return true;
      }
    }

    city.SetVisited();
    return false;
  }
};

// Complete the minTime function below.
int minTime(const vector<vector<int>>& roads, const vector<int>& machines) {
  if (machines.size() < 2) {
    // special case: less than two machines
    return 0;
  }

  Zion zion(roads.size() + 1);

  for (size_t idx = 0; idx < roads.size(); ++idx) {
    zion.AddRoad(roads[idx][0], roads[idx][1], roads[idx][2]);
  }

  for (int machine : machines) {
    zion.AddMachine(machine);
  }

  return zion.DestroyRoads(machines);
}

TEST_CASE("matrix_zion", "[interview_prep_kit][graph][hard][star]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  // start
  const chrono::high_resolution_clock::time_point start_time = chrono::high_resolution_clock::now();

  string nk_temp;
  getline(cin, nk_temp);

  vector<string> nk = split_string(nk_temp);

  int n = stoi(nk[0]);

  int k = stoi(nk[1]);

  vector<vector<int>> roads(n - 1);
  for (int i = 0; i < n - 1; i++) {
    roads[i].resize(3);

    getline(cin, nk_temp);
    nk = split_string(nk_temp);

    for (int j = 0; j < 3; j++) {
      if (!IsNumber(nk[j])) {
        i--;
        break;
      }

      roads[i][j] = stoi(nk[j]);
    }
  }

  vector<int> machines(k, -1);

  for (int i = 0; i < k; i++) {
    int machines_item;
    cin >> machines_item;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    machines[i] = machines_item;
  }

  while ((machines.back() == machines[machines.size() - 2]) || (machines.back() < 0)) {
    machines.pop_back();
  }

  int result = minTime(roads, machines);

  fout << result << "\n";

  fout.close();

  // end
  const chrono::high_resolution_clock::time_point end_time = chrono::high_resolution_clock::now();

  // run time
  const int run_time = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();
  cout << "Time taken : " << run_time << " msec\n";
}
