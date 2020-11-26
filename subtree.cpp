#include "subtree.h"
#include "tree.h"

// The Node(T1 key, T2 value) constructor will be invoked and value will be set to the default value
// for its actual type
template <typename T1, typename T2>
SubTree<T1, T2>::SubTree() : Node<T1, T2>() {
	level					= 0;	// 0: root level
	this->key				= {};
	this->value				= {};
	prevSubtree				= nullptr;
	nextSubtree				= nullptr;
	this->allowDuplicates	= false;
	size					= 0;
	nodeSize				= 0;
	subtreeSize				= 0;
}

template <typename T1, typename T2>
SubTree<T1, T2>::SubTree(int level, T1 key, bool allowDuplicates) : Node<T1, T2>() {
	this->level				= level;
	this->key				= key;
	this->value				= value;
	prevSubtree				= nullptr;
	nextSubtree				= nullptr;
	this->allowDuplicates	= allowDuplicates;
	size					= 0;
	nodeSize				= 0;
	subtreeSize				= 0;
}

template <typename T1, typename T2>
SubTree<T1,T2>::~SubTree() {
	delete prevSubtree;
	delete nextSubtree;
}

template <typename T1, typename T2>
int SubTree<T1, T2>::getLevel() {
	return level;
}

template <typename T1, typename T2>
bool SubTree<T1, T2>::isRoot() {
	return level == 0;
}

template <typename T1, typename T2>
T1 SubTree<T1, T2>::getKey() {
	return key;
}

template <typename T1, typename T2>
T2 SubTree<T1, T2>::getValue() {
	return value;
}

template <typename T1, typename T2>
int SubTree<T1, T2>::getSize() {
	return size;
}

template <typename T1, typename T2>
int SubTree<T1, T2>::getSubtreeSize() {
	return subtreeSize;
}

template <typename T1, typename T2>
int SubTree<T1, T2>::getNodeSize() {
	return nodeSize;
}

template <typename T1, typename T2>
bool SubTree<T1, T2>::isEmpty() {
	return size == 0;
}

template <typename T1, typename T2>
bool SubTree<T1, T2>::duplicatesAllowed() {
	return allowDuplicates;
}

template <typename T1, typename T2>
Tree<T1, T2>* SubTree<T1, T2>::getPrevSubtree() {
	return prevSubtree;
}

template <typename T1, typename T2>
Tree<T1, T2>* SubTree<T1, T2>::getNextSubtree() {
	return nextSubtree;
}

template <typename T1, typename T2>
void SubTree<T1, T2>::setLevel(int level) {
	this->level = level;
}

template <typename T1, typename T2>
void SubTree<T1, T2>::setSize(int size) {
	this->size = size;
}

template <typename T1, typename T2>
void SubTree<T1, T2>::setSubtreeSize(int size) {
	subtreeSize = size;
}

template <typename T1, typename T2>
void SubTree<T1, T2>::setNodeSize(int size) {
	nodeSize = size;
}

template <typename T1, typename T2>
void SubTree<T1, T2>::setPrevSubtree(Tree<T1, T2>* newTree) {
	prevSubtree = newTree;
}

template <typename T1, typename T2>
void SubTree<T1, T2>::setNextSubtree(Tree<T1, T2>* newTree) {
	nextSubtree = newTree;
}

/*
	findNode() will return a pointer to the Node containing the key,
	or nullptr if the key is not found anywhere in the Tree
*/
template <typename T1, typename T2>
Node<T1, T2>* SubTree<T1, T2>::findNode(T1 key) {
	Node<T1, T2>* node = nullptr;
	// Get the root Node key
	T1 nodeKey = Node<T1, T2>::getNodeKey();

	// Check the root Node (our own Node)
	if (key == nodeKey) {
		node = this;
	}
	else {
		// Recursively check if key is equal to the root Node key or comes before it
		if (key <= nodeKey) {
			Node<T1,T2>* newNode = Node<T1, T2>::getPrev();
			
			if (newNode != nullptr) {
				node = findNodeRecursive(newNode, key);
			}
		}
		// Key must come after the root Node key. Recursively check.
		else {
			Node<T1, T2>* newNode = Node<T1, T2>::getNext();

			if (newNode != nullptr) {
				node = findNodeRecursive(newNode, key);
			}
		}
	}

	return node;
}

/*
	findTree() will return a pointer to the Tree containing the key,
	or nullptr if the key is not found anywhere in the Tree
*/

