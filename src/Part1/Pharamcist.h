#include "Person.h"

class Pharmacist : public Person {
public:
	Pharmacist(long ID, std::string name, long licenseID, double salary, double sales) : Person(ID, name) {
		setLicenseID(licenseID);
		setSalary(salary);
		setSales(sales);
	}
	long getLicenseID() const {
		return this->licenseID;
	}
	void setLicenseID(long licenseID) {
		this->licenseID = licenseID;
	}
	double getSalary() const {
		return this->salary;
	}
	void setSalary(double salary) {
		this->salary = salary;
	}
	double getSales() const {
		return this->sales;
	}
	void setSales(double sales) {
		this->salary = sales;
	}
private:
	// TODO: Char?
	long licenseID;
	double salary;
	double sales;
};