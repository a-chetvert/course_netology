/**
 * @brief Задача 2. Проверка функций добавления и получения элементов из двусвязного списка
 * @note  Источник: https://github.com/netology-code/cppl-homeworks/blob/main/04/02/
 */

#include <iostream>

 //подключаем макросы catch2
#include <catch2/catch_test_macros.hpp>

#include <stdexcept>


struct ListNode
{
public:
  ListNode(int value, ListNode* prev = nullptr, ListNode* next = nullptr)
    : value(value), prev(prev), next(next)
  {
    if (prev != nullptr) prev->next = this;
    if (next != nullptr) next->prev = this;
  }

public:
  int value;
  ListNode* prev;
  ListNode* next;
};


class List
{
public:
  List()
    : m_head(new ListNode(static_cast<int>(0))), m_size(0),
    m_tail(new ListNode(0, m_head))
  {
  }

  virtual ~List()
  {
    Clear();
    delete m_head;
    delete m_tail;
  }

  bool Empty() { return m_size == 0; }

  unsigned long Size() { return m_size; }

  void PushFront(int value)
  {
    new ListNode(value, m_head, m_head->next);
    ++m_size;
  }

  void PushBack(int value)
  {
    new ListNode(value, m_tail->prev, m_tail);
    ++m_size;
  }

  int PopFront()
  {
    if (Empty()) throw std::runtime_error("list is empty");
    auto node = extractPrev(m_head->next->next);
    int ret = node->value;
    delete node;
    return ret;
  }

  int PopBack()
  {
    if (Empty()) throw std::runtime_error("list is empty");
    auto node = extractPrev(m_tail);
    int ret = node->value;
    delete node;
    return ret;
  }

  void Clear()
  {
    auto current = m_head->next;
    while (current != m_tail)
    {
      current = current->next;
      delete extractPrev(current);
    }
  }

private:
  ListNode* extractPrev(ListNode* node)
  {
    auto target = node->prev;
    target->prev->next = target->next;
    target->next->prev = target->prev;
    --m_size;
    return target;
  }

private:
  ListNode* m_head;
  ListNode* m_tail;
  unsigned long m_size;
};

//юнит-тест
TEST_CASE("PushBack()") {
  List myList;
  REQUIRE(myList.Size() == 0);
  myList.PushBack(1);
  REQUIRE(myList.Size() == 1);
  myList.PushBack(1);
  REQUIRE(myList.Size() == 2);
}

TEST_CASE("PushFront()") {
  List myList;
  REQUIRE(myList.Size() == 0);
  myList.PushFront(1);
  REQUIRE(myList.Size() == 1);
  myList.PushFront(1);
  REQUIRE(myList.Size() == 2);
}

TEST_CASE("PopBack()") {
  List myList;
  REQUIRE_THROWS_AS(myList.PopBack(), std::runtime_error);
}

TEST_CASE("PopFront()") {
  List myList;
  REQUIRE_THROWS_AS(myList.PopFront(), std::runtime_error);
}


TEST_CASE("Hard Test PopFront") {
  List myList;
  myList.PushBack(2);
  myList.PushBack(3);
  myList.PushFront(1);
  REQUIRE(myList.PopFront() == 1);
  REQUIRE(myList.PopFront() == 2);
  REQUIRE(myList.PopFront() == 3);
}

TEST_CASE("Hard Test PopBack") {
  List myList;
  myList.PushBack(20);
  myList.PushFront(30);
  myList.PushBack(10);
  REQUIRE(myList.PopBack() == 10);
  REQUIRE(myList.PopBack() == 20);
  REQUIRE(myList.PopBack() == 30);
}

