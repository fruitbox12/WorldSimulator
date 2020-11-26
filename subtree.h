#pragma once

#include "constants.h"
#include "node.h"
#include <vector>

// Class forwarding
template <typename T1, typename T2>
class Tree;

template <typename T1, typename T2>

class SubTree : public Node<T1, T2> {
	private:
		// The SubTree IS A Node, it has its own root Node, no need to add it.
		// A tree's Nodes are linked off its root Node.
		int				level;
		T1				key;
		T2				value;
		int				size;
		int				nodeSize;
		int				subtreeSize;
		bool			allowDuplicates;

		// SubTree links for a SubTree's own subtrees.
		// The root tree's Subtree's Tree links are always null.
		Tree<T1, T2>*	prevSubtree;
		Tree<T1, T2>*	nextSubtree;

		// Helper functions
		Node<T1, T2>*					findNode(T1 key);
		Tree<T1, T2>*					findSubtree(T1 key);
		std::vector<SubTree<T1, T2>*>	inOrderSubtreeTraversal();
		std::vector<SubTree<T1, T2>*>	inOrderSubtreeTraversal(int level);
		std::vector<std::pair<T1, T2>>	inOrderNodeTraversal();

		// Recursive helper functions
		Node<T1, T2>*					findNodeRecursive(Node<T1, T2>* nextNode, T1 key);
		Tree<T1, T2>*					findSubtreeRecursive(Tree<T1, T2>* subTree, T1 key);
		int								addSubtreeRecursive(Tree<T1, T2>* subTree, Tree<T1, T2>* newTree);
		int								addNodeRecursive(Node<T1, T2>* nextNode, T1 key, T2 value);
		void							inOrderNodeTraversalRecursive(Node<T1, T2>* nextNode, std::vector<std::pair<T1, T2>> &traverse);
		void							inOrderSubtreeTraversalRecursive(SubTree<T1, T2>* nextTree, std::vector<SubTree<T1, T2>*> &traverse);
		void							inOrderSubtreeTraversalRecursive(SubTree<T1, T2>* nextTree, std::vector<SubTree<T1, T2>*> &traverse, int level);

	public:
		SubTree();
		SubTree(int level, T1 key, bool allowDuplicates = false);
		~SubTree();
	
		// Getters
		int				getLevel();
		bool			isRoot();
		T1				getKey();
		T2				getValue();
		int				getSize();
		int				getSubtreeSize();
		int				getNodeSize();
		bool			isEmpty();
		bool			duplicatesAllowed();
		Tree<T1, T2>*	getPrevSubtree();
		Tree<T1, T2>*	getNextSubtree();

		// Setters
		void			setLevel(int level);
		void			setSize(int size);
		void			setSubtreeSize(int size);
		void			setNodeSize(int size);
		void			setPrevSubtree(Tree<T1, T2>* newTree);
		void			setNextSubtree(Tree<T1, T2>* newTree);
		
		int				addSubtree(Tree<T1,T2>* newTree);
		int				addNode(T1 key, T2 value);
		
		// YET TO BE IMPLEMENTED:
		// See a good article on Tree Traversals
		// http://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/
		// See a good article on Level Order Tree Traversal
		// http://www.geeksforgeeks.org/?p=2686

		// Binary Tree Example:
		//			1
		//		2		3
		//	4		5
		//
		//				"M"								"WORLD"
		//		"D"				"O"					"A-L"
		//	"A"		"F"		"N"		"P"			"A-L"
		//									"A-L"
		
		// Depth First Traversals (from the bottom up):
		// Pre-Order Traversal: (1-2-4-5-3)
		// Used to create a copy of the tree. Also used to get prefix expression on of an expression tree.
		// Please see http://en.wikipedia.org/wiki/Polish_notation
		// to know why prefix expressions are useful.
		void preOrderTraversal();

		// In-Order Traversal: (4-2-5-1-3)
		// In case of binary search trees (BST), Inorder traversal gives nodes in non-decreasing order
		std::vector<SubTree<T1, T2>*> getSubtreesInOrder();
		std::vector<SubTree<T1, T2>*> getSubtreesInOrder(int level);
		std::vector<std::pair<T1, T2>> getNodesInOrder();
		
		// Post-Order Traversal: (4-5-2-3-1)
		// Used to delete the tree. Also useful to get the postfix expression of an expression tree.
		// Please see http://en.wikipedia.org/wiki/Reverse_Polish_notation
		// for the usage of postfix expression.
		void postOrderTraversal();

		// Breadth First Traversal (from the root down):
		// Level-Order Traversal: (1 2 3 4 5)
		void levelOrderTraversal();

		void updateSubtree();
		void updateNode();
		void deleteSubtree();
		void deleteNode();
		void copySubtree();
		void copyNode();
};
