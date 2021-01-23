// Copyright 2021 LemuriiL <LemuriiL@yandex.ru>
#include <cache.hpp>
#include <random>

void Cache::CacheWeights() {
  sizes[0] = low / 2;
  for (int n = 1, i = 1; n < hight * 1.5; n *= 2, ++i) {
    sizes[i] = n;
  }
  sizes[5] = hight * 1.5;
}

void Cache::Straight() {
  double time[6];
  for (int i = 0; i < 6; i++) {
    size_t bSize = (sizes[i] * 1024 * 1024) / 4;
    int* array = ArrayGenerating(bSize);
    Fire(array, bSize);
    [[maybe_unused]] int k;
    auto start = std::chrono::system_clock::now();
    for (size_t j = 0; j < bSize * shots; j += step) {
      k = array[j % 1000];
    }
    auto end = std::chrono::system_clock::now();
    time[i] = (static_cast<double>(
        std::chrono::nanoseconds((end - start) / shots).count()));
    delete[] array;
  }
  for (int j = 0; j < 6; ++j) {
    straightTimes[j] = time[j];
  }
}

void Cache::Back() {
  double time[6];
  for (int i = 0; i < 6; i++) {
    size_t bSize = (sizes[i] * 1024 * 1024) / 4;
    int* array = ArrayGenerating(bSize);
    Fire(array, bSize);
    [[maybe_unused]] int k;
    auto start = std::chrono::system_clock::now();
    for (size_t j = bSize * shots; j > 0; j -= step) {
      k = array[j % 1000];
    }
    auto end = std::chrono::system_clock::now();
    time[i] = (static_cast<double>(
        std::chrono::nanoseconds((end - start) / shots).count()));
    delete[] array;
  }
  for (int j = 0; j < 6; ++j) {
    backTimes[j] = time[j];
  }
}

void Cache::Random() {
  double time[6];
  for (int i = 0; i < 6; i++) {
    size_t bSize = (sizes[i] * 1024 * 1024) / 4;
    int* array = ArrayGenerating(bSize);
    std::vector<size_t>::iterator start, end;
    std::vector<size_t> arr;
    for (size_t j = 0; j < bSize; j += step) arr.push_back(j);
    start = arr.begin();
    end = arr.end();
    shuffle(start, end, std::mt19937(std::random_device()()));
    Fire(array, bSize);
    auto startTime = std::chrono::high_resolution_clock::now();
    [[maybe_unused]] int k;
    for (size_t j = 0; j < bSize * shots; j += step) {
      k = array[j % 1000];
    }
    auto endTime = std::chrono::high_resolution_clock::now();
    time[i] = (static_cast<double>(
        std::chrono::nanoseconds((endTime - startTime) / 1000).count()));
    delete[] array;
  }
  for (int j = 0; j < 6; ++j) {
    randomTimes[j] = time[j];
  }
}

void Cache::Fire(int* fireArray, size_t size) {
  [[maybe_unused]] int k;
  for (size_t i = 0; i < size; ++i) {
    k = fireArray[i];
  }
}
int* Cache::ArrayGenerating(size_t bSize) {
  int* generatedArray = new int[bSize];
  for (size_t i = 0; i < bSize; ++i) {
    generatedArray[i] = rand() % 100;
  }
  return generatedArray;
}

void Cache::Print(std::ostream& os) {
  using std::endl;
  for (size_t i = 0; i < 3; ++i) {
    os << "Invistigations: " << endl
       << "     travel_variant: " << variant[i] << endl
       << "     experiments: " << std::endl;
    for (size_t j = 0, c = 0; j < 6; ++j, ++c) {
      os << "           -experiment:" << endl
         << "           number: " << j + 1 << endl
         << "      input_data: " << endl
         << "            buffer_size: " << sizes[j] << " mb" << endl
         << "      results: " << endl
         << "            duration: ";
      WhatTimeCorrect(i, j);
      os << " nanoseconds" << std::endl;
    }
  }
}

void Cache::WhatTimeCorrect(int i, int j) {
  using std::cout;
  switch (i) {
    case 0:
      cout << straightTimes[j];
      break;
    case 1:
      cout << backTimes[j];
      break;
    case 2:
      cout << randomTimes[j];
      break;
  }
}
