#include <iostream>
#include "BinarySearchTree.h"
#include "BinarySearchTree.cpp"

int main() {
    std::cout << std::boolalpha;
    BinarySearchTree<int> bst1;
    bst1.insert(8);
    bst1.insert(3);
    bst1.insert(10);
    bst1.insert(1);
    bst1.insert(6);
    bst1.insert(14);
    bst1.insert(4);
    bst1.insert(7);
    bst1.insert(13);
    bst1.print(std::cout);
    std::cout << "\n" << bst1.getCount() << "\n";
    bst1.iterativeInorderWalk();
    std::cout << "\n";
    std::cout << bst1.iterativeSearch(9) << "\n";
    bst1.deleteKey(10);
    bst1.print(std::cout);
    std::cout << bst1.getCount();
    std::cout << "\n" << bst1.getHeight() << "\n";
    bst1.iterativeInorderWalk();
    std::cout << "\n";
    bst1.inorderWalk();
    std::cout << "\n";
    bst1.walkByLevels();
    std::cout << "\n";

    BinarySearchTree<int> bst2;
    bst2.insert(3);
    bst2.insert(2);
    bst2.insert(5);
    bst2.insert(15);
    bst2.insert(0);
    bst2.print(std::cout);
    std::cout << "\n" << bst1.isSimilar(bst2) << "\n";
    std::cout << bst1.isIdenticalKey(bst2);
}