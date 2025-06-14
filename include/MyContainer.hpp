#ifndef MY_CONTAINER_HPP
#define MY_CONTAINER_HPP

#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>

namespace cont {

template <typename T = int> class MyContainer {
private:
  std::vector<T> data;

public:
  MyContainer() = default;

  void add(const T &value) { data.push_back(value); }

  void remove(const T &value) {
    auto original_size = data.size();
    data.erase(std::remove(data.begin(), data.end(), value), data.end());
    if (data.size() == original_size) {
      throw std::runtime_error("Element not found");
    }
  }

  size_t size() const { return data.size(); }

  friend std::ostream &operator<<(std::ostream &os,
                                  const MyContainer<T> &container) {
    os << "[";
    for (size_t i = 0; i < container.data.size(); ++i) {
      os << container.data[i];
      if (i + 1 < container.data.size())
        os << ", ";
    }
    os << "]";
    return os;
  }

  const std::vector<T> &getData() const { return data; }

  class AscendingOrder {
    std::vector<T> sorted;
    size_t index;

  public:
    AscendingOrder(const MyContainer<T> &c) {
      sorted = c.getData();
      std::sort(sorted.begin(), sorted.end());
      index = 0;
    }
    AscendingOrder begin() const {
      AscendingOrder it(*this);
      it.index = 0;
      return it;
    }
    AscendingOrder end() const {
      AscendingOrder it(*this);
      it.index = sorted.size();
      return it;
    }
    bool operator!=(const AscendingOrder &other) const {
      return index != other.index;
    }
    const T &operator*() const { return sorted[index]; }
    AscendingOrder &operator++() {
      ++index;
      return *this;
    }
  };

  class DescendingOrder {
    std::vector<T> sorted;
    size_t index;

  public:
    DescendingOrder(const MyContainer<T> &c) {
      sorted = c.getData();
      std::sort(sorted.begin(), sorted.end(), std::greater<T>());
      index = 0;
    }
    DescendingOrder begin() const {
      DescendingOrder it(*this);
      it.index = 0;
      return it;
    }
    DescendingOrder end() const {
      DescendingOrder it(*this);
      it.index = sorted.size();
      return it;
    }
    bool operator!=(const DescendingOrder &other) const {
      return index != other.index;
    }
    const T &operator*() const { return sorted[index]; }
    DescendingOrder &operator++() {
      ++index;
      return *this;
    }
  };

  class SideCrossOrder {
    std::vector<T> order;
    size_t index;

  public:
    SideCrossOrder(const MyContainer<T> &c) {
      auto sorted = c.getData();
      std::sort(sorted.begin(), sorted.end());
      size_t left = 0, right = sorted.size() - 1;
      while (left <= right) {
        order.push_back(sorted[left++]);
        if (left <= right)
          order.push_back(sorted[right--]);
      }
      index = 0;
    }
    SideCrossOrder begin() const {
      SideCrossOrder it(*this);
      it.index = 0;
      return it;
    }
    SideCrossOrder end() const {
      SideCrossOrder it(*this);
      it.index = order.size();
      return it;
    }
    bool operator!=(const SideCrossOrder &other) const {
      return index != other.index;
    }
    const T &operator*() const { return order[index]; }
    SideCrossOrder &operator++() {
      ++index;
      return *this;
    }
  };

  class ReverseOrder {
    std::vector<T> reversed;
    size_t index;

  public:
    ReverseOrder(const MyContainer<T> &c) {
      reversed = c.getData();
      std::reverse(reversed.begin(), reversed.end());
      index = 0;
    }
    ReverseOrder begin() const {
      ReverseOrder it(*this);
      it.index = 0;
      return it;
    }
    ReverseOrder end() const {
      ReverseOrder it(*this);
      it.index = reversed.size();
      return it;
    }
    bool operator!=(const ReverseOrder &other) const {
      return index != other.index;
    }
    const T &operator*() const { return reversed[index]; }
    ReverseOrder &operator++() {
      ++index;
      return *this;
    }
  };

  class Order {
    const std::vector<T> &ref;
    size_t index;

  public:
    Order(const MyContainer<T> &c) : ref(c.getData()), index(0) {}
    Order begin() const {
      Order it(*this);
      it.index = 0;
      return it;
    }
    Order end() const {
      Order it(*this);
      it.index = ref.size();
      return it;
    }
    bool operator!=(const Order &other) const { return index != other.index; }
    const T &operator*() const { return ref[index]; }
    Order &operator++() {
      ++index;
      return *this;
    }
  };

  class MiddleOutOrder {
    std::vector<T> order;
    size_t index;

  public:
    MiddleOutOrder(const MyContainer<T> &c) {
      auto d = c.getData();
      if (d.empty())
        return;
      int mid = d.size() / 2;
      order.push_back(d[mid]);
      int left = mid - 1, right = mid + 1;
      while (left >= 0 || right < (int)d.size()) {
        if (right < (int)d.size())
          order.push_back(d[right++]);
        if (left >= 0)
          order.push_back(d[left--]);
      }
      index = 0;
    }

    MiddleOutOrder begin() const {
      MiddleOutOrder it(*this);
      it.index = 0;
      return it;
    }
    MiddleOutOrder end() const {
      MiddleOutOrder it(*this);
      it.index = order.size();
      return it;
    }
    bool operator!=(const MiddleOutOrder &other) const {
      return index != other.index;
    }
    const T &operator*() const { return order[index]; }
    MiddleOutOrder &operator++() {
      ++index;
      return *this;
    }
  };

  AscendingOrder begin_ascending_order() const {
    return AscendingOrder(*this).begin();
  }
  AscendingOrder end_ascending_order() const {
    return AscendingOrder(*this).end();
  }

  DescendingOrder begin_descending_order() const {
    return DescendingOrder(*this).begin();
  }
  DescendingOrder end_descending_order() const {
    return DescendingOrder(*this).end();
  }

  SideCrossOrder begin_side_cross_order() const {
    return SideCrossOrder(*this).begin();
  }
  SideCrossOrder end_side_cross_order() const {
    return SideCrossOrder(*this).end();
  }

  ReverseOrder begin_reverse_order() const {
    return ReverseOrder(*this).begin();
  }
  ReverseOrder end_reverse_order() const { return ReverseOrder(*this).end(); }

  Order begin_order() const { return Order(*this).begin(); }
  Order end_order() const { return Order(*this).end(); }

  MiddleOutOrder begin_middle_out_order() const {
    return MiddleOutOrder(*this).begin();
  }
  MiddleOutOrder end_middle_out_order() const {
    return MiddleOutOrder(*this).end();
  }
};

} // namespace cont

#endif
