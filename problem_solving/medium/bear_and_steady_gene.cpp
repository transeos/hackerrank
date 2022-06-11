// -*- C++ -*-
//
//*****************************************************************
//
// https://www.hackerrank.com/challenges/bear-and-steady-gene/problem
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy on 11/06/22.
//
//*****************************************************************

#include "utils.h"
#include <bits/stdc++.h>
#include <catch2/catch.hpp>

using std::cin;
using std::cout;
using std::endl;
using std::ofstream;
using std::string;
using std::vector;

/*
 * Complete the 'steadyGene' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING gene as parameter.
 */

constexpr int32_t GetGeneIndex(const char c) {
  switch (c) {
    case ('A'):
      return 0;
    case ('C'):
      return 1;
    case ('G'):
      return 2;
    case ('T'):
      return 3;
  }

  return -1;
}

class Chunk {
 private:
  int32_t _startIndex;
  int32_t _len;

  std::array<int32_t, 4> _geneCount;

  int64_t _priority;
  bool _match;

  void Compute() {
    _match = true;

    int64_t numMisMatch = 0;

    for (size_t i = 0; i < 4; ++i) {
      if (_geneCount[i] < BestMismatch[i]) {
        _match = false;
      } else {
        numMisMatch += BestMismatch[i] - _geneCount[i];
      }
    }

    //_priority = (int64_t)((_len) << 32L) + (int64_t)numMisMatch;
    _priority = _len;
    //_priority = _len + numMisMatch;
  }

 public:
  static std::array<int32_t, 4> BestMismatch;

  Chunk(const string& gene, const int32_t startIndex, const int32_t len)
      : _startIndex(startIndex), _len(len) {
    _geneCount = {};

    for (size_t i = startIndex; i < (startIndex + len); ++i) {
      _geneCount[GetGeneIndex(gene[i])]++;
    }

    Compute();
  }

  Chunk(const Chunk& prevChunk, const char prevChar, const char newChar) {
    _startIndex = prevChunk._startIndex + 1;
    _len = prevChunk._len;

    _geneCount = prevChunk._geneCount;
    _geneCount[GetGeneIndex(newChar)]++;
    _geneCount[GetGeneIndex(prevChar)]--;

    Compute();
  }

  void Update(const Chunk& prevChunk, const char newChar, const bool incrementAfter) {
    _startIndex = prevChunk._startIndex;
    if (!incrementAfter) {
      _startIndex--;
    }

    _len = prevChunk._len + 1;

    _geneCount = prevChunk._geneCount;
    _geneCount[GetGeneIndex(newChar)]++;

    Compute();
  }

  int32_t StartIndex() const {
    return _startIndex;
  }
  int32_t Len() const {
    return _len;
  }
  bool Match() const {
    return _match;
  }

  bool operator>(const Chunk& rhs) const {
    if (_priority < rhs._priority) {
      return false;
    } else if (_priority > rhs._priority) {
      return true;
    }

    if (_len < rhs._len) {
      return false;
    } else if (_len > rhs._len) {
      return true;
    }

    return _startIndex > rhs._startIndex;
  }

  bool operator<(const Chunk& rhs) const {
    if (_priority < rhs._priority) {
      return true;
    } else if (_priority > rhs._priority) {
      return false;
    }

    if (_len < rhs._len) {
      return true;
    } else if (_len > rhs._len) {
      return false;
    }

    return _startIndex < rhs._startIndex;
  }
};
std::array<int32_t, 4> Chunk::BestMismatch;

int32_t steadyGene(const string& gene) {
  // A, C, G, T
  std::array<int32_t, 4> geneCount = {};

  for (const char c : gene) {
    geneCount[GetGeneIndex(c)]++;
  }

  Chunk::BestMismatch = {};
  for (size_t i = 0; i < 4; ++i) {
    const int32_t count = geneCount[i];

    if (count > (gene.length() / 4)) {
      Chunk::BestMismatch[i] = count - (int32_t)(gene.length() / 4);
    }
  }

  auto getCountFn = [](const std::array<int32_t, 4>& arr) -> int32_t {
    return (arr[0] + arr[1] + arr[2] + arr[3]);
  };

  const int32_t misMatchCount = getCountFn(Chunk::BestMismatch);
  if (misMatchCount == 0) {
    return 0;
  }

  vector<Chunk> visitedChunks;

  auto compareChunkFn = [&visitedChunks](const int32_t leftIndex,
                                         const int32_t rightIndex) -> bool {
    return visitedChunks[leftIndex] < visitedChunks[rightIndex];
  };

  std::set<int32_t, std::function<bool(int32_t, int32_t)>> chunks(compareChunkFn);

  visitedChunks.emplace_back(gene, 0, misMatchCount);
  if (visitedChunks[0].Match()) {
    return misMatchCount;
  }
  chunks.insert(0);

  for (int32_t i = 1; i < gene.length() - misMatchCount; ++i) {
    visitedChunks.emplace_back(visitedChunks[i - 1], gene[i - 1], gene[i + misMatchCount - 1]);
    if (visitedChunks.back().Match()) {
      return misMatchCount;
    }
    chunks.insert(i);
  }

  while (!chunks.empty()) {
    const Chunk& curChunk = visitedChunks[*chunks.begin()];
    chunks.erase(chunks.begin());
    const int32_t curStart = curChunk.StartIndex();
    const int32_t newLen = curChunk.Len() + 1;

    if (curStart != 0) {
      if (visitedChunks[curStart - 1].Len() < newLen) {
        visitedChunks[curStart - 1].Update(curChunk, gene[curStart - 1], false);
        if (visitedChunks[curStart - 1].Match()) {
          return newLen;
        }

        chunks.erase(curStart - 1);
        chunks.insert(curStart - 1);
      }
    }

    if ((curStart + newLen - 1) < gene.length()) {
      if (visitedChunks[curStart].Len() < newLen) {
        visitedChunks[curStart].Update(curChunk, gene[curStart + newLen - 1], true);
        if (visitedChunks[curStart].Match()) {
          return newLen;
        }

        chunks.erase(curStart);
        chunks.insert(curStart);
      }
    }
  }

  assert(0);
  return -1;
}

TEST_CASE("bear_and_steady_gene", "[problem_solving][medium][star]") {
  ofstream fout(getenv("OUTPUT_PATH"));

  string n_temp;
  getline(cin, n_temp);

  int n = stoi(ltrim(rtrim(n_temp)));

  string gene;
  getline(cin, gene);

  int result = steadyGene(gene);

  fout << result << "\n";

  fout.close();
}
