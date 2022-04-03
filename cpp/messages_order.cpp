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
  friend class MessageFactory;

 private:
  uint32_t _id;
  string _data;

  Message(const uint32_t id, const string& text) : _id(id), _data(text) {}

 public:
  Message(const Message& msg) : _id(msg._id), _data(msg._data) {}

  const string& get_text() const {
    return _data;
  }

  friend bool operator<(const Message& lhs, const Message& rhs);
  friend void swap(Message&& lhs, Message&& rhs);
};

bool operator<(const Message& lhs, const Message& rhs) {
  return lhs._id < rhs._id;
}

void swap(Message&& lhs, Message&& rhs) {
  std::pair<uint32_t, string> tempData(lhs._id, lhs._data);
  lhs._id = rhs._id;
  lhs._data = rhs._data;
  rhs._id = std::get<0>(tempData);
  rhs._data = std::get<1>(tempData);
}

class MessageFactory {
 private:
  uint32_t _msgCount;

 public:
  MessageFactory() : _msgCount(0) {}

  Message create_message(const string& text) {
    _msgCount++;
    return Message(_msgCount, text);
  }
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
