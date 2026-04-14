#include <iostream>
#include <string>
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
    Pizza() {   // default
        type = HAND_TOSSED;
        size = MEDIUM;
        pepperoniToppings = 0;
        cheeseToppings = 0;
    }

    Pizza(int t, int s, int p, int c) { // contructor with parameters
        type = t;
        size = s;
        pepperoniToppings = p;
        cheeseToppings = c;
    }

    // getters functions
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
            default: basePrice = 0.0; 
            break; 
        }

        double toppingPrice = 2.0 * (pepperoniToppings + cheeseToppings);
        return basePrice + toppingPrice;
    }
};

int main() {
    cout << fixed << setprecision(2);

    // create several pizza objects to test
    Pizza pizza1(HAND_TOSSED, SMALL, 1, 1);
    Pizza pizza2(DEEP_DISH, LARGE, 2, 0);
    Pizza pizza3(PAN, MEDIUM, 0, 3);
    
    // testing default constructor and mutator functions
    Pizza pizza4; 
    pizza4.setType(PAN);
    pizza4.setSize(LARGE);
    pizza4.setPepperoniToppings(3);
    pizza4.setCheeseToppings(2);

    // output descriptions and prices
    cout << "--- Pizza 1 ---" << endl;
    pizza1.outputDescription();
    cout << "Price: $" << pizza1.computePrice() << endl << endl;

    cout << "--- Pizza 2 ---" << endl;
    pizza2.outputDescription();
    cout << "Price: $" << pizza2.computePrice() << endl << endl;

    cout << "--- Pizza 3 ---" << endl;
    pizza3.outputDescription();
    cout << "Price: $" << pizza3.computePrice() << endl << endl;

    cout << "--- Pizza 4 ---" << endl;
    pizza4.outputDescription();
    cout << "Price: $" << pizza4.computePrice() << endl << endl;

    return 0;
}