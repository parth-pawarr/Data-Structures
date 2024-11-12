#include <iostream>
#include <iomanip>
using namespace std;

struct Appointment {
    string name;
    string timeSlot;
    Appointment* next;
};

class AppointmentManager {
    private:
        Appointment* head;

    public:
        AppointmentManager() : head(nullptr) {}
        void displayFreeSlots();
        void bookAppointment();
        void cancelAppointment();
        void sortAppointments();
        void sortAppointmentsPointer();
        void displayAppointments();
        bool isTimeSlotFree(string timeSlot);
};

void AppointmentManager::displayFreeSlots() {
    cout << "\n-----------------------------------\n";
    cout << "         Free Time Slots          \n";
    cout << "-----------------------------------\n";
    for (int i = 0; i < 6; i++) {
        string timeSlot = to_string(10 + (i * 10)) + ":00 to " + to_string(10 + (i * 10) + 10) + ":00";
        if (isTimeSlotFree(timeSlot)) {
            cout << "Slot " << i + 1 << ": " << timeSlot << endl;
        }
    }
    cout << "-----------------------------------\n";
}

bool AppointmentManager::isTimeSlotFree(string timeSlot) {
    Appointment* current = head;
    while (current != nullptr) {
        if (current->timeSlot == timeSlot) {
            return false;
        }
        current = current->next;
    }
    return true;
}

void AppointmentManager::bookAppointment() {
    string name;
    int slotNumber;
    cout << "\nEnter your name for the appointment: ";
    cin >> name;

    cout << "Choose a time slot:\n";
    displayFreeSlots();

    cout << "Enter the slot number (1-6): ";
    cin >> slotNumber;

    if (slotNumber < 1 || slotNumber > 6) {
        cout << "\nInvalid slot number. Please choose a valid slot.\n";
        return;
    }

    string timeSlot = to_string(10 + ((slotNumber - 1) * 10)) + ":00 to " + to_string(10 + ((slotNumber - 1) * 10) + 10) + ":00";

    if (isTimeSlotFree(timeSlot)) {
        Appointment* newAppointment = new Appointment{name, timeSlot, head};
        head = newAppointment;
        cout << "\nAppointment booked successfully for " << name << " at " << timeSlot << ".\n";
    } else {
        cout << "\nTime slot is already booked. Please choose another slot.\n";
    }
}

void AppointmentManager::cancelAppointment() {
    int slotNumber;
    cout << "\nEnter the slot number to cancel (1-6): ";
    cin >> slotNumber;

    if (slotNumber < 1 || slotNumber > 6) {
        cout << "\nInvalid slot number. Please choose a valid slot.\n";
        return;
    }

    string timeSlot = to_string(10 + ((slotNumber - 1) * 10)) + ":00 to " + to_string(10 + ((slotNumber - 1) * 10) + 10) + ":00";

    Appointment* current = head;
    Appointment* previous = nullptr;

    while (current != nullptr && current->timeSlot != timeSlot) {
        previous = current;
        current = current->next;
    }

    if (current == nullptr) {
        cout << "\nNo appointment found for the specified time slot.\n";
        return;
    }

    if (previous == nullptr) {
        head = current->next;
    } else {
        previous->next = current->next;
    }

    delete current;
    cout << "\nAppointment canceled successfully for slot: " << timeSlot << ".\n";
}

void AppointmentManager::sortAppointments() {
    if (head == nullptr) return;

    for (Appointment* i = head; i->next != nullptr; i = i->next) {
        for (Appointment* j = head; j->next != nullptr; j = j->next) {
            if (j->timeSlot > j->next->timeSlot) {
                string tempName = j->name;
                string tempTimeSlot = j->timeSlot;
                j->name = j->next->name;
                j->timeSlot = j->next->timeSlot;
                j->next->name = tempName;
                j->next->timeSlot = tempTimeSlot;
            }
        }
    }
}

void AppointmentManager::sortAppointmentsPointer() {
    if (head == nullptr) return;

    Appointment* sorted = nullptr;

    while (head != nullptr) {
        Appointment* current = head;
        head = head->next;

        if (sorted == nullptr || sorted->timeSlot > current->timeSlot) {
            current->next = sorted;
            sorted = current;
        } else {
            Appointment* temp = sorted;
            while (temp->next != nullptr && temp->next->timeSlot < current->timeSlot) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
    }

    head = sorted;
}

void AppointmentManager::displayAppointments() {
    if (head == nullptr) {
        cout << "\nNo appointments scheduled.\n";
        return;
    }

    cout << "\n-----------------------------------\n";
    cout << "        Scheduled Appointments     \n";
    cout << "-----------------------------------\n";
    Appointment* current = head;
    while (current != nullptr) {
        cout << "Name: " << current->name << ", Time Slot: " << current->timeSlot << endl;
        current = current->next;
    }
    cout << "-----------------------------------\n";
}

int main() {
    AppointmentManager manager;
    int choice;

    do {
        cout << "\n******** Appointment Management System ********\n";
        cout << "1. Display Free Slots\n";
        cout << "2. Book Appointment\n";
        cout << "3. Cancel Appointment\n";
        cout << "4. Sort Appointments (Bubble Sort)\n";
        cout << "5. Sort Appointments (Pointer Manipulation)\n";
        cout << "6. Display Appointments\n";
        cout << "7. Exit\n";
        cout << "***********************************************\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                manager.displayFreeSlots();
                break;
            case 2:
                manager.bookAppointment();
                break;
            case 3:
                manager.cancelAppointment();
                break;
            case 4:
                manager.sortAppointments();
                cout << "\nAppointments sorted successfully.\n";
                break;
            case 5:
                manager.sortAppointmentsPointer();
                cout << "\nAppointments sorted successfully using pointer manipulation.\n";
                break;
            case 6:
                manager.displayAppointments();
                break;
            case 7:
                cout << "\nExiting program.\n";
                break;
            default:
                cout << "\nInvalid choice, please try again.\n";
        }
    } while (choice != 7);

    return 0;
}
