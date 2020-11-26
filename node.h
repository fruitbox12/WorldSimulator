#pragma once

template <typename T1, typename T2>

class Node {
	private:
		T1				key;
		T2				value;
		bool			empty;
		Node<T1,T2>*	prev;
		Node<T1,T2>*	next;

	public:
		// Default constructor used by the Tree constructor
		Node();

		Node(T1 key, T2 value);
		~Node();

		// Getters
		T1				getNodeKey();
		T2				getNodeValue();
		bool			isEmpty() const;
		Node<T1,T2>*	getPrev();
		Node<T1,T2>*	getNext();

		// Setters
		void setKey(T1 key);
		void setValue(T2 value);
		void setPrev(Node<T1,T2>* prev);
		void setNext(Node<T1,T2>* next);
};
