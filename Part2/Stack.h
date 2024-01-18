template <typename T> class Node {
public:
	Node<T>* next;
	T value;
};

template <typename T> class Stack {
	public: 
		Stack() {
			head = NULL;
			length = 0;
		}
		~Stack();

		bool isEmpty() {return length == 0;}
		T top();
		void push(T x);
		int findNode(T x);
		Node<T>* findKth(int index);
		Node<T>* getHead() { return head; }
		void displayStack();
		void setLength(int length) { this->length = length; }

	protected:
		Node<T>* head;
		int length;
};