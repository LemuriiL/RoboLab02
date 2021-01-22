// Copyright 2021 LemuriiL <LemuriiL@yandex.ru>
#include <cache.hpp>
#include <gtest/gtest.h>

TEST(Example, EmptyTest) {
  Cache experiments;
  experiments.CacheSizes();
  experiments.StraightExperiment();
  experiments.BackExperiment();
  experiments.RandomExperiment();
  experiments.Print(std::cout);
}