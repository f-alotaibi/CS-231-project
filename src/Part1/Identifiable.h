class Identifiable {
private:
	long ID;
public:
	Identifiable(long ID) {
		setID(ID);
	}
	long getID() const {
		return this->ID;
	}
	void setID(long ID) {
		// TODO VALIDATION
		this->ID = ID;
	}
};