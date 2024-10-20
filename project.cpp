#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Contact {
public:
    string name;
    string phoneNumber;

    Contact(const string& n, const string& p) : name(n), phoneNumber(p) {}

    virtual void display() const {
        cout << "Name: " << name << "\nPhone Number: " << phoneNumber << endl;
    }

    virtual ~Contact() {}
};

class CollegeContact : public Contact {
public:
    string collegeName;

    CollegeContact(const string& n, const string& p, const string& college) 
        : Contact(n, p), collegeName(college) {}

    void display() const override {
        Contact::display();
        cout << "College Name: " << collegeName << endl;
    }
};

class Phonebook {
private:
    vector<Contact*> contacts;

public:
    ~Phonebook() {
        for (Contact* contact : contacts) {
            delete contact;
        }
    }

    void addContact(const string& name, const string& phoneNumber, const string& type) {
        if (type == "College") {
            string collegeName;
            cout << "Enter college name: ";
            getline(cin, collegeName);
            contacts.push_back(new CollegeContact(name, phoneNumber, collegeName));
        } else {
            contacts.push_back(new Contact(name, phoneNumber));
        }
        cout << "Phone details successfully stored!\n";
    }

    void searchContact(const string& searchTerm) {
        for (const auto& contact : contacts) {
            if (contact->name == searchTerm || contact->phoneNumber == searchTerm) {
                contact->display();
                return;
            }
        }
        cout << "Contact not found.\n";
    }

    void displayContacts() const {
        if (contacts.empty()) {
            cout << "No contacts available.\n";
            return;
        }

        for (const auto& contact : contacts) {
            contact->display();
            cout << "-----------------\n";
        }
    }

    void deleteContact(const string& phoneNumber) {
        for (auto it = contacts.begin(); it != contacts.end(); ++it) {
            if ((*it)->phoneNumber == phoneNumber) {
                delete *it;
                contacts.erase(it);
                cout << "Record deleted!\n";
                return;
            }
        }
        cout << "Record doesn’t exist! Try again...\n";
    }
};

int main() {
    Phonebook phonebook;
    int choice;

    do {
        cout << "\nPhonebook Management System\n";
        cout << "1. Add Contact\n";
        cout << "2. Search Contact\n";
        cout << "3. Display Contacts\n";
        cout << "4. Delete Contact\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                string name, phoneNumber, Cname;
                cout << "Enter name: ";
                getline(cin, name);
                cout << "Enter phone number: ";
                getline(cin, phoneNumber);
                cout << "Enter Collage Name: ";
                getline(cin, Cname);
                phonebook.addContact(name, phoneNumber, Cname);
                break;
            }
            case 2: {
                string searchTerm;
                cout << "Enter name or phone number to search: ";
                getline(cin, searchTerm);
                phonebook.searchContact(searchTerm);
                break;
            }
            case 3: {
                phonebook.displayContacts();
                break;
            }
            case 4: {
                string phoneNumber;
                cout << "Enter phone number to delete: ";
                getline(cin, phoneNumber);
                phonebook.deleteContact(phoneNumber);
                break;
            }
            case 5: {
                cout << "Exiting...\n";
                break;
            }
            default: {
                cout << "Invalid choice. Try again.\n";
            }
        }
    } while (choice != 5);

    return 0;
}
