class Callable {
public:
	Callable(long phone) {
		setPhone(phone);
	}
	long getPhone() const {
		return this->phone;
	}
	void setPhone(long phone) {
		//TODO VALIDATION
		this->phone = phone;
	}
private:
	// TODO: Convert it to char.
	long phone;
};