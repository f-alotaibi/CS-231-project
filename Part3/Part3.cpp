/*
    DATA STRUCTURE PROJECT: PART 3
    Made By:
    Moath Aljubair
    Ibrahem Altawalah
    Bader Alslamah
    Faleh Alotaibi
    Majed Almutari
*/
#include <iostream>
#include "Queue.cpp"
#include "Identifiable.h"
#include "Person.h"
#include "Callable.h"
#include "Drug.h"
#include "Pharamcist.h"
#include "Customer.h"
#include "Branch.h"

using namespace std;

Queue<Branch> Pharmacy;
Queue<Customer> customerList;

/*
    Test values
*/
void testValues();
void mainMenu();
int subMenu();

void branchMenu();
void drugMenu();
void pharamacistMenu();
void customerMenu();

int main() {
    testValues();
    while (true) {
        mainMenu();
    }
}

// TODO: Values
void testValues() {
    customerList.enqueue(Customer("4166", "Moath Aljubair", "055471619", "m.aljubair@email.com", 150));
    customerList.enqueue(Customer("6717", "Faleh Alotaibi", "057071972", "f.alotaibi@email.com", 90));

    Pharmacy.enqueue(Branch("002", "Zulfi", "050549412"));
    Pharmacy.enqueue(Branch("001", "Riyadh", "058696066"));

    Node<Branch>* temp = Pharmacy.getFront();
    temp->value.drugList.enqueue(Drug("80602", "Panadol extra", 8, 10));
    temp->value.drugList.enqueue(Drug("70283", "Flutab", 9.9, 9));
    temp->value.pharmacistList.enqueue(Pharmacist("5778", "Majed Almutairi", "14133", 15340, 60));

    temp = temp->next;
    temp->value.drugList.enqueue(Drug("34785", "Otrvin", 13.80, 5));
    temp->value.drugList.enqueue(Drug("38214", "Vicks throat drop menthol", 8.63, 18));
    temp->value.pharmacistList.enqueue(Pharmacist("7183", "Bader Alslamah", "61635", 13660, 49));
    temp->value.pharmacistList.enqueue(Pharmacist("2360", "Ibrahem Altowala", "82048", 12090, 44));
}

void mainMenu() {
    int choice;
    cout << "--------------------" << endl;
    cout << "Main:" << endl;
    cout << "1- Branch" << endl;
    cout << "2- Drug" << endl;
    cout << "3- Pharamacist" << endl;
    cout << "4- Customer" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice) {
    case 1:
        branchMenu();
        break;
    case 2:
        drugMenu();
        break;
    case 3:
        pharamacistMenu();
        break;
    case 4:
        customerMenu();
        break;
    }
}

int subMenu() {
    int choice;
    cout << "------------------" << endl;
    cout << "Submenu: " << endl;
    cout << "1- Display" << endl;
    cout << "2- Insert" << endl;
    cout << "3- Modify" << endl;
    cout << "4- Delete" << endl;
    cout << "5- Find" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}

Node<Branch>* findBranch() {
    string id;
    cin >> id;
    int index = Pharmacy.findNode(Branch(id, "", ""));
    if (index == -1) {
        cout << "Branch with ID (" << id << ") Not found" << endl;
        return NULL;
    }
    Node<Branch>* current = Pharmacy.findKth(index);
    return current;
}

