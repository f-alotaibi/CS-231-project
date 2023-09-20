#include <iostream>
#include "LinkedList.h"

using namespace std;

/*
	Deletes every node that it has.
*/
template <typename T> LinkedList<T>::~LinkedList() {
	Node<T>* cNode = head, *nNode = NULL;
	while (cNode) {
		nNode = cNode->next;
		delete cNode;
		cNode = nNode;
	}
}

/*
	Insert a node into the list
	If the index less than 0 or too far from the list, it will return null
*/
template <typename T> Node<T>* LinkedList<T>::insertNode(int index, T x) {
	if (index < 0) return NULL;
	Node<T>* cNode = head;
	int cIndex = 1;
	while (cNode && index > cIndex) {
		cNode = cNode->next;
		cIndex++;
	}
	if (index > 0 && !cNode) return NULL;

	Node<T>* newNode = new Node<T>;
	newNode->value = x;

	if (index == 0) {
		newNode->next = head;
		head = newNode;
	}
	else {
		newNode->next = cNode->next;
		cNode->next = newNode;
	}

	return newNode;
}

/*
	Tries to find a node from a value
	if it isn't found, return 0.
*/
template <typename T> int LinkedList<T>::findNode(T x) {
	Node<T> *cNode = head;
	int cIndex = 1;
	while (cNode && cNode->value != x) {
		cNode = cNode->next;
		cIndex++;
	}
	if (cNode) return cIndex;
	return 0;
}

/*
	Deletes a node from a specified value
	Returns its index if it is found, otherwise 0 will be returned
*/
template <typename T> int LinkedList<T>::deleteNode(T x) {
	Node<T>* pNode = NULL;
	Node<T>* cNode = head;
	int cIndex = 1;
	while (cNode && cNode->value != x) {
		pNode = cNode;
		cNode = cNode->next;
		cIndex++;
	}
	if (!cNode) return 0;
	Node<T>* nNode = (pNode ? pNode : head);
	nNode->next = cNode->next;
	delete cNode;

	return cIndex;
}


/*
	Display information about the list
*/
template <typename T> void LinkedList<T>::displayList() {
	int num = 0;
	Node<T>* cNode = head;
	while (cNode) {
		cout << cNode->value << endl;
		cNode = cNode->next;
		num++;
	}
	cout << "Number of nodes in the list " << num << endl;
}