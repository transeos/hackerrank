// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/inherited-code/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 12/05/19.
//
//*****************************************************************

#include <exception>
#include <iostream>
#include <sstream>
#include <string>

#include <catch2/catch.hpp>

using namespace std;

/* Define the exception here */

/*struct BadLengthException : public std::exception
{
  const char * what () const throw ()
    {
      return "C++ Exception";
    }
};*/

class BadLengthException : public exception {
 public:
  BadLengthException(int n) {
    msg_ = to_string(n);
  }
  ~BadLengthException() {}

 private:
  static string msg_;

 public:
  const char* what() const throw() {
    return msg_.c_str();
  }
};

string BadLengthException::msg_ = "";

bool checkUsername(string username) {
  bool isValid = true;
  int n = username.length();
  if (n < 5) {
    throw BadLengthException(n);
  }
  for (int i = 0; i < n - 1; i++) {
    if (username[i] == 'w' && username[i + 1] == 'w') {
      isValid = false;
    }
  }
  return isValid;
}

TEST_CASE("inherited_code", "[cpp][easy]") {
  int T;
  cin >> T;
  while (T--) {
    string username;
    cin >> username;
    try {
      bool isValid = checkUsername(username);
      if (isValid) {
        cout << "Valid" << '\n';
      } else {
        cout << "Invalid" << '\n';
      }
    } catch (BadLengthException e) {
      cout << "Too short: " << e.what() << '\n';
    }
  }
}
