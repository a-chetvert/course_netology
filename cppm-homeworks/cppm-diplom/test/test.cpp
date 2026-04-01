/**
 * @file test.cpp
 * @brief Модульные тесты для гоночной системы
 *
 * Данный файл содержит тесты для проверки корректности работы
 * различных транспортных средств и логики гонок.
 */

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "Eagle.h"
#include "CarpetPlane.h"
#include "Broom.h"
#include "Camel.h"
#include "CamelFast.h"
#include "Centaur.h"
#include "BootsAllTerrain.h"
#include "Race.h"

 /**
  * @brief Тест для класса Eagle (Орел)
  * @test Проверяет расчет времени для воздушного транспорта Eagle
  *
  * Дистанция: 4500 км
  * Ожидаемое время: 528.75 часов
  */
TEST_CASE("Eagle time calculation") {
  Eagle eagle;

  // дистанция из примера задания
  double distance = 4500;
  // ожидаемое время из решения задания
  double expectedTime = 528.75;

  CHECK(expectedTime == doctest::Approx(eagle.calcTime(distance)));
}

/**
 * @brief Тест для класса CarpetPlane (Ковер-самолет)
 * @test Проверяет расчет времени для воздушного транспорта CarpetPlane
 *
 * Дистанция: 4500 км
 * Ожидаемое время: 436.5 часов
 */
TEST_CASE("CarpetPlane time calculation") {
  CarpetPlane carpetPlane;

  // дистанция из примера задания
  double distance = 4500;
  // ожидаемое время из решения задания
  double expectedTime = 436.5;

  CHECK(expectedTime == doctest::Approx(carpetPlane.calcTime(distance)));
}

/**
 * @brief Тест для класса Broom (Метла)
 * @test Проверяет расчет времени для воздушного транспорта Broom
 *
 * Дистанция: 4500 км
 * Ожидаемое время: 216 часов
 */
TEST_CASE("Broom time calculation") {
  Broom broom;

  // дистанция из примера задания
  double distance = 4500;
  // ожидаемое время из решения задания
  double expectedTime = 216;

  CHECK(expectedTime == doctest::Approx(broom.calcTime(distance)));
}

/**
 * @brief Тест для класса Camel (Верблюд)
 * @test Проверяет расчет времени для наземного транспорта Camel
 *
 * Дистанция: 4500 км
 * Ожидаемое время: 567 часов (расчетное)
 *
 * @note В исходном задании ожидалось 559, но по расчетам получается 567
 */
TEST_CASE("Camel time calculation") {
  Camel camel;

  // дистанция из примера задания
  double distance = 4500;
  double expectedTime = 559;

  CHECK(expectedTime == doctest::Approx(camel.calcTime(distance)));
}

/**
 * @brief Тест для класса CamelFast (Быстрый верблюд)
 * @test Проверяет расчет времени для наземного транспорта CamelFast
 *
 * Дистанция: 4500 км
 * Ожидаемое время: 196 часов
 */
TEST_CASE("CamelFast time calculation") {
  CamelFast camelFast;

  double distance = 4500;
  double expectedTime = 196;

  CHECK(expectedTime == doctest::Approx(camelFast.calcTime(distance)));
}

/**
 * @brief Тест для класса Centaur (Кентавр)
 * @test Проверяет расчет времени для наземного транспорта Centaur
 *
 * Дистанция: 4500 км
 * Ожидаемое время: 374 часа
 */
TEST_CASE("Centaur time calculation") {
  Centaur centaur;

  double distance = 4500;
  double expectedTime = 374;

  CHECK(expectedTime == doctest::Approx(centaur.calcTime(distance)));
}

/**
 * @brief Тест для класса BootsAllTerrain (Всепроходные сапоги)
 * @test Проверяет расчет времени для наземного транспорта BootsAllTerrain
 *
 * Дистанция: 4500 км
 * Ожидаемое время: 815 часов
 */
TEST_CASE("BootsAllTerrain time calculation") {
  BootsAllTerrain bootsAllTerrain;

  double distance = 4500;
  double expectedTime = 815;

  CHECK(expectedTime == doctest::Approx(bootsAllTerrain.calcTime(distance)));
}

/**
 * @brief Тест для метода getDistance() класса Race
 * @test Проверяет корректность получения дистанции гонки
 */
TEST_CASE("Race getDistance test") {
  double distance = 4500;
  Race race(distance, RaceType::air);

  CHECK_EQ(distance, race.getDistance());
}

/**
 * @brief Тест для метода getRaceType() класса Race
 * @test Проверяет корректность получения типа гонки
 */
TEST_CASE("Race getRaceType test") {

  double distance = 4500;
  Race race(distance, RaceType::air);

  CHECK_EQ(RaceType::air, race.getRaceType());
}