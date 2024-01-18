#include <string>
using namespace std;
class Callable {
public:
	Callable(string phone) {
		setPhone(phone);
	}
	string getPhone() const {
		return this->phone;
	}
	void setPhone(string phone) {
		this->phone = phone;
	}
private:
	string phone = "";
};