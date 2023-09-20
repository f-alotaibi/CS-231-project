template <typename T> class Node {
public:
	Node<T>* next;
	T value;
};

template <typename T> class LinkedList {
	public: 
		LinkedList() {
			head = NULL;
		}
		~LinkedList();

		bool isEmpty() {return head == NULL;}
		Node<T>* insertNode(int index, T x);
		int findNode(T x);
		int deleteNode(T x);
		
		void displayList();

	private:
		Node<T>* head;
};