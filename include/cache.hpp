// Copyright 2021 LemuriiL <LemuriiL@yandex.ru>
#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_

#include <chrono>
#include <functional>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::ostream;
using std::string;
using std::stringstream;

class Cache {
  double straightTimes[6];
  double backTimes[6];
  double randomTimes[6];
  string variant[3] = {"straight", "back", "random"};

 public:
  void CacheWeights();
  void Fire(int *arrayToFire, size_t size);
  void Straight();
  void Back();
  void Random();
  int *ArrayGenerating(size_t bSize);
  void Print(std::ostream& os);
  void WhatTimeCorrect(int i, int j);

 private:
  double sizes[6];

  const double low = 0.256;
  const double hight = 8;
  const int step = 16;
  const int shots = 1000;
};

#endif  // INCLUDE_HEADER_HPP_
