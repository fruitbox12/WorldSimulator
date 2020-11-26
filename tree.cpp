#include "tree.h"

template <typename T1, typename T2>
Tree<T1, T2>::Tree() : SubTree<T1, T2>() {
	errors	 = 0;
	warnings = 0;
}

template <typename T1, typename T2>
Tree<T1, T2>::Tree(int level, T1 key, bool allowDuplicates) : SubTree<T1, T2>(level, key, allowDuplicates) {
	errors	 = 0;
	warnings = 0;
}

template <typename T1, typename T2>
Tree<T1, T2>::~Tree() {
}

/*
	findRootSubtree will return a pointer to the Tree containing the key,
	or nullptr if the key is not found anywhere in the Tree
*/
template <typename T1, typename T2>
Tree<T1, T2>* Tree<T1, T2>::findTree(T1 key) {
	Tree<T1, T2>* tree = nullptr;

	// Get the our Tree's root Node key
	T1 nodeKey = SubTree<T1, T2>::getKey();

	// Check the root Node of our own Tree
	if (key == nodeKey) {
		tree = this;
	}
	else {
		// Recursively check if key comes before our Tree's root Node key
		if (key < nodeKey) {
			Tree<T1, T2>* prevTree = getPrevTree();

			if (prevTree != nullptr) {
				tree = findTreeRecursive(prevTree, key);
			}
		}
		// Key must come after our Tree's root Node key. Recursively check.
		else {
			Tree<T1, T2>* nextTree = getNextTree();

			if (nextTree != nullptr) {
				tree = findTreeRecursive(nextTree, key);
			}
		}
	}

	return tree;
}

/*
	findRootSubtree will return a pointer to the Tree containing the root Node key,
	or nullptr if the key is not found anywhere in the Tree
*/
template <typename T1, typename T2>
Tree<T1, T2>* Tree<T1, T2>::findTreeRecursive(Tree<T1, T2>* subTree, T1 key) {
	Tree<T1, T2>* tree = nullptr;

	// Get the subtree's root Node key
	T1 nodeKey = subTree->getKey();

	// Check the subtree's root Node
	if (key == nodeKey) {
		tree = subTree;
	}
	else {
		// Recursively check if key comes before the subtree's root Node key
		if (key < nodeKey) {
			Tree<T1, T2>* prevTree = subTree->getPrevTree();

			if (prevTree != nullptr) {
				tree = findTreeRecursive(prevTree, key);
			}
		}
		// Key must come after the subtree's root Node key. Recursively check.
		else {
			Tree<T1, T2>* nextTree = subTree->getNextTree();

			if (nextTree != nullptr) {
				tree = findTreeRecursive(nextTree, key);
			}
		}
	}

	return tree;
}

template <typename T1, typename T2>
int Tree<T1, T2>::addTreeRecursive(Tree<T1, T2>* subTree, Tree<T1, T2>* newTree) {
	int added = NODE_ADDED;

	// Get the subtree's root Node keys
	T1 subTreeRootNodeKey = subTree->getKey();
	T1 newTreeRootNodeKey = newTree->getKey();

	// If duplicates are not allowed, find out if the new Tree's root Node key is already in the Tree
	// and if so do not add the new Node
	if (!subTree->duplicatesAllowed()) {
		Tree<T1, T2>* tree = findTree(newTreeRootNodeKey);
		if (tree != nullptr) {
			added = DUPLICATE_NODE;
		}
	}

	if (added != DUPLICATE_NODE) {
		// Recursively check if the new Tree's root Node key
		// is equal to the root Node key or comes before it
		if (newTreeRootNodeKey <= subTreeRootNodeKey) {
			Tree<T1, T2>* prevTree = nullptr;

			if (newTree->getLevel() == 1) {
				prevTree = subTree->getPrevTree();

				if (prevTree == nullptr) {
					// Add the new Tree to the root tree
					subTree->setPrevTree(newTree);

					SubTree<T1, T2>::setSize(SubTree<T1, T2>::getSize() + 1);
					SubTree<T1, T2>::setSubtreeSize(SubTree<T1, T2>::getSubtreeSize() + 1);
				}
				else {
					added = addTreeRecursive(prevTree, newTree);
				}
			}
			else {
				prevTree = subTree->getPrevSubtree();

				if (prevTree == nullptr) {
					// Add the new Tree to the parent tree
					subTree->setPrevSubtree(newTree);

					SubTree<T1, T2>::setSize(SubTree<T1, T2>::getSize() + 1);
					SubTree<T1, T2>::setSubtreeSize(SubTree<T1, T2>::getSubtreeSize() + 1);
				}
				else {
					added = addTreeRecursive(prevTree, newTree);
				}
			}
		}
		// The new Tree's root Node key must come after the subtree's Node key. Recursively check.
		else {
			Tree<T1, T2>* nextTree = nullptr;

			if (newTree->getLevel() == 1) {
				nextTree = subTree->getNextTree();

				if (nextTree == nullptr) {
					// Add the new Tree to the root tree
					subTree->setNextTree(newTree);

					SubTree<T1, T2>::setSize(SubTree<T1, T2>::getSize() + 1);
					SubTree<T1, T2>::setSubtreeSize(SubTree<T1, T2>::getSubtreeSize() + 1);
				}
				else {
					added = addTreeRecursive(nextTree, newTree);
				}
			}
			else {
				nextTree = subTree->getNextSubtree();

				if (nextTree == nullptr) {
					// Add the new Tree to the parent tree
					subTree->setNextSubtree(newTree);

					SubTree<T1, T2>::setSize(SubTree<T1, T2>::getSize() + 1);
					SubTree<T1, T2>::setSubtreeSize(SubTree<T1, T2>::getSubtreeSize() + 1);
				}
				else {
					added = addTreeRecursive(nextTree, newTree);
				}
			}
		}
	}

	return added;
}

