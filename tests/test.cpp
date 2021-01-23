// Copyright 2021 LemuriiL <LemuriiL@yandex.ru>
#include <cache.hpp>
#include <gtest/gtest.h>

TEST(Example, EmptyTest) {
  Cache run;
  run.CacheWeights();
  run.Straight();
  run.Back();
  run.Random();
  run.Print(std::cout);
}