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

template <typename T, typename... Ts>
bool CheckForKnownSpells(Spell* spell) {
  if (T* knownSpell = dynamic_cast<T*>(spell); knownSpell != nullptr) {
    if constexpr (std::is_same_v<T, Fireball>) {
      knownSpell->revealFirepower();
    } else if constexpr (std::is_same_v<T, Frostbite>) {
      knownSpell->revealFrostpower();
    } else if constexpr (std::is_same_v<T, Waterbolt>) {
      knownSpell->revealWaterpower();
    } else if constexpr (std::is_same_v<T, Thunderstorm>) {
      knownSpell->revealThunderpower();
    }

    return true;
  }

  if constexpr (sizeof...(Ts)) {
    return CheckForKnownSpells<Ts...>(spell);
  }

  return false;
}

size_t FindLongestSubsequenceLength(const string& seq1, const string& seq2) {
  vector<vector<size_t>> lenMatrix(seq1.length() + 1);

  for_each(lenMatrix.begin(), lenMatrix.end(), [&seq2](vector<size_t>& row) {
    row.resize(seq2.length() + 1);
    row[0] = 0;
  });

  for_each(lenMatrix[0].begin(), lenMatrix[0].end(), [](size_t& elm) { elm = 0; });

  for (size_t i = 1; i <= seq1.length(); ++i) {
    for (size_t j = 1; j <= seq2.length(); ++j) {
      size_t curLen = lenMatrix[i - 1][j - 1];

      if (seq1[i - 1] == seq2[j - 1]) {
        curLen++;
      }

      lenMatrix[i][j] = std::max(curLen, std::max(lenMatrix[i][j - 1], lenMatrix[i - 1][j]));
    }
  }

  return lenMatrix[seq1.length()][seq2.length()];
}

void counterspell(Spell* spell) {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */

  if (spell == nullptr) {
    return;
  }

  if (CheckForKnownSpells<Fireball, Frostbite, Waterbolt, Thunderstorm>(spell)) {
    return;
  }

  cout << FindLongestSubsequenceLength(spell->revealScrollName(), SpellJournal::read()) << endl;
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

TEST_CASE("magic_spells", "[cpp][hard][star]") {
  int T;
  cin >> T;
  Wizard Arawn;
  while (T--) {
    Spell* spell = Arawn.cast();
    counterspell(spell);
  }
}