template <typename T1, typename T2>
Tree<T1, T2>* SubTree<T1, T2>::findSubtree(T1 key) {
	Tree<T1, T2>* tree = nullptr;
	 
	// Get the our Tree's root Node key
	T1 nodeKey = getKey();

	// Check the root Node of our own Tree
	if (key == nodeKey) {
		tree = this;
	}
	else {
		// Recursively check if key comes before our Tree's root Node key
		if (key < nodeKey) {
			Tree<T1, T2>* prevTree = getPrevSubtree();

			if (prevTree != nullptr) {
				tree = findTree(prevTree, key);
			}
		}
		// Key must come after our Tree's root Node key. Recursively check.
		else {
			Tree<T1, T2>* nextTree = getNextSubtree();

			if (nextTree != nullptr) {
				tree = findTree(nextTree, key);
			}
		}
	}

	return tree;
}

/*
	find() will return a pointer to the Node (nextNode parm) containing the key,
	or nullptr if the key is not found anywhere in the Tree
*/
template <typename T1, typename T2>
Node<T1, T2>* SubTree<T1, T2>::findNodeRecursive(Node<T1, T2>* nextNode, T1 key) {
	Node<T1, T2>* node = nullptr;
	T1 nodeKey = nextNode->getNodeKey();

	// Check the root Node (our own Node)
	if (key == nodeKey) {
		node = nextNode;
	}
	else {
		// Recursively check if key is equal to the next Node key or comes before it
		if (key <= nodeKey) {
			Node<T1, T2>* newNode = nextNode->getPrev();

			if (newNode != nullptr) {
				node = findNodeRecursive(newNode, key);
			}
		}
		// Key must come after the root Node key. Recursively check.
		else {
			Node<T1, T2>* newNode = nextNode->getNext();

			if (newNode != nullptr) {
				node = findNodeRecursive(newNode, key);
			}
		}
	}

	return node;
}

/*
	findTree() will return a pointer to the Tree containing the root Node key,
	or nullptr if the key is not found anywhere in the Tree
*/
template <typename T1, typename T2>
Tree<T1, T2>* SubTree<T1, T2>::findSubtreeRecursive(Tree<T1, T2>* subTree, T1 key) {
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
				tree = findTree(prevTree, key);
			}
		}
		// Key must come after the subtree's root Node key. Recursively check.
		else {
			Tree<T1, T2>* nextTree = subTree->getNextTree();

			if (nextTree != nullptr) {
				tree = findTree(nextTree, key);
			}
		}
	}

	return tree;
}

template <typename T1, typename T2>
int SubTree<T1, T2>::addSubtree(Tree<T1, T2>* newTree) {
	int added = NODE_ADDED;

	// Get the parent Tree keys
	T1 parentRootNodeKey	= getKey();
	T1 newTreeRootNodeKey	= newTree->getKey();

	// If duplicates are not allowed, find out if the new Tree's parent Node key is already in the Tree
	// and if so do not add the new Tree
	if (!allowDuplicates) {
		Tree<T1, T2>* tree = findTree(newTreeRootNodeKey);
		if (tree != nullptr) {
			added = DUPLICATE_NODE;
		}
	}

	if (added != DUPLICATE_NODE) {
		// Recursively check if the new Tree's root Node key
		// is equal to the parent root Node key or comes before it
		if (newTreeRootNodeKey <= parentRootNodeKey) {
			Tree<T1, T2>* prevTree = getPrevSubtree();

			if (prevTree == nullptr) {
				// Add the new Tree to the parent Tree
				setPrevSubtree(newTree);
				size++;
				subtreeSize++;
			}
			else {
				added = addTree(prevTree, newTree);
			}
		}
		// The new Tree's root Node key must come after the parent Tree root Node key. Recursively check.
		else {
			Tree<T1, T2>* nextTree = getNextSubtree();

			if (nextTree == nullptr) {
				// Add the new Tree to the parent Tree
				setNextSubtree(newTree);
				size++;
				subtreeSize++;
			}
			else {
				added = addTree(nextTree, newTree);
			}
		}
	}

	return added;
}