void branchMenu() {
    int choice = subMenu();
    switch (choice) {
    case 1:
        if (Pharmacy.isEmpty()) {
            cout << "Error: There are no branches" << endl;
            return;
        }
        cout << endl << "Displaying branch data..." << endl;
        Pharmacy.displayQueue();
        break;
    case 2: {
        cout << endl << "Inserting branch data..." << endl;
        string id, address, phone;
        cout << "Enter id";
        cin >> id;
        cout << "Address: ";
        cin >> address;
        cout << "Phone: ";
        cin >> phone;
        Pharmacy.enqueue(Branch(id, address, phone));
        break;
    }
    case 3: {
        if (Pharmacy.isEmpty()) {
            cout << "Error: There are no branches" << endl;
            return;
        }
        cout << endl << "Modifying branch data..." << endl;

        string id;
        Pharmacy.displayQueue();
        cout << "Enter the ID of the branch you want to modify: ";
        Node<Branch>* current = findBranch();
        if (!current) return;
        int subChoice;
        cout << "Select what you want to edit:" << endl;
        cout << "1- Address" << endl;
        cout << "2- Phone" << endl;
        cout << "Enter your choice: ";
        cin >> subChoice;

        if (subChoice == 1) {
            string newAddress;
            cout << "Enter new address: ";
            cin >> newAddress;
            current->value.setAddress(newAddress);
        }
        else if (subChoice == 2) {
            string newPhone;
            cout << "Enter new phone: ";
            cin >> newPhone;
            current->value.setPhone(newPhone);
        }
        cout << "Branch address has been modified successfully!" << endl;
        current = NULL;
        delete current;
        break;
    }
    case 4: {
        if (Pharmacy.isEmpty()) {
            cout << "Error: There are no branches" << endl;
            return;
        }
        cout << endl << "Deleting branch data..." << endl;

        Node<Branch>* cNode = Pharmacy.getFront(), * nNode = NULL;
        while (cNode) {
            nNode = cNode->next;
            delete cNode;
            cNode = nNode;
        }
        delete cNode;
        Pharmacy.setCounter(0);

        cout << "Branch has been deleted successfully!" << endl;
        break;
    }
    case 5: {
        if (Pharmacy.isEmpty()) {
            cout << "Error: There are no branches" << endl;
            return;
        }
        cout << endl << "Finding branch data..." << endl;

        string id;
        cout << "Enter the ID of the branch you want to find: ";
        Node<Branch>* current = findBranch();
        if (!current) return;
        cout << "Found: " << current->value << endl;
        current = NULL;
        delete current;
        break;
    }
    default: {
        cout << "Invalid choice." << endl;
        break;
    }
    }
}

