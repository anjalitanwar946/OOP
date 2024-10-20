#include <iostream>

using namespace std;

class Details {
public:
    virtual void inputDetails() = 0;
    virtual void displayDetails() const = 0;
};

class Patient : public Details {
private:
    char patientName[50];
    char medicalHistory[100];
    char covidTestResult[10];

public:
    void inputDetails() override {
        cout << "Enter Patient Name: ";
        cin.getline(patientName, 50);
        cout << "Enter Medical History: ";
        cin.getline(medicalHistory, 100);
        cout << "Enter COVID Test Result (positive/negative): ";
        cin.getline(covidTestResult, 10);
    }

    void displayDetails() const override {
        cout << "\n** Patient Information **n";
        cout << "Name: " << patientName << endl;
        cout << "Medical History: " << medicalHistory << endl;
        cout << "COVID Test Result: " << covidTestResult << endl;
        cout << "--------------------------" ;

    }
};

class InventoryItem : public Details {
private:
    char itemName[50];
    int itemQuantity;

public:
    void inputDetails() override {
        cout << "\n Enter Inventory Item Name: ";
        cin.getline(itemName, 50);
        cout << "Enter Item Quantity: ";
        cin >> itemQuantity;
        cin.ignore(); // Clear input buffer
    }

    void displayDetails() const override {
        cout << "\n** Inventory Information **\n";
        cout << "Item Name: " << itemName << endl;
        cout << "Quantity: " << itemQuantity << endl;
        cout << "--------------------------" ;

    }
};

class Service : public Details {
private:
    char serviceName[50];
    float serviceCost;

public:
    void inputDetails() override {
        cout << "\n Enter Service Name: ";
        cin.getline(serviceName, 50);
        cout << "Enter Service Cost: ";
        cin >> serviceCost;
        cin.ignore(); // Clear input buffer
    }

    void displayDetails() const override {
        cout << "\n** Billing Information **\n";
        cout << "Service: " << serviceName << endl;
        cout << "Cost: " << serviceCost << endl;
        cout << "--------------------------" ;

    }
};

class InsurancePolicy : public Details {
private:
    char policyNumber[50];
    char insuranceProvider[50];
    float coverageAmount;

public:
    void inputDetails() override {
        cout << "\n Enter Insurance Policy Number: ";
        cin.getline(policyNumber, 50);
        cout << "Enter Insurance Provider: ";
        cin.getline(insuranceProvider, 50);
        cout << "Enter Coverage Amount: ";
        cin >> coverageAmount;
        cin.ignore(); // Clear input buffer
    }

    void displayDetails() const override {
        cout << "\n** Insurance Policy Information **\n";
        cout << "Policy Number: " << policyNumber << endl;
        cout << "Insurance Provider: " << insuranceProvider << endl;
        cout << "Coverage Amount: " << coverageAmount << endl;
        cout << "--------------------------" << endl;
    }
};

int main() {
    Details *details;

    // Input and display patient details
    details = new Patient();
    details->inputDetails();
    details->displayDetails();
    delete details;

    // Input and display inventory details
    details = new InventoryItem();
    details->inputDetails();
    details->displayDetails();
    delete details;

    // Input and display service details
    details = new Service();
    details->inputDetails();
    details->displayDetails();
    delete details;

    details = new  InsurancePolicy();
    details->inputDetails();
    details->displayDetails();
    delete details;


    return 0;
}

