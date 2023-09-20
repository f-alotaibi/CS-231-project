#include "Identifiable.h"
#include "Callable.h"
#include "LinkedList.cpp"
#include "Drug.h"
#include "Pharamcist.h"

class Branch : public Identifiable, public Callable {
public:
	LinkedList<Drug> drugList;
	LinkedList<Pharmacist> pharmacistList;
	Branch(long ID, long address, long phone) : Identifiable(ID), Callable(phone) {
		setAddress(address);
	}
	long getAddress() const {
		return this->address;
	}
	void setAddress(long address) {
		this->address = address;
	}
private:
	//TODO char?
	long address;
};