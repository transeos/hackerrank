// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/attribute-parser/problem
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

class Tag {
 public:
  Tag() : name_(""), parent_tag_(nullptr) {}
  Tag(const Tag& tag)
      : name_(tag.name_), attributes_(tag.attributes_), parent_tag_(tag.parent_tag_) {}

  Tag(const string& name) : parent_tag_(nullptr) {
    size_t idx = 1;
    while ((name[idx] != ' ') && (idx < (name.length() - 1))) {
      idx++;
    }

    name_ = name.substr(1, (idx - 1));

    while (idx < (name.length() - 1)) {
      // space between name/attribute and next attribute
      idx++;

      const int attribute_start = idx;
      // find next space
      while (name[idx] != ' ') {
        idx++;
      }
      const int attribute_end = (idx - 1);

      // '= "' before value;
      idx += 4;

      const int val_start = idx;
      // find next '"'
      while (name[idx] != '"') {
        idx++;
      }
      const int val_end = (idx - 1);

      attributes_[name.substr(attribute_start, (attribute_end - attribute_start + 1))] =
          name.substr(val_start, (val_end - val_start + 1));

      // '"' after value;
      idx++;
    }
  }
  ~Tag() {}

  const string& GetName() const {
    return name_;
  }

  bool HasParent() const {
    return (parent_tag_ != nullptr);
  }
  const Tag& GetParent() const {
    return *parent_tag_;
  }
  void SetParent(const Tag& parent) {
    parent_tag_ = &parent;
  }

  bool GetVal(const string& attr, string& val) const {
    auto iter = attributes_.find(attr);
    if (iter != attributes_.end()) {
      val = iter->second;
      return true;
    }
    return false;
  }

  friend ostream& operator<<(ostream& out, const Tag& tag) {
    out << "Tag name=" << tag.name_;

    if (tag.HasParent()) {
      out << " parent tag:" << tag.GetParent().GetName();
    }

    if (tag.attributes_.size()) {
      out << " attributes: ";
    }

    for (auto& iter : tag.attributes_) {
      out << iter.first << "=" << iter.second << ", ";
    }
    return out;
  }

 private:
  string name_;
  unordered_map<string, string> attributes_;

  const Tag* parent_tag_;
};

TEST_CASE("attribute_parser", "[cpp][medium]") {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */

  unordered_map<string, Tag> tags;

  // input lines (tag descriptions)
  int N = 0;

  // queries
  int Q = 0;

  cin >> N >> Q;

  string text = "";
  string parent_tag = "";

  while (getline(cin, text)) {
    if (text.empty()) {
      continue;
    }
    // cout << "==" << text << "==" << endl;

    if (N > 0) {
      // process tags
      N--;

      assert((text[0] == '<') && (text[text.length() - 1] == '>'));

      if (text[1] != '/') {
        Tag new_tag(text);

        if (!parent_tag.empty()) {
          new_tag.SetParent(tags.at(parent_tag));
        }
        parent_tag = new_tag.GetName();

        tags[new_tag.GetName()] = new_tag;
        // cout << new_tag << endl;
      } else {
        string tag_name = text.substr(2, (text.length() - 3));
        auto iter = tags.find(tag_name);
        if (iter != tags.end()) {
          const Tag& tag = iter->second;
          parent_tag = (tag.HasParent() ? tag.GetParent().GetName() : "");
        }
      }
    } else {
      // process queries
      Q--;

      const Tag* cur_tag = nullptr;
      string atrribute = "";

      int ch_idx = 0;
      while (ch_idx < text.length()) {
        const int tag_name_start = ch_idx;
        // look for '.' or "~'
        while ((text[ch_idx] != '.') && (text[ch_idx] != '~')) {
          ch_idx++;
        }
        const int tag_name_end = (ch_idx - 1);

        const string tag_name = text.substr(tag_name_start, (tag_name_end - tag_name_start + 1));
        auto iter = tags.find(tag_name);
        if (iter == tags.end()) {
          break;
        }

        const Tag& tag = iter->second;
        if (cur_tag != nullptr) {
          if (&(tag.GetParent()) != cur_tag) {
            break;
          }
        } else if (tag.HasParent()) {
          break;
        }
        cur_tag = &tag;

        // contains '.' or '~'
        ch_idx++;

        if (text[ch_idx - 1] == '.') {
          // nested tag
          continue;
        }

        const int attr_start = ch_idx;
        const int attr_end = (text.length() - 1);
        atrribute = text.substr(attr_start, (attr_end - attr_start + 1));
        ch_idx = (attr_end + 1);
      }

      /*if (cur_tag) {
        cout << "Final tag: " << cur_tag->GetName() << ", ";
      }
      cout << " : " << atrribute << endl;*/

      if (atrribute.empty()) {
        cout << "Not Found!" << endl;
      } else {
        string tag_value = "";
        if (cur_tag->GetVal(atrribute, tag_value)) {
          cout << tag_value << endl;
        } else {
          cout << "Not Found!" << endl;
        }
      }
    }
  }

  assert((N == 0) && (Q == 0));
}
