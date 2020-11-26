#pragma once

#include "subtree.h"

template <typename T1, typename T2>

class Tree : public SubTree<T1, T2> {
	private:
		int				errors;
		int				warnings;

		// Additional set of Tree links for Subtrees of the root Tree
		Tree<T1, T2>*	prevTree;
		Tree<T1, T2>*	nextTree;

		// Helper functions
		Tree<T1, T2>* findTree(T1 key);
		std::vector<Tree<T1, T2>*> inOrderTraversal();

		// Recursive helper functions
		Tree<T1, T2>* findTreeRecursive(Tree<T1, T2>* subTree, T1 key);
		int addTreeRecursive(Tree<T1, T2>* subTree, Tree<T1, T2>* newTree);
		void inOrderTraversalRecursive(Tree<T1, T2>* nextTree, std::vector<Tree<T1, T2>*> &traverse);

	public:
		Tree();
		Tree(int level, T1 key, bool allowDuplicates = false);
		~Tree();

		// Getters
		Tree<T1, T2>*	getPrevTree();
		Tree<T1, T2>*	getNextTree();
		int				getErrors() const;
		int				getWarnings() const;

		// Binary Tree Example:
		//			1
		//		2		3
		// 4		5

		// Depth First Traversals (from the bottom up):
		// Pre-Order Traversal: (1-2-4-5-3)
		// Used to create a copy of the tree. Also used to get prefix expression on of an expression tree.
		// Please see http://en.wikipedia.org/wiki/Polish_notation
		// to know why prefix expressions are useful.
		void preOrderTraversal();

		// In-Order Traversal: (4-2-5-1-3)
		// In case of binary search trees (BST), Inorder traversal gives nodes in non-decreasing order
		std::vector<Tree<T1, T2>*> getTreesInOrder();

		// Setters
		void setPrevTree(Tree<T1, T2>* newTree);
		void setNextTree(Tree<T1, T2>* newTree);
		void setErrors(int errors);
		void setWarnings(int warnings);

		Tree<T1, T2>* findTree();
		int addTree(Tree<T1, T2>* newTree);
};
