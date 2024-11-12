#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name;
    string phone;
    Node* next;
};

class Phonebook {
    private:
        static const int TABLE_SIZE = 10;
        Node* table[TABLE_SIZE];

    public:
        Phonebook() {
            for (int i = 0; i < TABLE_SIZE; i++) {
                table[i] = nullptr;
            }
        }

        int hashFunction(string key) {
            int hash = 0;
            for (char c : key) {
                hash = (hash + c) % TABLE_SIZE;
            }
            return hash;
        }

        void insert(string name, string phone) {
            int index = hashFunction(name);
            Node* newNode = new Node{name, phone, nullptr};
            if (table[index] == nullptr) {
                table[index] = newNode;
            } else {
                newNode->next = table[index];
                table[index] = newNode;
            }
            cout << "Contact added: " << name << " - " << phone << endl;
        }

        void find(string name) {
            int index = hashFunction(name);
            Node* temp = table[index];
            while (temp != nullptr) {
                if (temp->name == name) {
                    cout << "Found: " << name << " - " << temp->phone << endl;
                    return;
                }
                temp = temp->next;
            }
            cout << "Contact not found." << endl;
        }

        void remove(string name) {
            int index = hashFunction(name);
            Node* temp = table[index];
            Node* prev = nullptr;
            while (temp != nullptr) {
                if (temp->name == name) {
                    if (prev == nullptr) {
                        table[index] = temp->next;
                    } else {
                        prev->next = temp->next;
                    }
                    delete temp;
                    cout << "Contact deleted: " << name << endl;
                    return;
                }
                prev = temp;
                temp = temp->next;
            }
            cout << "Contact not found." << endl;
        }

        void display() {
            cout << "Phonebook contents:" << endl;
            for (int i = 0; i < TABLE_SIZE; i++) {
                Node* temp = table[i];
                while (temp != nullptr) {
                    cout << temp->name << " - " << temp->phone << endl;
                    temp = temp->next;
                }
            }
        }
};

int main() {
    Phonebook pb;
    int choice;
    string name, phone;

    do {
        cout << "\nPhonebook Menu:\n";
        cout << "1. Insert Contact\n";
        cout << "2. Find Contact\n";
        cout << "3. Delete Contact\n";
        cout << "4. Display Phonebook\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter name: ";
                cin >> name;
                cout << "Enter phone number: ";
                cin >> phone;
                pb.insert(name, phone);
                break;
            case 2:
                cout << "Enter name to search: ";
                cin >> name;
                pb.find(name);
                break;
            case 3:
                cout << "Enter name to delete: ";
                cin >> name;
                pb.remove(name);
                break;
            case 4:
                pb.display();
                break;
            case 5:
                cout << "Exiting phonebook.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