template <typename T1, typename T2>
int SubTree<T1, T2>::addSubtreeRecursive(Tree<T1, T2>* subTree, Tree<T1, T2>* newTree) {
	int added = NODE_ADDED;
	
	// Get the subtree's root Node keys
	T1 subTreeRootNodeKey	= subTree->getKey();
	T1 newTreeRootNodeKey	= newTree->getKey();

	// If duplicates are not allowed, find out if the new Tree's root Node key is already in the Tree
	// and if so do not add the new Node
	if (!allowDuplicates) {
		Tree<T1, T2>* tree = findTree(newTreeRootNodeKey);
		if (tree != nullptr) {
			added = DUPLICATE_NODE;
		}
	}

	if (added != DUPLICATE_NODE) {
		// Recursively check if the new Tree's root Node key
		// is equal to the root Node key or comes before it
		if (newTreeRootNodeKey <= subTreeRootNodeKey) {
			Tree<T1, T2>* prevTree = subTree->getPrevTree();

			if (prevTree == nullptr) {
				// Add the new Tree to the next Node
				subTree->setPrevTree(newTree);
				size++;
				subtreeSize++;
			}
			else {
				added = addTree(prevTree, newTree);
			}
		}
		// The new Tree's root Node key must come after the subtree's Node key. Recursively check.
		else {
			Tree<T1, T2>* nextTree = subTree->getNextTree();

			if (nextTree == nullptr) {
				// Add the new Tree to the next Node
				subTree->setNextTree(newTree);
				size++;
				subtreeSize++;
			}
			else {
				added = addTree(nextTree, newTree);
			}
		}
	}

	return added;
}

template <typename T1, typename T2>
int SubTree<T1, T2>::addNode(T1 key, T2 value) {
	int added = NODE_ADDED;
	// Get the root Node key
	T1 rootNodeKey = Node<T1, T2>::getNodeKey();

	// If duplicates are not allowed, find out if the key is already in the Tree
	// and if so do not add the new Node
	if (!allowDuplicates) {
		Node<T1, T2>* node = findNode(key);
		if (node != nullptr) {
			added = DUPLICATE_NODE;
		}
	}

	if (added != DUPLICATE_NODE) {
		// Save key and value in root Node if empty
		if (Node<T1, T2>::isEmpty()) {
			Node<T1, T2>::setKey(key);
			Node<T1, T2>::setValue(value);
			size++;
			nodeSize++;
		}

		// Recursively check if key is equal to the root Node key or comes before it
		else if (key <= rootNodeKey) {
			Node<T1, T2>* newNode = Node<T1, T2>::getPrev();

			if (newNode == nullptr) {
				// Add the new Node to the root Node
				Node<T1, T2>* node = new Node<T1, T2>(key, value);
				Node<T1, T2>::setPrev(node);
				size++;
				nodeSize++;
			}
			else {
				added = addNodeRecursive(newNode, key, value);
			}
		}
		// Key must come after the root Node key. Recursively check.
		else {
			Node<T1, T2>* newNode = Node<T1, T2>::getNext();

			if (newNode == nullptr) {
				// Add the new Node to the root Node
				Node<T1, T2>* node = new Node<T1, T2>(key, value);
				Node<T1, T2>::setNext(node);
				size++;
				nodeSize++;
			}
			else {
				added = addNodeRecursive(newNode, key, value);
			}
		}
	}

	return added;
}

template <typename T1, typename T2>
int SubTree<T1, T2>::addNodeRecursive(Node<T1, T2>* nextNode, T1 key, T2 value) {
	int added = NODE_ADDED;
	// Get the next Node key
	T1 nextNodeKey = nextNode->getNodeKey();

	// If duplicates are not allowed, find out if the key is already in the Tree
	// and if so do not add the new Node
	if (!allowDuplicates) {
		Node<T1, T2>* node = findNode(key);
		if (node != nullptr) {
			added = DUPLICATE_NODE;
		}
	}

	if (added != DUPLICATE_NODE) {
		// Recursively check if key is equal to the next Node key or comes before it
		if (key <= nextNodeKey) {
			Node<T1, T2>* newNode = nextNode->getPrev();

			if (newNode == nullptr) {
				// Add the new Node to the next Node
				Node<T1, T2>* node = new Node<T1, T2>(key, value);
				nextNode->setPrev(node);
				size++;
				nodeSize++;
			}
			else {
				added = addNodeRecursive(newNode, key, value);
			}
		}
		// Key must come after the root Node key. Recursively check.
		else {
			Node<T1, T2>* newNode = nextNode->getNext();

			if (newNode == nullptr) {
				// Add the new Node to the next Node
				Node<T1, T2>* node = new Node<T1, T2>(key, value);
				nextNode->setNext(node);
				size++;
				nodeSize++;
			}
			else {
				added = addNodeRecursive(newNode, key, value);
			}
		}
	}

	return added;
}

