#include "BinarySearchTree.h"
#include <iostream>
#include <stack>
#include <queue>

template <class T> BinarySearchTree<T>::BinarySearchTree() : root_(nullptr) {};
template <class T> BinarySearchTree<T>::BinarySearchTree(BinarySearchTree<T>&& src) noexcept : root_(src.root_) { src.root_ = nullptr; };
template <class T> BinarySearchTree<T>::~BinarySearchTree() {};
template <class T> BinarySearchTree<T>& BinarySearchTree<T>::operator=(BinarySearchTree<T>&& src) noexcept {
	if (this != &src) {
		clear(root_);
		root_ = src.root_;
		src.root_ = nullptr;
	}
	return *this;
}

template <class T> 
BinarySearchTree<T>::Node<T>* BinarySearchTree<T>::iterativeSearchNode(const T& key) const {
	Node<T>* current = root_;
	while (current != nullptr) {
		if (current->key_ == key) {
			return current;
		}
		else if (current->key_ > key) {
			current = current->left_;
		}
		else if (current->key_ < key) {
			current = current->right_;
		}
	}
	return nullptr;
}

template <class T>
void BinarySearchTree<T>::printNode(std::ostream& out, Node<T>* root, int level) const{
	if (root == nullptr)
		return;
	level++;
	printNode(out, root->right_, level);
	std::string spaces;
	for (int i = 0; i < level - 1; ++i)
		spaces += '\t';
	out << spaces << root->key_ << "\n";
	printNode(out, root->left_, level);
}

template <class T>
int BinarySearchTree<T>::getCount(const Node<T>* node) const {
	if (node == nullptr) { 
		return 0; 
	}
	return (1 + getCount(node->left_) + getCount(node->right_));
}

template <class T>
int BinarySearchTree<T>::getHeight(const Node<T>* node) const {
	if (node == nullptr) 
		return 0;

	int left = getHeight(node->left_);
	int right = getHeight(node->right_);
	return (1 + std::max(left, right));
}

template <class T>
void BinarySearchTree<T>::inorderWalk(Node<T>* node) const {
	if (node != nullptr) {
		inorderWalk(node->left_);
		std::cout << node->key_ << " ";
		inorderWalk(node->right_);
	}
}

template <class T>
bool BinarySearchTree<T>::iterativeSearch(const T& key) const {
	Node<T>* node = iterativeSearchNode(key);
	return (node != nullptr);
}

template <class T>
void BinarySearchTree<T>::print(std::ostream& out) const {
	printNode(out, root_);
}

template <class T>
bool BinarySearchTree<T>::insert(const T& key) {
	Node<T>* parent = nullptr;
	Node<T>* current = root_;

	while (current != nullptr) {
		parent = current;
		if (key == current->key_)
			return false;
		else if (key < current->key_)
			current = current->left_;
		else
			current = current->right_;
	}

	Node<T>* newNode = new Node<T>(key);
	if (parent == nullptr)
		root_ = newNode;
	else if (key < parent->key_)
		parent->left_ = newNode;
	else
		parent->right_ = newNode;
	return true;
}

template <class T>
bool BinarySearchTree<T>::deleteKey(const T& key) {
	if (root_ == nullptr)
		return false;

	Node<T>* current = root_;
	Node<T>* parent = nullptr;
	bool found = false;

	while (!found && current) {
		if (current->key_ == key)
			found = true;
		else
		{
			parent = current;
			if (current->key_ > key)
				current = current->left_;
			else
				current = current->right_;
		}
	}
	if (!found)
		return false;

	if (current->left_ == nullptr || current->right_ == nullptr)
	{
		Node<T>* temp;
		temp = current->left_ ? current->left_ : current->right_;
		if (parent) {
			if (parent->left_ == current)
				parent->left_ = temp;
			else
				parent->right_ = temp;
		}
		else {
			root_ = temp;
		}
	}
	else {
		Node<T>* temp = current->right_;
		Node<T>* tempParent = current;

		while (temp->left_ != nullptr) {
			tempParent = temp;
			temp = temp->left_;
		}

		current->key_ = temp->key_;
		if (tempParent->left_ == temp)
			tempParent->left_ = temp->right_;
		else
			tempParent->right_ = temp->right_;
		delete temp;
	}
	return true;
}

template <class T>
int BinarySearchTree<T>::getCount() const {
	return getCount(root_);
}

template <class T>
int BinarySearchTree<T>::getHeight() const {
	return getHeight(root_);
}

template <class T>
void BinarySearchTree<T>::iterativeInorderWalk() const {
	if (root_ == nullptr) {
		return;
	}
	std::stack<Node<T>*> stack;
	Node<T>* current = root_;
	while (current != nullptr || !stack.empty()) {
		while (current != nullptr) {
			stack.push(current);
			current = current->left_;
		}
		current = stack.top();
		stack.pop();
		std::cout << current->key_ << " ";
		current = current->right_;
	}
}

template <class T>
void BinarySearchTree<T>::inorderWalk() const {
	inorderWalk(root_);
}

template <class T>
void BinarySearchTree<T>::walkByLevels() const {
	if (root_ == nullptr)
	{
		return;
	}
	std::queue<Node<T>*> q;
	q.push(root_);

	while (!q.empty()) 
	{
		Node<T>* temp = q.front();
		q.pop();
		std::cout << temp->key_ << " ";

		if (temp->left_ != nullptr)
			q.push(temp->left_);

		if (temp->right_ != nullptr)
			q.push(temp->right_);
	}
}

template <class T>
bool BinarySearchTree<T>::isSimilar(const BinarySearchTree<T>& other) const {
	if (root_ == nullptr && other.root_ == nullptr)
		return true;
	else if (root_ == nullptr || other.root_ == nullptr)
		return false;
	else if ((getCount(root_)) != (other.getCount(other.root_))) {
		return false;
	}
	return (getHeight(root_) == other.getHeight(other.root_));
}

template <class T>
bool BinarySearchTree<T>::isIdenticalKey(const BinarySearchTree<T>& other) const {
	std::stack<Node<T>*> stack1;
	stack1.push(root_);
	while (stack1.empty() == false)
	{
		Node<T>* temp = stack1.top();
		stack1.pop();
		if (other.iterativeSearch(temp->key_))
			return true;

		if (temp->right_)
			stack1.push(temp->right_); 
		if (temp->left_)
			stack1.push(temp->left_);
	}
	return false;
}
