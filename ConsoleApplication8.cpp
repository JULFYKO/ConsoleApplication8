#include <iostream>
#include <string>
#include <vector>

class Contact {
private:
    std::string fullName;
    std::string homePhone;
    std::string workPhone;
    std::string mobilePhone;
    std::string additionalInfo;

public:
    Contact(const std::string& name, const std::string& home, const std::string& work, const std::string& mobile, const std::string& info)
        : fullName(name), homePhone(home), workPhone(work), mobilePhone(mobile), additionalInfo(info) {}

    void display() const {
        std::cout << "Full Name: " << fullName << "\nHome Phone: " << homePhone
            << "\nWork Phone: " << workPhone
            << "\nMobile Phone: " << mobilePhone
            << "\nAdditional Info: " << additionalInfo << "\n\n";
    }

    const std::string& getFullName() const {
        return fullName;
    }
};

class PhoneBook {
private:
    std::vector<Contact> contacts;

public:
    void addContact(const Contact& contact) {
        contacts.push_back(contact);
    }

    void deleteContact(const std::string& name) {
        for (auto it = contacts.begin(); it != contacts.end(); ++it) {
            if (it->getFullName() == name) {
                contacts.erase(it);
                std::cout << "Contact deleted.\n";
                return;
            }
        }
        std::cout << "Contact not found.\n";
    }

    void searchContact(const std::string& name) const {
        for (const auto& contact : contacts) {
            if (contact.getFullName() == name) {
                contact.display();
                return;
            }
        }
        std::cout << "Contact not found.\n";
    }

    void displayAllContacts() const {
        for (const auto& contact : contacts) {
            contact.display();
        }
    }
};

int main() {
    PhoneBook phoneBook;
    phoneBook.addContact(Contact("Bandera", "12341234", "12341234", "12341234", "Father"));
    phoneBook.addContact(Contact("Ukraine", "12341234", "12341234", "12341234", "Mother"));

    phoneBook.searchContact("Bandera");
    phoneBook.displayAllContacts();
    phoneBook.deleteContact("Ukraine");
    phoneBook.displayAllContacts();

    return 0;
}
