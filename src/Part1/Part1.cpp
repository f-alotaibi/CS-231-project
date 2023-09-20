/*
	DATA STRUCTURE PROJECT: PART 1
*/

#include "LinkedList.cpp"
#include "Customer.h"

using namespace std;
int main()
{
	Customer c(43, "Hello", 500, "EMAIL@EMAIL.gov", 21);
	cout << c.getID() << " " << c.getName() << " " << c.getPhone() << endl;
	cout << c.getEmail() << " " << c.getPoints() << endl;
	//LinkedList<double> doubleList;
	//doubleList.displayList();
	LinkedList<double> list;
	list.insertNode(0, 7.0);	// successful
	list.insertNode(1, 5.0);	// successful
	list.insertNode(-1, 5.0);	// unsuccessful
	list.insertNode(0, 6.0);	// successful
	list.insertNode(8, 4.0);	// unsuccessful
	// print all the elements
	list.displayList();
	if (list.findNode(5.0) > 0)	cout << "5.0 found" << endl;
	else				cout << "5.0 not found" << endl;
	if (list.findNode(4.5) > 0) cout << "4.5 found" << endl;
	else				cout << "4.5 not found" << endl;
	list.deleteNode(7.0);
	list.displayList();
}