// -*- C++ -*-
//
//*****************************************************************
//
// hackerrank: https://www.hackerrank.com/challenges/magic-spells/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 12/05/19.
//
//*****************************************************************

#include <catch2/catch.hpp>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Spell {
 private:
  string scrollName;

 public:
  Spell() : scrollName("") {}
  Spell(string name) : scrollName(name) {}
  virtual ~Spell() {}
  string revealScrollName() {
    return scrollName;
  }
};

class Fireball : public Spell {
 private:
  int power;

 public:
  Fireball(int power) : power(power) {}
  void revealFirepower() {
    cout << "Fireball: " << power << endl;
  }
};

class Frostbite : public Spell {
 private:
  int power;

 public:
  Frostbite(int power) : power(power) {}
  void revealFrostpower() {
    cout << "Frostbite: " << power << endl;
  }
};

class Thunderstorm : public Spell {
 private:
  int power;

 public:
  Thunderstorm(int power) : power(power) {}
  void revealThunderpower() {
    cout << "Thunderstorm: " << power << endl;
  }
};

class Waterbolt : public Spell {
 private:
  int power;

 public:
  Waterbolt(int power) : power(power) {}
  void revealWaterpower() {
    cout << "Waterbolt: " << power << endl;
  }
};

class SpellJournal {
 public:
  static string journal;
  static string read() {
    return journal;
  }
};
string SpellJournal::journal = "";

void counterspell(Spell* spell) {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */

  Fireball* fire_spell = dynamic_cast<Fireball*>(spell);
  if (fire_spell) {
    fire_spell->revealFirepower();
    return;
  }

  Frostbite* frost_spell = dynamic_cast<Frostbite*>(spell);
  if (frost_spell) {
    frost_spell->revealFrostpower();
    return;
  }

  Waterbolt* water_spell = dynamic_cast<Waterbolt*>(spell);
  if (water_spell) {
    water_spell->revealWaterpower();
    return;
  }

  Thunderstorm* thunder_spell = dynamic_cast<Thunderstorm*>(spell);
  if (thunder_spell) {
    thunder_spell->revealThunderpower();
    return;
  }

  const string& spell_name = SpellJournal::journal;
  const string& journal_name = spell->revealScrollName();

  const int spell_len = spell_name.size();
  const int journal_len = journal_name.size();

  vector<vector<string>> matched_str;
  matched_str.resize(spell_len + 1);

  for (size_t i = 0; i <= spell_len; ++i) {
    matched_str[i].resize(journal_len + 1);
    matched_str[i][0] = "";
  }

  for (size_t j = 0; j <= journal_len; ++j) {
    matched_str[0][j] = "";
  }

  for (size_t i = 1; i <= spell_len; ++i) {
    for (size_t j = 1; j <= journal_len; ++j) {
      int data1 = ((spell_name[i - 1] == journal_name[j - 1]) + matched_str[i - 1][j - 1].length());
      int data2 = matched_str[i - 1][j].length();
      int data3 = matched_str[i][j - 1].length();

      if (data1 > data2) {
        if (data1 > data3) {
          matched_str[i][j] = matched_str[i - 1][j - 1];
          if (spell_name[i - 1] == journal_name[j - 1]) {
            matched_str[i][j].push_back(spell_name[i - 1]);
          }
        } else {
          matched_str[i][j] = matched_str[i][j - 1];
        }
      } else if (data2 > data3)
        matched_str[i][j] = matched_str[i - 1][j];
      else
        matched_str[i][j] = matched_str[i][j - 1];
    }
  }

  // cout << matched_str[spell_len][journal_len] << ", length:";
  cout << matched_str[spell_len][journal_len].length() << endl;
}

class Wizard {
 public:
  Spell* cast() {
    Spell* spell;
    string s;
    cin >> s;
    int power;
    cin >> power;
    if (s == "fire") {
      spell = new Fireball(power);
    } else if (s == "frost") {
      spell = new Frostbite(power);
    } else if (s == "water") {
      spell = new Waterbolt(power);
    } else if (s == "thunder") {
      spell = new Thunderstorm(power);
    } else {
      spell = new Spell(s);
      cin >> SpellJournal::journal;
    }
    return spell;
  }
};

TEST_CASE("magic_spells", "[cpp][hard]") {
  int T;
  cin >> T;
  Wizard Arawn;
  while (T--) {
    Spell* spell = Arawn.cast();
    counterspell(spell);
  }
}
