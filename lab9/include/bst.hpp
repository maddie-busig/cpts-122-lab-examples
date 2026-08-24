#pragma once

#include <utility>
#include <iostream>

template <typename T>
class bst {
private:
	class node;

public:
	bst() : m_root(nullptr) {}

	/*
	 * COPY constructor
	 */
	bst(const bst<T>& other);
	/*
	 * MOVE constructor
	 *
	 * If you're interested check this out :3
	 * https://www.en.cppreference.com/w/cpp/language/move_constructor.html
	 */
	bst(bst<T>&& other) : m_root(std::exchange(other.m_root, nullptr)) {}
	
	/*
	 * Copy-assignment operator
	 *
	 * NOTE: We're not passing the argument by reference, we're passing it
	 * by value. This will cause `rhs` to be COPY constructed if an l-value
	 * reference is given, and MOVE constructed if an r-value reference
	 * is given.
	 *
	 * After the parameter is constructed we have a copy already, so we can
	 * SWAP `this` and `rhs`. We do this by implementing a member `swap` function.
	 *
	 * Implementing the assignment operator this way lets us avoid making
	 * unnecessary copies by taking advantage of MOVE SEMANTICS.
	 * It also means we don't need to duplicate code between our
	 * copy constructor and assignment operator, we can just reuse the constructors.
	 *
	 * If you want to learn more, look up "copy-swap idiom", "move semantics"
	 * "move constructor", "r-value references", "l-value references"
	 */
	bst<T>& operator=(bst<T> rhs);
	
	~bst() {
		clear();
	}

	void swap(bst<T>& other) {
		std::swap(m_root, other.m_root);
	}

	void insert(const T& value) {
		insert_into_tree(m_root, value);
	}

	void clear() {
		clear_tree(m_root);
	}

	bool empty() const {
		return m_root == nullptr;
	}
	
	void print_inorder(std::ostream& stream = std::cout) const;
	void print_preorder(std::ostream& stream = std::cout) const;
	void print_postorder(std::ostream& stream = std::cout) const;

private:
	/*
	 * Copies the src root's tree into the dest root
	 *
	 * PRECONDITION: dest_root == nullptr
	 *
	 * throws if dest_root is not nullptr
	 */
	static void copy_tree(node*& dest_root_out, node* src_root);

	/*
	 * Clears the entire tree starting from the root.
	 *
	 * POSTCONDITION: root == nullptr
	 */
	static void clear_tree(node*& root);

	/*
	 * Inserts value into the tree starting at the given root
	 */
	static void insert_into_tree(node*& root, const T& value);

	node* m_root;

	struct node {
		node(const T& v) : value(v) {}
		node(T&& v) : value(v) {}

		T value;
		node* left = nullptr;
		node* right = nullptr;
	};
};

template <typename T>
std::ostream& operator<<(std::ostream& stream, const bst<T>& rhs) {
	rhs.print_inorder(stream);
	return stream;
}

template <typename T>
bst<T>::bst(const bst<T>& other) : m_root(nullptr) {
	copy(m_root, other.m_root);
}

template <typename T>
void bst<T>::copy_tree(bst<T>::node*& dest_root, node* src_root) {
	// If the destination was not deallocate prior, we would have a mem leak
	if (dest_root != nullptr) {
		throw std::invalid_argument("Destination root was not deallocated before copy.");
	}

	// If there is no tree to copy, then we reached the base case
	if (src_root == nullptr) {
		return;
	}

	dest_root = new node(src_root->value);

	copy_tree(dest_root->left, src_root->left);
	copy_tree(dest_root->right, src_root->right);
}

template <typename T>
void bst<T>::clear_tree(bst<T>::node*& root) {
	if (root == nullptr) {
		return;
	}

	clear_tree(root->left);
	clear_tree(root->right);

	delete root;
	root = nullptr;
}

template <typename T>
void bst<T>::insert_into_tree(bst<T>::node*& root, const T& value) {
	if (root == nullptr) {
		root = new node(value);
		return;
	}

	if (value < root->value) {
		insert_into_tree(root->left, value);
	} else if (value > root->value) {
		insert_into_tree(root->right, value);
	} else {
		return; // duplicate node, do nothing
	}
}

