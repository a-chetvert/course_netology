
#include "gtest/gtest.h"
#include "../lib/transport/Eagle.h"
#include "../lib/transport/Eagle.cpp"
#include "../lib/transport/AirTransport.cpp"
#include "../lib/transport/AirTransport.h"
#include "../lib/transport/CarpetPlane.cpp"
#include "../lib/transport/CarpetPlane.h"
#include "../lib/transport/Broom.cpp"
#include "../lib/transport/Broom.h"

TEST(TestAir, Eagle) {
  Eagle eagle;

  // дистанция из примера задания
  int distance = 4500;
  // ожидаемое время из решения задания
  double expectedTime = 528.75;

  EXPECT_DOUBLE_EQ(expectedTime, eagle.calcTime(distance));
}

TEST(TestAir, CarpetPlane) {
  CarpetPlane carpetPlane;

  // дистанция из примера задания
  int distance = 4500;
  // ожидаемое время из решения задания
  double expectedTime = 436.5;

  EXPECT_DOUBLE_EQ(expectedTime, carpetPlane.calcTime(distance));
}

TEST(TestAir, Broom) {
  Broom broom;

  // дистанция из примера задания
  int distance = 4500;
  // ожидаемое время из решения задания
  double expectedTime = 216;

  EXPECT_DOUBLE_EQ(expectedTime, broom.calcTime(distance));
}

