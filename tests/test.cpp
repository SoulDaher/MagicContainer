
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "MyContainer.hpp"
#include "doctest.h"

using namespace cont;

TEST_CASE("Basic operations on MyContainer") {
  MyContainer<int> container;
  CHECK(container.size() == 0);

  container.add(5);
  container.add(3);
  container.add(9);
  container.add(1);

  CHECK(container.size() == 4);
  CHECK_NOTHROW(container.remove(3));
  CHECK(container.size() == 3);
  CHECK_THROWS(container.remove(42));
}

TEST_CASE("AscendingOrder iterator works") {
  MyContainer<int> container;
  container.add(5);
  container.add(3);
  container.add(9);
  container.add(1);

  std::vector<int> expected = {1, 3, 5, 9};
  std::vector<int> result;

  for (auto it = container.begin_ascending_order();
       it != container.end_ascending_order(); ++it) {
    result.push_back(*it);
  }

  CHECK(result == expected);
}

TEST_CASE("DescendingOrder iterator works") {
  MyContainer<int> container;
  container.add(5);
  container.add(3);
  container.add(9);
  container.add(1);

  std::vector<int> expected = {9, 5, 3, 1};
  std::vector<int> result;

  for (auto it = container.begin_descending_order();
       it != container.end_descending_order(); ++it) {
    result.push_back(*it);
  }

  CHECK(result == expected);
}

TEST_CASE("SideCrossOrder iterator works") {
  MyContainer<int> container;
  container.add(1);
  container.add(2);
  container.add(3);
  container.add(4);
  container.add(5);

  std::vector<int> expected = {1, 5, 2, 4, 3};
  std::vector<int> result;

  for (auto it = container.begin_side_cross_order();
       it != container.end_side_cross_order(); ++it) {
    result.push_back(*it);
  }

  CHECK(result == expected);
}

TEST_CASE("ReverseOrder iterator works") {
  MyContainer<int> container;
  container.add(10);
  container.add(20);
  container.add(30);

  std::vector<int> expected = {30, 20, 10};
  std::vector<int> result;

  for (auto it = container.begin_reverse_order();
       it != container.end_reverse_order(); ++it) {
    result.push_back(*it);
  }

  CHECK(result == expected);
}

TEST_CASE("Order iterator works") {
  MyContainer<int> container;
  container.add(100);
  container.add(200);
  container.add(300);

  std::vector<int> expected = {100, 200, 300};
  std::vector<int> result;

  for (auto it = container.begin_order(); it != container.end_order(); ++it) {
    result.push_back(*it);
  }

  CHECK(result == expected);
}

TEST_CASE("MiddleOutOrder iterator works") {
  MyContainer<int> container;
  container.add(1);
  container.add(2);
  container.add(3);
  container.add(4);
  container.add(5);

  std::vector<int> expected = {3, 4, 2, 5, 1};
  std::vector<int> result;

  for (auto it = container.begin_middle_out_order();
       it != container.end_middle_out_order(); ++it) {
    result.push_back(*it);
  }

  CHECK(result == expected);
}
