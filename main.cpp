
#include <iostream>
#include "Board.hpp"

int main() {
    Node node1(1, {2, 3, 4});
    Node node2(2, {1, 3, 5});

    std::cout << node1.isNeighbourOf(5) << std::endl;  // Output: 1 (true)

    return 0;
}
