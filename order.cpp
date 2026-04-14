#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// pizza types
const int DEEP_DISH = 0;
const int HAND_TOSSED = 1;
const int PAN = 2;

// pizza sizes
const int SMALL = 0;
const int MEDIUM = 1;
const int LARGE = 2;

class Pizza {
private:
    int type;
    int size;
    int pepperoniToppings;
    int cheeseToppings;

public:
    // constructors
    Pizza() { // default constructor
        type = HAND_TOSSED;
        size = MEDIUM;
        pepperoniToppings = 0;
        cheeseToppings = 0;
    }

    Pizza(int t, int s, int p, int c) { // constructor with parameters
        type = t;
        size = s;
        pepperoniToppings = p;
        cheeseToppings = c;
    }

    // getter functions
    int getType() const { 
        return type; 
    }

    int getSize() const { 
        return size; 
    }
    
    int getPepperoniToppings() const { 
        return pepperoniToppings; 
    }
    
    int getCheeseToppings() const { 
        return cheeseToppings; 
    }

    // setter functions
    void setType(int t) { 
        type = t; 
    }
    
    void setSize(int s) { 
        size = s; 
    }
    void setPepperoniToppings(int p) { 
        pepperoniToppings = p; 
    }
    void setCheeseToppings(int c) { 
        cheeseToppings = c; 
    }

    // output
    void outputDescription() const {
        string sizeStr;
        string typeStr;

        switch (size) {
            case SMALL: 
                sizeStr = "Small"; 
                break;
            case MEDIUM: 
                sizeStr = "Medium"; 
                break;
            case LARGE: 
                sizeStr = "Large"; 
                break;
            default: 
                sizeStr = "Unknown Size"; 
                break;
        }

        switch (type) {
            case DEEP_DISH: 
                typeStr = "Deep Dish"; 
                break;
            case HAND_TOSSED: 
                typeStr = "Hand Tossed"; 
                break;
            case PAN: 
                typeStr = "Pan"; 
                break;
            default: 
                typeStr = "Unknown Type"; 
                break;
        }

        cout << sizeStr << " " << typeStr << " Pizza with " 
             << pepperoniToppings << " pepperoni topping(s) and " 
             << cheeseToppings << " cheese topping(s)." << endl;
    }

    // compute price function
    double computePrice() const {
        double basePrice = 0.0;
        
        switch (size) {
            case SMALL:     
                basePrice = 10.0; 
                break;
            case MEDIUM: 
                basePrice = 14.0; 
                break;
            case LARGE: 
                basePrice = 17.0; 
                break;
            default: 
                basePrice = 0.0; 
                break; 
        }

        double toppingPrice = 2.0 * (pepperoniToppings + cheeseToppings);
        return basePrice + toppingPrice;
    }
};

class Order {
private:
    vector<Pizza> pizzas; // vector to store multiple pizzas

public:
    // add a pizza to the order
    void addPizza(int type, int size, int pepperoni, int cheese) {
        Pizza newPizza(type, size, pepperoni, cheese);
        pizzas.push_back(newPizza);
    }

    // output order along with total price
    void outputOrderAndPrice() const {
        cout << "--- Order Details ---" << endl;
        double totalPrice = 0.0;

        // iterate through all pizzas in the order
        for (size_t i = 0; i < pizzas.size(); i++) {
            cout << "Pizza " << (i + 1) << ":" << endl;
            pizzas[i].outputDescription();
            double price = pizzas[i].computePrice();
            cout << "Price: $" << price << endl << endl;
            totalPrice += price;
        }

        cout << "---------------------" << endl;
        cout << "Total Price: $" << totalPrice << endl;
    }
};

int main() {
    // set format for outputting currency
    cout << fixed << setprecision(2);

    Order myOrder;
    char addMore = 'y';

    cout << "=== Pizza Order System ===" << endl << endl;

    while (addMore == 'y' || addMore == 'Y') {
        int type, size, pepperoni, cheese;

        // get pizza type from user
        cout << "Enter pizza type (0 = Deep Dish, 1 = Hand Tossed, 2 = Pan): ";
        cin >> type;
        while (type < 0 || type > 2) {
            cout << "Invalid type. Enter 0, 1, or 2: ";
            cin >> type;
        }

        // get pizza size from user
        cout << "Enter pizza size (0 = Small, 1 = Medium, 2 = Large): ";
        cin >> size;
        while (size < 0 || size > 2) {
            cout << "Invalid size. Enter 0, 1, or 2: ";
            cin >> size;
        }

        // get number of toppings from user
        cout << "Enter number of pepperoni toppings: ";
        cin >> pepperoni;
        while (pepperoni < 0) {
            cout << "Invalid number. Enter a non-negative value: ";
            cin >> pepperoni;
        }

        cout << "Enter number of cheese toppings: ";
        cin >> cheese;
        while (cheese < 0) {
            cout << "Invalid number. Enter a non-negative value: ";
            cin >> cheese;
        }

        // add pizza to the order
        myOrder.addPizza(type, size, pepperoni, cheese);
        cout << "Pizza added to order!" << endl << endl;

        // ask if user wants to add another pizza
        cout << "Add another pizza? (y/n): ";
        cin >> addMore;
        cout << endl;
    }

    // output full order details and total price
    myOrder.outputOrderAndPrice();

    return 0;
}