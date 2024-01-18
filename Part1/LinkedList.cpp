#include <iostream>
#include "LinkedList.h"

using namespace std;

/*
	Deletes every node that it has.
*/
template <typename T> LinkedList<T>::~LinkedList() {
	length = 0;
	Node<T>* currNode = head, * nextNode = NULL;
	while (currNode != NULL)
	{
		nextNode = currNode->next;
		// destroy the current node
		delete currNode;
		currNode = nextNode;
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
	length++;

	return newNode;
}

/*
	Tries to find a node from a value
	if it isn't found, return 0.
*/
template <typename T> int LinkedList<T>::findNode(T x) {
	Node<T> *cNode = head;
	int cIndex = 0;
	while (cNode && cNode->value != x) {
		cNode = cNode->next;
		cIndex++;
	}
	if (cNode) return cIndex;
	return -1;
}

/*
	Deletes a node from a specified value
	Returns its index if it is found, otherwise 0 will be returned
*/
template <typename T> int LinkedList<T>::deleteNode(T x) {
	Node<T>* pNode = NULL;
	Node<T>* cNode = head;
	int cIndex = 0;
	while (cNode && cNode->value != x) {
		pNode = cNode;
		cNode = cNode->next;
		cIndex++;
	}
	if (!cNode) return -1;
	Node<T>* nNode = (pNode ? pNode : head);
	nNode->next = cNode->next;
	delete cNode;
	length--;
	return cIndex;
}

template <typename T> Node<T>* LinkedList<T>::findKth(int index) {
	Node<T>* current = head;
	int count = 0;
	while (current && count < index) {
		current = current->next;
		count++;
	}
	if (!current) return NULL;
	return current;
}


/*
	Display information about the list
*/
template <typename T> void LinkedList<T>::displayList() {
	int num = 0;
	Node<T>* cNode = head;
	while (cNode && num < length) {
		cout << cNode->value << endl;
		cNode = cNode->next;
		num++;
	}
	cout << "Number of nodes in the list " << num << endl;
}

/*
	ADD TO LAST
*/

template <typename T> Node<T>* LinkedList<T>::addNode(T x) {
	return insertNode(0, x);
}