void customerMenu()
{
    if (Pharmacy.isEmpty())
    {
        cout << "Error: There are no branches to store customers" << endl;
        return;
    }
    int choice = subMenu();
    switch (choice)
    {
    case 1:
    {
        if (customerList.isEmpty())
        {
            cout << "Error: There are no customers" << endl;
            return;
        }
        cout << endl
            << "Displaying Customer data..." << endl;
        customerList.displayQueue();
        break;
    }
    case 2:
    {
        cout << endl
            << "Inserting Customer data..." << endl;
        string id, name, phone, email;
        int points;
        cout << "Enter the ID: ";
        cin >> id;
        cout << "Enter the Name: ";
        cin.clear();
        cin.ignore();
        getline(cin, name);
        cout << "Enter the phone: ";
        cin >> phone;
        cout << "Enter the email: ";
        cin >> email;
        customerList.enqueue(Customer(id, name, phone, email, 0));
        cout << "Successfully added the customer!" << endl;
        break;
    }
    case 3:
    {
        if (customerList.isEmpty())
        {
            cout << "Error: There are no customers" << endl;
            return;
        }
        cout << endl
            << "Modifying Customer data..." << endl;
        string id;
        customerList.displayQueue();
        cout << "Enter the ID of the customer you want to modify: ";
        cin >> id;
        int index = customerList.findNode(Customer(id, "", "", "", 0));
        if (index != -1)
        {
            Node<Customer>* currentCustomer = customerList.getFront();
            int count = 0;
            while (currentCustomer != NULL && count < index)
            {
                currentCustomer = currentCustomer->next;
                count++;
            }
            int choice;
            cout << "Please select the info you want to edit:" << endl;
            cout << "1- Name" << endl;
            cout << "2- Phone" << endl;
            cout << "3- Email" << endl;
            cout << "4- Points" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
            {
                string name;
                cout << "Enter the new name: ";
                cin.clear();
                cin.ignore();
                getline(cin, name);
                currentCustomer->value.setName(name);
                cout << "Customer name has been modified successfully!" << endl;
                break;
            }
            case 2:
            {
                string phone;
                cout << "Enter the new phone: ";
                cin >> phone;
                currentCustomer->value.setPhone(phone);
                cout << "Customer phone has been modified successfully!" << endl;
                break;
            }
            case 3:
            {
                string email;
                cout << "Enter the new email: ";
                cin >> email;
                currentCustomer->value.setEmail(email);
                cout << "Customer email has been modified successfully!" << endl;
                break;
            }
            case 4:
                int points;
                cout << "Enter the new points: ";
                cin >> points;
                currentCustomer->value.setPoints(points);
                cout << "Customer email has been modified successfully!" << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
                break;
            }
            currentCustomer = NULL;
            delete currentCustomer;
        }
        else
        {
            cout << "Error: Customer with ID " << id << " not found." << endl;
        }
        break;
    }
    case 4:
    {
        if (customerList.isEmpty())
        {
            cout << "Error: There are no customers" << endl;
            return;
        }
        cout << endl
            << "Deleting Customer data..." << endl;
        if (!customerList.isEmpty())
        {
            Node<Customer>* cNode = customerList.getFront(), * nNode = NULL;
            while (cNode) {
                nNode = cNode->next;
                delete cNode;
                cNode = nNode;
            }
            delete cNode;
            customerList.setCounter(0);
            cout << "Customer has been deleted successfully!" << endl;
        }
        break;
    }
    case 5:
    {
        if (customerList.isEmpty())
        {
            cout << "Error: There are no customers" << endl;
            return;
        }
        cout << endl
            << "Finding Customer data..." << endl;
        string id;
        cout << "Enter the ID of the customer you want to look for: ";
        cin >> id;
        int index = customerList.findNode(Customer(id, "", "", "", 0));
        if (index != -1)
        {
            Node<Customer>* currentCustomer = customerList.getFront();
            int count = 0;
            while (currentCustomer != NULL && count < index)
            {
                currentCustomer = currentCustomer->next;
                count++;
            }
            cout << "Found!" << endl << "Index: " << index << ", " << currentCustomer->value << endl;
            currentCustomer = NULL;
            delete currentCustomer;
        }
        else
        {
            cout << "Error: Customer with ID " << id << " not found." << endl;
        }
        break;
    }
    default:
        cout << "Invalid choice." << endl;
        break;
    }
}

