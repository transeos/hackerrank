// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/rectangle-area/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 12/05/19.
//
//*****************************************************************

#include <iostream>

#include <catch2/catch.hpp>

using namespace std;

/*
 * Create classes Rectangle and RectangleArea
 */
class Rectangle {
 public:
  virtual ~Rectangle() {}

 protected:
  Rectangle() {}

  int width_{0};
  int height_{0};

 public:
  void display() const {
    cout << width_ << " " << height_ << endl;
  }
};

class RectangleArea : public Rectangle {
 public:
  RectangleArea() : Rectangle() {}
  virtual ~RectangleArea() {}

  void read_input() {
    cin >> width_ >> height_;
  }

  void display() const {
    cout << (width_ * height_) << endl;
  }
};

TEST_CASE("rectangle_area", "[cpp][easy]") {
  /*
   * Declare a RectangleArea object
   */
  RectangleArea r_area;

  /*
   * Read the width and height
   */
  r_area.read_input();

  /*
   * Print the width and height
   */
  r_area.Rectangle::display();

  /*
   * Print the area
   */
  r_area.display();
}
