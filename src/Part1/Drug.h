#include "Identifiable.h"
#include <string>
class Drug : public Identifiable {
public:
	Drug(long ID, std::string title, double price, int quantity) : Identifiable(ID) {
		setTitle(title);
		setPrice(price);
		setQuantity(quantity);
	}
	std::string getTitle() const {
		return this->title;
	}
	void setTitle(std::string email) {
		// TODO VALIDATION
		this->title = title;
	}
	double getPrice() const {
		return this->price;
	}
	void setPrice(double price) {
		this->price = price;
	}
	int getQuantity() const {
		return this->quantity;
	}
	void setQuantity(int quantity) {
		this->quantity = quantity;
	}
private:
	std::string title;
	double price;
	int quantity;
};