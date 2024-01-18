template <typename T> class Node {
public:
	Node<T>* next;
	T value;
};

template <typename T> class LinkedList {
	public: 
		LinkedList() {
			head = NULL;
			length = 0;
		}
		~LinkedList();

		bool isEmpty() {return length == 0;}
		Node<T>* insertNode(int index, T x);
		int findNode(T x);
		int deleteNode(T x);
		Node<T>* findKth(int index);
		Node<T>* getHead() { return head; }
		void displayList();
		Node<T>* addNode(T x);
		void setLength(int length) { this->length = length; }

	protected:
		Node<T>* head;
		int length;
};