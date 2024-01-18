#include <iostream>
#include "Queue.h"

using namespace std;

template <typename T> void Queue<T>::enqueue(T x) {
	Node<T>* newNode = new Node<T>;
	newNode->value = x;
	newNode->next = NULL;
	if (isEmpty()) {
		front = newNode;
		rear = newNode;
	}
	else {
		rear->next = newNode;
		rear = newNode;
	}
	counter++;
}

template <typename T> void Queue<T>::dequeue(T &x) {
	if (isEmpty()) {
		return;
	}
	x = front->value;
	Node<T>* nextNode = front->next;
	delete front;
	front = nextNode;
	counter--;
}

/*
	Display information about the list
*/
template <typename T> void Queue<T>::displayQueue() {
	int num = 0;
	Node<T>* cNode = front;
	while (cNode) {
		cout << cNode->value << endl;
		cNode = cNode->next;
		num++;
	}
	cout << "Number of nodes in the list " << num << endl;
}

/*
	Tries to find a node from a value
	if it isn't found, return 0.
*/
template <typename T> int Queue<T>::findNode(T x) {
	Node<T>* cNode = front;
	int cIndex = 0;
	while (cNode && cNode->value != x) {
		cNode = cNode->next;
		cIndex++;
	}
	if (cNode) return cIndex;
	return -1;
}

template <typename T> Node<T>* Queue<T>::findKth(int index) {
	Node<T>* current = front;
	int count = 0;
	while (current && count < index) {
		current = current->next;
		count++;
	}
	if (!current) return NULL;
	return current;
}