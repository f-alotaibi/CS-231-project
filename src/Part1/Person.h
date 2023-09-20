#include "Identifiable.h"
#include <string>

class Person : public Identifiable {
public:
	Person(long ID, std::string name) : Identifiable(ID) {
		setName(name);
	}
	std::string getName() const {
		return this->name;
	}
	void setName(std::string name) {
		// TODO VALIDATION
		this->name = name;
	}
private:
	std::string name;
};