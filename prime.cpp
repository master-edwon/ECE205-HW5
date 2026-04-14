#include <iostream>

using namespace std;

class PrimeNumber {
private:
    int prime;

    // helper function to check if prime
    bool isPrime(int n) const {
        if (n <= 1) return false;
        if (n == 2) return true;
        if (n % 2 == 0) return false;
        for (int i = 3; i * i <= n; i += 2) {
            if (n % i == 0) return false;
        }
        return true;
    }

public:
    // default constructor
    PrimeNumber() {
        prime = 1;
    }

    // constructor with parameters
    PrimeNumber(int p) {
        prime = p;
    }

    // getter function
    int getPrime() const {
        return prime;
    }

    // prefix increment (++p)
    PrimeNumber& operator++() {
        int current = prime + 1;
        while (current > 1 && !isPrime(current)) {
            current++;
        }
        prime = current;
        return *this;
    }

    // postfix increment (p++)
    PrimeNumber operator++(int) {
        PrimeNumber temp = *this; // store old state    
        ++(*this);                // increment current state using prefix ++
        return temp;              // return old state
    }

    // postfix decrement (p--)
    PrimeNumber& operator--() {
        int current = prime - 1;
        // search downwards for the next smaller prime
        while (current > 1 && !isPrime(current)) {
            current--;
        }
        // use 1 as a default if no smaller prime is found
        if (current < 1) {
            current = 1;
        }
        prime = current;
        return *this;
    }

    // postfix decrement (p--)
    PrimeNumber operator--(int) {
        PrimeNumber temp = *this;
        --(*this);
        return temp;
    }
};

int main() {
    int input;
    cout << "Enter a number (or 0 for default): ";
    cin >> input;

    PrimeNumber p1;

    if (input > 0) {
        // user input
        p1 = PrimeNumber(input);
        cout << "You entered: " << p1.getPrime() << endl;

        // if the number is not prime, move to the next highest prime using prefix ++ to find the next prime
        PrimeNumber test(input); // test variable to check if input is prime
        ++test; // increment test
        --test; // decrement test
        if (test.getPrime() != input) { // if test is not equal to input, then input is not prime
            p1 = PrimeNumber(input);
            ++p1; // use prefix ++ to get next highest prime
            cout << input << " is not prime. Using next highest prime: " << p1.getPrime() << endl;
        }
    } else {
        // default constructor sets prime to 1
        cout << "Using default constructor, p1: " << p1.getPrime() << endl;
    }

    cout << endl;
    cout << "Starting value: " << p1.getPrime() << endl << endl;

    // testing prefix ++
    ++p1;
    cout << "After ++p1, p1 is: " << p1.getPrime() << endl;

    // testing postfix ++
    PrimeNumber p2 = p1++;
    cout << "After p2 = p1++, p2 is: " << p2.getPrime() << ", p1 is: " << p1.getPrime() << endl;

    // testing prefix --
    --p1;
    cout << "After --p1, p1 is: " << p1.getPrime() << endl;

    // testing postfix --
    PrimeNumber p_temp = p1--;
    cout << "After p_temp = p1--, p_temp is: " << p_temp.getPrime() << ", p1 is: " << p1.getPrime() << endl;

    return 0;
}