void pharamacistMenu()
{
    if (Pharmacy.isEmpty())
    {
        cout << "Error: There are no branches" << endl;
        return;
    }

    Pharmacy.displayQueue();
    cout << "Enter the ID of the branch: ";
    Node<Branch>* current = findBranch();
    if (!current) return;
    int choice = subMenu();
    switch (choice)
    {
    case 1:
    {
        if (current->value.pharmacistList.isEmpty())
        {
            cout << "Error: There are no pharmacists" << endl;
            return;
        }
        cout << endl
            << "Displaying Pharmacists data..." << endl;
        current->value.pharmacistList.displayQueue();
        break;
    }
    case 2:
    {
        cout << endl
            << "Inserting Pharmacist data..." << endl;
        string id, name, licenseID;
        double salary, sales;
        cout << "Enter the ID: ";
        cin >> id;
        cout << "Enter the Name: ";
        cin.clear();
        cin.ignore();
        getline(cin, name);
        cout << "Enter the LicenseID: ";
        cin >> licenseID;
        cout << "Enter the salary: ";
        cin >> salary;
        current->value.pharmacistList.enqueue(Pharmacist(id, name, licenseID, salary, 0));
        cout << "Successfully added the Pharmacist!" << endl;
        break;
    }
    case 3:
    {
        if (current->value.pharmacistList.isEmpty())
        {
            cout << "Error: There are no Pharmacists" << endl;
            return;
        }
        cout << endl
            << "Modifying pharmacist data..." << endl;
        string id;
        current->value.pharmacistList.displayQueue();
        cout << "Enter the ID of the pharmacist you want to modify: ";
        cin >> id;
        int index = current->value.pharmacistList.findNode(Pharmacist(id, "", "", 0, 0));
        if (index != -1)
        {
            Node<Pharmacist>* currentPharmacist = current->value.pharmacistList.getFront();
            int count = 0;
            while (currentPharmacist != NULL && count < index)
            {
                currentPharmacist = currentPharmacist->next;
                count++;
            }
            cout << "Please select the info you want to edit:" << endl;
            cout << "1- Name" << endl;
            cout << "2- License ID" << endl;
            cout << "3- Salary" << endl;
            cout << "4- Sales" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
            {
                string name;
                cout << "Enter the new name: ";
                cin.clear();
                cin.ignore();
                getline(cin, name);
                currentPharmacist->value.setName(name);
                cout << "Customer name has been modified successfully!" << endl;
                break;
            }
            case 2:
            {
                string licenseID;
                cout << "Enter the new License ID: ";
                cin >> licenseID;
                currentPharmacist->value.setLicenseID(licenseID);
                cout << "Pharamacist License ID has been modified successfully!" << endl;
                break;
            }
            case 3:
            {
                double salary;
                cout << "Enter the new salary: ";
                cin >> salary;
                currentPharmacist->value.setSalary(salary);
                cout << "Pharamacist salary has been modified successfully!" << endl;
                break;
            }
            case 4:
                double sales;
                cout << "Enter the new sales: ";
                cin >> sales;
                currentPharmacist->value.setSales(sales);
                cout << "Pharamacist sales has been modified successfully!" << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
                break;
            }
            currentPharmacist = NULL;
            delete currentPharmacist;
        }
        else
        {
            cout << "Error: Pharamacist with ID " << id << " not found." << endl;
        }
        break;
    }
    case 4:
    {
        if (current->value.pharmacistList.isEmpty())
        {
            cout << "Error: There are no pharmacists" << endl;
            return;
        }
        cout << endl
            << "Deleting pharmacist data..." << endl;
        Node<Pharmacist>* cNode = current->value.pharmacistList.getFront(), * nNode = NULL;
        while (cNode) {
            nNode = cNode->next;
            delete cNode;
            cNode = nNode;
        }
        delete cNode;
        current->value.pharmacistList.setCounter(0);
        cout << "Pharmacist list has been deleted successfully!" << endl;
        break;
    }
    case 5:
    {
        if (current->value.pharmacistList.isEmpty())
        {
            cout << "Error: There are no pharamacists" << endl;
            return;
        }
        cout << endl
            << "Finding Pharamacist data..." << endl;
        string id;
        cout << "Enter the ID of the pharamacist you want to look for: ";
        cin >> id;
        int index = current->value.pharmacistList.findNode(Pharmacist(id, "", "", 0, 0));
        if (index != -1)
        {
            Node<Pharmacist>* currentPharmacist = current->value.pharmacistList.getFront();
            int count = 0;
            while (currentPharmacist != NULL && count < index)
            {
                currentPharmacist = currentPharmacist->next;
                count++;
            }
            cout << "Found!" << endl << "Index: " << index << ", " << currentPharmacist->value << endl;
            currentPharmacist = NULL;
            delete currentPharmacist;
        }
        else
        {
            cout << "Error: Pharamacist with ID " << id << " not found." << endl;
        }
        break;
    }
    default:
        cout << "Invalid choice." << endl;
        break;
    }
    current = NULL;
    delete current;
}

