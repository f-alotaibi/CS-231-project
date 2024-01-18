class Branch : public Identifiable, public Callable {
public:
	Queue<Drug> drugList = Queue<Drug>();
	Queue<Pharmacist> pharmacistList = Queue<Pharmacist>();
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