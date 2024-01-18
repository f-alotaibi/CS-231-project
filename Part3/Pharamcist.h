class Pharmacist : public Person {
public:
	Pharmacist() : Person("", "") {
		setLicenseID("");
		setSalary(0.0);
		setSales(0.0);
	}
	Pharmacist(string ID, string name, string licenseID, double salary, double sales) : Person(ID, name) {
		setLicenseID(licenseID);
		setSalary(salary);
		setSales(sales);
	}
	string getLicenseID() const {
		return this->licenseID;
	}
	double getSalary() const {
		return this->salary;
	}
	double getSales() const {
		return this->sales;
	}
	void setLicenseID(string licenseID) {
		this->licenseID = licenseID;
	}
	void setSalary(double salary) {
		this->salary = salary;
	}
	void setSales(double sales) {
		this->salary = sales;
	}
	friend ostream& operator<< (ostream& stream, Pharmacist& pharmacist) {
		stream << "ID: " << pharmacist.getID() << ", Name: " << pharmacist.getName() << ", License ID: " << pharmacist.getLicenseID() << ", Salary: "
			<< pharmacist.getSalary() << ", Sales: " << pharmacist.getSalary();
		return stream;
	}
private:
	string licenseID;
	double salary;
	double sales;
};