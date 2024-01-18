class Branch : public Identifiable, public Callable {
public:
	Stack<Drug> drugList = Stack<Drug>();
	Stack<Pharmacist> pharmacistList = Stack<Pharmacist>();
	Branch() : Identifiable(""), Callable("") {
		setAddress("");
	}
	Branch(string ID, string address, string phone) : Identifiable(ID), Callable(phone) {
		setAddress(address);
	}
	string getAddress() const {
		return this->address;
	}
	void setAddress(string address) {
		this->address = address;
	}
	friend ostream& operator<< (ostream& stream, Branch& branch) {
		stream << "ID: " << branch.getID() << ", Address: " << branch.getAddress() << ", Phone: " << branch.getPhone();
		return stream;
	}
private:
	string address;
};