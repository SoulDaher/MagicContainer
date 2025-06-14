#include <iostream>
#include "include/MyContainer.hpp"
#include "src/MyContainer.cpp"

using namespace cont;

int main() {
    MyContainer<int> container;
    container.add(7);
    container.add(15);
    container.add(6);
    container.add(1);
    container.add(2);

    std::cout << "Size of container: " << container.size() << std::endl;

    for (auto it = container.begin_ascending_order(); it != container.end_ascending_order(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    for (auto it = container.begin_descending_order(); it != container.end_descending_order(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    for (auto it = container.begin_side_cross_order(); it != container.end_side_cross_order(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    for (auto it = container.begin_reverse_order(); it != container.end_reverse_order(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    for (auto it = container.begin_order(); it != container.end_order(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    for (auto it = container.begin_middle_out_order(); it != container.end_middle_out_order(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    return 0;
}
