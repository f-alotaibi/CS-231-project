#include <string>

class Person : public Identifiable {
public:
	Person(string ID, string name) : Identifiable(ID) {
		setName(name);
	}
	string getName() const {
		return this->name;
	}
	void setName(string name) {
		this->name = name;
	}
private:
	string name;
};