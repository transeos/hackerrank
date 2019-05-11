// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/box-it/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 12/05/19.
//
//*****************************************************************

#include <bits/stdc++.h>
#include <iostream>
#include <tuple>

#include <catch2/catch.hpp>

using namespace std;

// Implement the class Box
// l,b,h are integers representing the dimensions of the box

class Box {
 public:
  // Constructors:
  Box() : l_(0), b_(0), h_(0) {}
  Box(int l, int b, int h) : l_(l), b_(b), h_(h) {}
  Box(const Box& box) : l_(box.l_), b_(box.b_), h_(box.h_) {}

  ~Box() {}

 private:
  // length
  int l_;

  // breadth
  int b_;

  // height
  int h_;

 public:
  int getLength() const {
    return l_;
  }  // Return box's length
  int getBreadth() const {
    return b_;
  }  // Return box's breadth
  int getHeight() const {
    return h_;
  }                                    // Return box's height
  long long CalculateVolume() const {  // Return the volume of the box
    return (long long)l_ * (long long)b_ * (long long)h_;
  }

  // Overload operator < as specified
  bool operator<(const Box& box) const {
    return (tuple<int, int, int>(l_, b_, h_) < tuple<int, int, int>(box.l_, box.b_, box.h_));
  }

  // Overload operator << as specified
  friend ostream& operator<<(ostream& out, const Box& box) {
    out << box.l_ << " " << box.b_ << " " << box.h_;
    return out;
  }
};

void check2() {
  int n;
  cin >> n;
  Box temp;
  for (int i = 0; i < n; i++) {
    int type;
    cin >> type;
    if (type == 1) {
      cout << temp << endl;
    }
    if (type == 2) {
      int l, b, h;
      cin >> l >> b >> h;
      Box NewBox(l, b, h);
      temp = NewBox;
      cout << temp << endl;
    }
    if (type == 3) {
      int l, b, h;
      cin >> l >> b >> h;
      Box NewBox(l, b, h);
      if (NewBox < temp) {
        cout << "Lesser\n";
      } else {
        cout << "Greater\n";
      }
    }
    if (type == 4) {
      cout << temp.CalculateVolume() << endl;
    }
    if (type == 5) {
      Box NewBox(temp);
      cout << NewBox << endl;
    }
  }
}

TEST_CASE("box_it", "[cpp][easy]") {
  check2();
}