template <typename T1, typename T2>
std::vector<std::pair<T1, T2>> SubTree<T1, T2>::inOrderNodeTraversal() {
	std::vector<std::pair<T1, T2>> traverse;

	// Recursively begin at the tree root Node
	inOrderNodeTraversalRecursive(this, traverse);

	return traverse;
}

template <typename T1, typename T2>
void SubTree<T1, T2>::inOrderNodeTraversalRecursive(Node<T1, T2>* nextNode, std::vector<std::pair<T1, T2>> &traverse) {
	
	if (nextNode != nullptr) {
		// If the Node is a subtree (not a parent Node object) pass it on
		if (!dynamic_cast<Node<T1,T2>*>(nextNode)) {
			inOrderNodeTraversalRecursive(nextNode, traverse);
		}
		else {
			// Recursively traverse the left (previous) subtree
			inOrderNodeTraversalRecursive(nextNode->getPrev(), traverse);

			traverse.push_back(std::make_pair(nextNode->getNodeKey(), nextNode->getNodeValue()));

			// Recursively traverse the right (next) subtree
			inOrderNodeTraversalRecursive(nextNode->getNext(), traverse);
		}
	}
}

template <typename T1, typename T2>
std::vector<std::pair<T1, T2>> SubTree<T1, T2>::getNodesInOrder() {
	return inOrderNodeTraversal();
}

template <typename T1, typename T2>
std::vector<SubTree<T1, T2>*> SubTree<T1, T2>::inOrderSubtreeTraversal() {
	std::vector<SubTree<T1, T2>*> traverse;

	// Recursively begin at the root tree's subtree
	inOrderSubtreeTraversalRecursive(this, traverse);

	return traverse;
}

template <typename T1, typename T2>
void SubTree<T1, T2>::inOrderSubtreeTraversalRecursive(SubTree<T1, T2>* nextTree, std::vector<SubTree<T1, T2>*> &traverse) {

	if (nextTree != nullptr) {
		// Recursively traverse the left (previous) tree
		SubTree<T1, T2>* prevSubTree = nextTree->getPrevSubtree();

		if (prevSubTree != nullptr) {
			traverse.push_back(prevSubTree);
			
			inOrderSubtreeTraversalRecursive(prevSubTree, traverse);
		}

		// Recursively traverse the right (next) tree
		SubTree<T1, T2>* nextSubTree = nextTree->getNextSubtree();

		if (nextSubTree != nullptr) {
			traverse.push_back(nextSubTree);

			inOrderSubtreeTraversalRecursive(nextSubTree, traverse);
		}
	}
}

template <typename T1, typename T2>
std::vector<SubTree<T1, T2>*> SubTree<T1, T2>::getSubtreesInOrder() {
	return inOrderSubtreeTraversal();
}

template <typename T1, typename T2>
std::vector<SubTree<T1, T2>*> SubTree<T1, T2>::inOrderSubtreeTraversal(int level) {
	std::vector<SubTree<T1, T2>*> traverse;

	// Recursively begin at the root tree's subtree
	inOrderSubtreeTraversalRecursive(this, traverse, level);

	return traverse;
}

template <typename T1, typename T2>
void SubTree<T1, T2>::inOrderSubtreeTraversalRecursive(SubTree<T1, T2>* nextTree, std::vector<SubTree<T1, T2>*> &traverse, int level) {

	if (nextTree != nullptr) {
		// Recursively traverse the left (previous) tree
		SubTree<T1, T2>* prevSubTree = nextTree->getPrevSubtree();

		if (prevSubTree != nullptr && prevSubTree->getLevel() == level) {
			traverse.push_back(prevSubTree);

			inOrderSubtreeTraversalRecursive(prevSubTree, traverse, level);
		}

		// Recursively traverse the right (next) tree
		SubTree<T1, T2>* nextSubTree = nextTree->getNextSubtree();

		if (nextSubTree != nullptr && nextSubTree->getLevel() == level) {
			traverse.push_back(nextSubTree);

			inOrderSubtreeTraversalRecursive(nextSubTree, traverse, level);
		}
	}
}

template <typename T1, typename T2>
std::vector<SubTree<T1, T2>*> SubTree<T1, T2>::getSubtreesInOrder(int level) {
	return inOrderSubtreeTraversal(level);
}
