#include <string>

class Customer : public Person, public Callable {
public:
	Customer() : Person("", ""), Callable("") {
		setEmail("");
		setPoints(0);
	}
	Customer(string ID, string name, string phone, string email, int points) : Person(ID, name), Callable(phone) {
		setEmail(email);
		setPoints(points);
	}
	string getEmail() const {
		return this->email;
	}
	void setEmail(string email) {
		this->email = email;
	}
	int getPoints() const {
		return this->points;
	}
	void setPoints(int points) {
		this->points = points;
	}
	friend ostream& operator<< (ostream& stream, Customer& customer) {
		stream << "ID: " << customer.getID() << ", Name: " << customer.getName() << ", Phone: " << customer.getPhone() << ", Email: " 
			<< customer.getEmail() << ", Points: " << customer.getPoints();
		return stream;
	}
private:
	string email;
	int points;
};