template <typename T1, typename T2>
int Tree<T1, T2>::getErrors() const {
	return errors;
}

template <typename T1, typename T2>
int Tree<T1, T2>::getWarnings() const {
	return warnings;
}

template <typename T1, typename T2>
Tree<T1, T2>* Tree<T1, T2>::getPrevTree() {
	return prevTree;
}

template <typename T1, typename T2>
Tree<T1, T2>* Tree<T1, T2>::getNextTree() {
	return nextTree;
}

template <typename T1, typename T2>
void Tree<T1, T2>::setPrevTree(Tree<T1, T2>* newTree) {
	prevTree = newTree;
}

template <typename T1, typename T2>
void Tree<T1, T2>::setNextTree(Tree<T1, T2>* newTree) {
	nextTree = newTree;
}

template <typename T1, typename T2>
void Tree<T1, T2>::setErrors(int errors) {
	this->errors = errors;
}

template <typename T1, typename T2>
void Tree<T1, T2>::setWarnings(int warnings) {
	this->warnings = warnings;
}

template <typename T1, typename T2>
int Tree<T1, T2>::addTree(Tree<T1, T2>* newTree) {
	int added = NODE_ADDED;

	// Get the parent Tree keys
	T1 parentRootNodeKey	= SubTree<T1, T2>::getKey();
	T1 newTreeRootNodeKey	= newTree->getKey();

	// If duplicates are not allowed, find out if the new Tree's parent Node key is already in the Tree
	// and if so do not add the new Tree
	if (!SubTree<T1, T2>::duplicatesAllowed()) {
		Tree<T1, T2>* tree = Tree<T1,T2>::findTree(newTreeRootNodeKey);
		if (tree != nullptr) {
			added = DUPLICATE_NODE;
		}
	}

	if (added != DUPLICATE_NODE) {
		// Recursively check if the new Tree's root Node key
		// is equal to the parent root Node key or comes before it
		if (newTreeRootNodeKey <= parentRootNodeKey) {
			Tree<T1, T2>* prevTree = nullptr;

			if (newTree->getLevel() == 1) {
				prevTree = getPrevTree();

				if (prevTree == nullptr) {
					// Add the new Tree to the root tree
					setPrevTree(newTree);

					SubTree<T1, T2>::setSize(SubTree<T1, T2>::getSize() + 1);
					SubTree<T1, T2>::setSubtreeSize(SubTree<T1, T2>::getSubtreeSize() + 1);
				}
				else {
					added = addTreeRecursive(prevTree, newTree);
				}
			}
			else {
				prevTree = SubTree<T1, T2>::getPrevSubtree();

				if (prevTree == nullptr) {
					// Add the new Tree to the parent tree
					SubTree<T1, T2>::setPrevSubtree(newTree);

					SubTree<T1, T2>::setSize(SubTree<T1, T2>::getSize() + 1);
					SubTree<T1, T2>::setSubtreeSize(SubTree<T1, T2>::getSubtreeSize() + 1);
				}
				else {
					added = addTreeRecursive(prevTree, newTree);
				}
			}
		}
		// The new Tree's root Node key must come after the parent Tree root Node key. Recursively check.
		else {
			Tree<T1, T2>* nextTree = nullptr;

			if (newTree->getLevel() == 1) {
				nextTree = getNextTree();

				if (nextTree == nullptr) {
					// Add the new Tree to the root tree
					setNextTree(newTree);

					SubTree<T1, T2>::setSize(SubTree<T1, T2>::getSize() + 1);
					SubTree<T1, T2>::setSubtreeSize(SubTree<T1, T2>::getSubtreeSize() + 1);
				}
				else {
					added = addTreeRecursive(prevTree, newTree);
				}
			}
			else {
				nextTree = SubTree<T1, T2>::getNextSubtree();

				if (nextTree == nullptr) {
					// Add the new Tree to the parent tree
					SubTree<T1, T2>::setNextSubtree(newTree);

					SubTree<T1, T2>::setSize(SubTree<T1, T2>::getSize() + 1);
					SubTree<T1, T2>::setSubtreeSize(SubTree<T1, T2>::getSubtreeSize() + 1);
				}
				else {
					added = addTreeRecursive(nextTree, newTree);
				}
			}
		}
	}

	return added;
}

template <typename T1, typename T2>
std::vector<Tree<T1, T2>*> Tree<T1, T2>::inOrderTraversal() {
	std::vector<Tree<T1, T2>*> traverse;

	// Recursively begin at the root tree
	inOrderTraversalRecursive(this, traverse);

	return traverse;
}

template <typename T1, typename T2>
void Tree<T1, T2>::inOrderTraversalRecursive(Tree<T1, T2>* nextTree, std::vector<Tree<T1, T2>*> &traverse) {

	if (nextTree != nullptr) {
		// Recursively traverse the left (previous) tree
		inOrderTraversalRecursive(nextTree->getPrevTree(), traverse);

		// Do not include the root tree, only its subtrees
		if (nextTree->getLevel() > 0) {
			traverse.push_back(nextTree);
		}

		// Recursively traverse the right (next) tree
		inOrderTraversalRecursive(nextTree->getNextTree(), traverse);
	}
}

template <typename T1, typename T2>
std::vector<Tree<T1, T2>*> Tree<T1, T2>::getTreesInOrder() {
	return inOrderTraversal();
}
