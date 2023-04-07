#pragma once
#include <iostream>

template <class T>
class BinarySearchTree {
private:
	template <class T>
	struct Node {
		T key_;
		Node<T>* left_;
		Node<T>* right_;
		Node(T key, Node* left = nullptr, Node* right = nullptr, Node* p = nullptr) :
			key_(key), left_(left), right_(right) {  }
	};
	Node<T>* iterativeSearchNode(const T& key) const;
	void printNode(std::ostream& out, Node<T>* root, int level = 0) const;
	int getCount(const Node<T>* node) const;
	int getHeight(const Node<T>* node) const;
	void inorderWalk(Node<T>* node) const;
	Node<T>* root_;

public:
	BinarySearchTree();
	BinarySearchTree(const BinarySearchTree<T>& src) = delete; 
	BinarySearchTree(BinarySearchTree<T>&& src) noexcept; 
	BinarySearchTree <T>& operator= (const BinarySearchTree <T>& src) = delete; 
	BinarySearchTree <T>& operator= (BinarySearchTree <T>&& src) noexcept; 
	virtual ~BinarySearchTree();
	bool iterativeSearch(const T& key) const; 
	bool insert(const T& key); 
	bool deleteKey(const T& key);
	void print(std::ostream& out) const; 
	int getCount() const; 
	int getHeight() const; 
	void iterativeInorderWalk() const; 
	void inorderWalk() const;  
	void walkByLevels() const; 
	bool isSimilar(const BinarySearchTree<T> & other) const; 
	bool isIdenticalKey(const BinarySearchTree<T> & other) const;
}; 
