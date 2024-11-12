#include <iostream>
using namespace std;

struct PizzaData {
    string name;
    int price;
};

class PizzaShop {
private:
    int maxOrders;
    int front;
    int rear;
    int orderID;

    struct Order {
        int orderNumber;
        PizzaData pizza;
    } orders[50];

    PizzaData menu[10] = {
        {"Margherita", 250},
        {"Farmhouse", 350},
        {"Peppy Paneer", 400},
        {"Mexican Green Wave", 380},
        {"Deluxe Veggie", 370},
        {"Chicken Dominator", 450},
        {"Pepper Barbecue", 430},
        {"Cheese n Corn", 300},
        {"Veg Extravaganza", 420},
        {"Paneer Makhani", 390}
    };

public:
    PizzaShop(int maxOrdersAllowed) {
        maxOrders = maxOrdersAllowed;
        front = 0;
        rear = -1;
        orderID = 1;
    }

    bool isFull() {
        return rear == maxOrders - 1;
    }

    bool isEmpty() {
        return front > rear;
    }

    void displayMenu() {
        cout << "\n--- Pizza Menu ---\n";
        for (int i = 0; i < 10; i++) {
            cout << i + 1 << ". " << menu[i].name << " - Rs " << menu[i].price << "\n";
        }
    }

    void placeOrder(int pizzaChoice) {
        if (isFull()) {
            cout << "\nSorry, we can't take more orders right now.\n";
            return;
        }
        if (pizzaChoice < 1 || pizzaChoice > 10) {
            cout << "Invalid choice! Please pick a pizza from the menu.\n";
            return;
        }

        rear++;
        orders[rear].orderNumber = orderID++;
        orders[rear].pizza = menu[pizzaChoice - 1];

        cout << "\nOrder added successfully!\n";
        displayBill(orders[rear]);
    }

    void serveOrder() {
        if (isEmpty()) {
            cout << "\nNo orders to serve right now.\n";
            return;
        }

        cout << "\nServing Order No. " << orders[front].orderNumber << ": " 
             << orders[front].pizza.name << " - Rs " << orders[front].pizza.price << "\n";
        
        front++;
    }

    void displayBill(Order order) {
        cout << "\n--- Your Bill ---\n";
        cout << "Order Number: " << order.orderNumber << "\n";
        cout << "Pizza: " << order.pizza.name << "\n";
        cout << "Total Price: Rs " << order.pizza.price << "\n";
        cout << "-----------------\n";
    }

    void displayOrders() {
        if (isEmpty()) {
            cout << "\nNo orders in the queue.\n";
            return;
        }
        cout << "\nPending Orders:\n";
        for (int i = front; i <= rear; i++) {
            cout << "Order No. " << orders[i].orderNumber << ": " 
                 << orders[i].pizza.name << " - Rs " << orders[i].pizza.price << "\n";
        }
    }
};

int main() {
    int maxOrdersAllowed;
    cout << "Enter the maximum number of orders the pizza shop can take: ";
    cin >> maxOrdersAllowed;

    PizzaShop myPizzaShop(maxOrdersAllowed);

    int userChoice;
    while (true) {
        cout << "\n--- Welcome to Pizza Shop ---\n";
        cout << "1. Show Menu\n";
        cout << "2. Place Order\n";
        cout << "3. Serve Order\n";
        cout << "4. Show All Orders\n";
        cout << "5. Exit\n";
        cout << "Choose an option: ";
        cin >> userChoice;

        switch (userChoice) {
            case 1:
                myPizzaShop.displayMenu();
                break;
            case 2: {
                myPizzaShop.displayMenu();
                cout << "\nPick the pizza number you want to order: ";
                int pizzaChoice;
                cin >> pizzaChoice;
                myPizzaShop.placeOrder(pizzaChoice);
                break;
            }
            case 3:
                myPizzaShop.serveOrder();
                break;
            case 4:
                myPizzaShop.displayOrders();
                break;
            case 5:
                cout << "Thanks for visiting!\n";
                return 0;
            default:
                cout << "Invalid option! Try again.\n";
        }
    }
}
