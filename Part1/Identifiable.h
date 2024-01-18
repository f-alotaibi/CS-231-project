#include <string>
using namespace std;
class Identifiable {
private:
	string ID;
public:
	Identifiable(string ID) {
		setID(ID);
	}
	string getID() const {
		return this->ID;
	}
	void setID(string ID) {
		this->ID = ID;
	}
	bool operator!= (Identifiable identifiable) {
		return (ID != identifiable.ID);
	}
};