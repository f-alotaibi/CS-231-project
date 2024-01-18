template <typename T> class Node {
public:
	Node<T>* next;
	T value;
};

template <typename T> class Queue {
public:
	Queue() {
		front = rear = NULL;
		counter = 0;
	}
	~Queue() {
		T value;
		while (!isEmpty()) dequeue(value);
	}
	Node<T>* getFront() { return front; }
	bool isEmpty() { return counter == 0; }
	void enqueue(T x);
	void dequeue(T& x);
	int findNode(T x);
	Node<T>* findKth(int index);
	void displayQueue();
	void setCounter(int counter) { this->counter = counter; }

protected:
	Node<T>* front;
	Node<T>* rear;
	int counter;
};