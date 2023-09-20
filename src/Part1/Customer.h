#include "Person.h"
#include "Callable.h"
#include <string>

class Customer : public Person, public Callable {
public:
	Customer(long ID, std::string name, long phone, std::string email, int points) : Person(ID, name), Callable(phone) {
		setEmail(email);
		setPoints(points);
	}
	std::string getEmail() const {
		return this->email;
	}
	void setEmail(std::string email) {
		// TODO VALIDATION
		this->email = email;
	}
	int getPoints() const {
		return this->points;
	}
	void setPoints(int points) {
		// TODO VALIDATION ?
		this->points = points;
	}
private:
	std::string email;
	int points;
};