void drugMenu()
{
    if (Pharmacy.isEmpty())
    {
        cout << "Error: There are no branches" << endl;
        return;
    }

    string id;
    Pharmacy.displayQueue();
    cout << "Enter the ID of the branch: ";
    Node<Branch>* current = findBranch();
    if (!current) return;
    int choice = subMenu();
    switch (choice)
    {
    case 1:
    {
        if (current->value.drugList.isEmpty())
        {
            cout << "Error: There are no drugs" << endl;
            return;
        }
        cout << endl
            << "Displaying drug data..." << endl;
        current->value.drugList.displayQueue();
        break;
    }
    case 2:
    {
        cout << endl
            << "Inserting drug data..." << endl;
        string id, title;
        double price;
        cout << "Enter the ID: ";
        cin >> id;
        cout << "Enter the Title: ";
        cin.clear();
        cin.ignore();
        getline(cin, title);
        cout << "Enter the Price: ";
        cin >> price;
        Node<Drug>* currentDrug = current->value.drugList.getFront();
        int count = 0;
        while (currentDrug != NULL)
        {
            currentDrug = currentDrug->next;
            count++;
        }
        current->value.drugList.enqueue(Drug(id, title, price, 0));
        cout << "Successfully added the Drug!" << endl;
        currentDrug = NULL;
        delete currentDrug;
        break;
    }
    case 3:
    {
        if (current->value.drugList.isEmpty())
        {
            cout << "Error: There are no drugs" << endl;
            return;
        }
        cout << endl
            << "Modifying drug data..." << endl;
        string id;
        current->value.drugList.displayQueue();
        cout << "Enter the ID of the drug you want to modify: ";
        cin >> id;
        int index = current->value.drugList.findNode(Drug(id, "", 0.0, 0));
        if (index != -1)
        {
            Node<Drug>* currentDrug = current->value.drugList.getFront();
            int count = 0;
            while (currentDrug != NULL && count < index)
            {
                currentDrug = currentDrug->next;
                count++;
            }
            int choice;
            cout << "Please select the info you want to edit:" << endl;
            cout << "1- Title." << endl;
            cout << "2- Price." << endl;
            cout << "3- Quantity." << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
            {
                string title;
                cout << "Enter the new title: ";
                cin.clear();
                cin.ignore();
                getline(cin, title);
                currentDrug->value.setTitle(title);
                cout << "Drug title has been modified successfully!" << endl;
                break;
            }
            case 2:
            {
                double price;
                cout << "Enter the new price: ";
                cin >> price;
                currentDrug->value.setPrice(price);
                cout << "Drug price has been modified successfully!" << endl;
                break;
            }
            case 3:
            {
                int quantity;
                cout << "Enter the new quantity: ";
                cin >> quantity;
                currentDrug->value.setQuantity(quantity);
                cout << "Drug quantity has been modified successfully!" << endl;
                break;
            }
            default:
                cout << "Invalid choice." << endl;
                break;
            }
            currentDrug = NULL;
            delete currentDrug;
        }
        else
        {
            cout << "Error: Drug with ID " << id << " not found." << endl;
        }
        break;
    }
    case 4:
    {
        if (current->value.drugList.isEmpty())
        {
            cout << "Error: There are no drugs" << endl;
            return;
        }
        cout << endl
            << "Deleting drug data..." << endl;
        if (!current->value.drugList.isEmpty())
        {
            Node<Drug>* cNode = current->value.drugList.getFront(), * nNode = NULL;
            while (cNode) {
                nNode = cNode->next;
                delete cNode;
                cNode = nNode;
            }
            delete cNode;
            current->value.drugList.setCounter(0);
            cout << "Drugs has been deleted successfully!" << endl;
        }
        break;
    }
    case 5:
    {
        if (current->value.drugList.isEmpty())
        {
            cout << "Error: There are no drugs" << endl;
            return;
        }
        cout << endl
            << "Finding drug data..." << endl;
        string id;
        cout << "Enter the ID of the drug you want to look for: ";
        cin >> id;
        int index = current->value.drugList.findNode(Drug(id, "", 0.0, 0));
        if (index != -1)
        {
            Node<Drug>* currentDrug = current->value.drugList.getFront();
            int count = 0;
            while (currentDrug != NULL && count < index)
            {
                currentDrug = currentDrug->next;
                count++;
            }
            cout << "Found!" << endl << "Index: " << index << ", " << currentDrug->value;
            currentDrug = NULL;
            delete currentDrug;
        }
        else
        {
            cout << "Error: Drug with ID " << id << " not found." << endl;
        }
        break;
    }
    default:
        cout << "Invalid choice." << endl;
        break;
    }
    current = NULL;
    delete current;
}