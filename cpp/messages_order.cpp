// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/messages-order/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 19/12/20.
//
//*****************************************************************

#include <algorithm>
#include <catch2/catch.hpp>
#include <iostream>
#include <vector>

using namespace std;

class Message {
 public:
  Message() : str_(""), index_(-1) {}
  Message(const string& str, const int32_t index) : str_(str), index_(index) {}
  ~Message() {}

  const string& get_text() const {
    return str_;
  }
  const int32_t GetIndex() const {
    return index_;
  }

 private:
  string str_;
  int32_t index_;
};

bool operator==(const Message& lhs, const Message& rhs) {
  return lhs.GetIndex() == rhs.GetIndex();
}
bool operator>(const Message& lhs, const Message& rhs) {
  return lhs.GetIndex() > rhs.GetIndex();
}
bool operator<(const Message& lhs, const Message& rhs) {
  return lhs.GetIndex() < rhs.GetIndex();
}

class MessageFactory {
 public:
  MessageFactory() : counter_(-1) {}
  Message create_message(const string& text) {
    counter_++;
    return Message(text, counter_);
  }

 private:
  int32_t counter_;
};

class Recipient {
 public:
  Recipient() {}
  void receive(const Message& msg) {
    messages_.push_back(msg);
  }
  void print_messages() {
    fix_order();
    for (auto& msg : messages_) {
      cout << msg.get_text() << endl;
    }
    messages_.clear();
  }

 private:
  void fix_order() {
    sort(messages_.begin(), messages_.end());
  }
  vector<Message> messages_;
};

class Network {
 public:
  static void send_messages(vector<Message> messages, Recipient& recipient) {
    // simulates the unpredictable network, where sent messages might arrive in unspecified order
    random_shuffle(messages.begin(), messages.end());
    for (auto msg : messages) {
      recipient.receive(msg);
    }
  }
};

TEST_CASE("messages_order", "[cpp][medium]") {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */

  MessageFactory message_factory;
  Recipient recipient;
  vector<Message> messages;
  string text;
  while (getline(cin, text)) {
    messages.push_back(message_factory.create_message(text));
  }
  Network::send_messages(messages, recipient);
  recipient.print_messages();
}
