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
    std::cout << "\nNumber of tree nodes: " << bst1.getCount() << "\n";
    std::cout << "iterativeInorderWalk: ";
    bst1.iterativeInorderWalk();
    std::cout << "\n";
    std::cout << "Search for key 9 in the tree: " << bst1.iterativeSearch(9) << "\n";
    std::cout << "Search for key 8 in the tree: " << bst1.iterativeSearch(8) << "\n";
    std::cout << "Node with key 10 deleted: " << bst1.deleteKey(10) << "\n";
    std::cout << "Node with key 9 deleted: " << bst1.deleteKey(9) << "\n";
    bst1.print(std::cout);
    std::cout << "\nNumber of tree nodes: " << bst1.getCount() << "\n";
    std::cout << "\nTree height: " << bst1.getHeight() << "\n";
    std::cout << "iterativeInorderWalk: ";
    bst1.iterativeInorderWalk();
    std::cout << "\n";
    std::cout << "inorderWalk(recursively): ";
    bst1.inorderWalk();
    std::cout << "\n";
    std::cout << "walkByLevels: ";
    bst1.walkByLevels();
    std::cout << "\n\n";

    BinarySearchTree<int> bst2;
    bst2.insert(3);
    bst2.insert(2);
    bst2.insert(5);
    bst2.insert(15);
    bst2.insert(0);
    bst2.print(std::cout);
    std::cout << "\nThe bst1 and bst2 trees are similar:" << bst1.isSimilar(bst2);
    std::cout << "\nThe bst1 and bst2 trees contain identical keys: " << bst1.isIdenticalKey(bst2);
}