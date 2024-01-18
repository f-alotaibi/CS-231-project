#include <string>
class Drug : public Identifiable {
public:
	Drug() : Identifiable("") {
		setTitle("");
		setPrice(0.0);
		setQuantity(0);
	}
	Drug(string ID, string title, double price, int quantity) : Identifiable(ID) {
		setTitle(title);
		setPrice(price);
		setQuantity(quantity);
	}
	void setTitle(string title) {
		this->title = title;
	}
	void setPrice(double price) {
		this->price = price;
	}
	void setQuantity(int quantity) {
		this->quantity = quantity;
	}
	string getTitle() const {
		return this->title;
	}
	double getPrice() const {
		return this->price;
	}
	int getQuantity() const {
		return this->quantity;
	}
	friend ostream& operator<< (ostream& stream, Drug& drug) {
		stream << "ID: " << drug.getID() << ", Title: " << drug.getTitle() << ", Price: " << drug.getPrice() << ", Quantity: " << drug.getQuantity();
		return stream;
	}

private:
	std::string title;
	double price;
	int quantity;
};