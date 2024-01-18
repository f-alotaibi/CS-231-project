#include <iostream>
#include "Stack.h"

using namespace std;

/*
	Deletes every node that it has.
*/
template <typename T> Stack<T>::~Stack() {
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
template <typename T> void Stack<T>::push(T x) {
	Node<T>* newNode = new Node<T>;
	newNode->value = x;
	newNode->next = head;
	head = newNode;
	length++;
}

/*
	Tries to find a node from a value
	if it isn't found, return 0.
*/
template <typename T> int Stack<T>::findNode(T x) {
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
template <typename T> T Stack<T>::top() {
	if (head == NULL) {
		return NULL;
	}
	Node<T>* cNode = head;
	T value = cNode->value;
	head = head->next;
	delete cNode;
	length--;
	return value;
}

template <typename T> Node<T>* Stack<T>::findKth(int index) {
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
template <typename T> void Stack<T>::displayStack() {
	int num = 0;
	Node<T>* cNode = head;
	while (cNode && num > length) {
		cout << cNode->value << endl;
		cNode = cNode->next;
		num++;
	}
	cout << "Number of nodes in the list " << num << endl;
}