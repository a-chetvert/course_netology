#include "pch.h"

#include "gtest/gtest.h"

#include "Eagle.h"
#include "CarpetPlane.h"
#include "Broom.h"
#include "Camel.h"
#include "CamelFast.h"
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
TEST(TestGnd, Camel) {
  Camel camel;

  // дистанция из примера задания
  int distance = 4500;
  // ожидаемое время из решения задания - 559
  // вручную - получается 567
  // поставил расчитанное мной
  double expectedTime = 567;

  EXPECT_DOUBLE_EQ(expectedTime, camel.calcTime(distance));
}
TEST(TestGnd, CamelFast) {
  CamelFast camelFast;

  int distance = 1600;
  // 1610км / 40км/ч = 40,25ч
  // 40,25ч соответствет 4 перерывам
  // 5+6,55+2*8 =27,5
  double expectedTime = 67.5;

  EXPECT_DOUBLE_EQ(expectedTime, camelFast.calcTime(distance));
}

/*
TEST(TestGnd, Centaur) {
  Centaur Centaur;

  int distance = 1600;
  // 45км / 40км/ч = 40,25ч
  // 40,25ч соответствет 4 перерывам
  // 5+6,55+2*8 =27,5
  double expectedTime = 67.5;

  EXPECT_DOUBLE_EQ(expectedTime, Centaur.calcTime(distance));
}

*/
