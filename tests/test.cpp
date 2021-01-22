// Copyright 2021 LemuriiL <LemuriiL@yandex.ru>
#include <cache.hpp>
#include <gtest/gtest.h>

TEST(Example, EmptyTest) {
  Cache experiments;
  experiments.CacheWeights();
  experiments.Straight();
  experiments.Back();
  experiments.Random();
  experiments.Print(std::cout);
}