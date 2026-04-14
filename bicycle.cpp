#include <iostream>

using namespace std;

class BicycleSpeedometer {
private:
    double distance; 
    double time;     

public:
    // default constructor
    BicycleSpeedometer() {
        distance = 0.0;
        time = 0.0;
    }

    // mutator functions for distance and time
    void setDistance(double d) {
        distance = d;
    }

    void setTime(double t) {
        time = t;
    }

    // member function for average speed in miles per hour
    double computeAverageSpeed() {
        if (time == 0) {
            return 0.0; // Prevent division by zero
        }
        // convert to hours
        return distance / (time / 60.0);
    }
};

int main() {
    BicycleSpeedometer bike;

    double travelDistance;
    double travelTime;

    // read input values from the user
    cout << "Enter distance traveled (in miles): ";
    cin >> travelDistance;

    cout << "Enter time taken (in minutes): ";
    cin >> travelTime;

    // set member variables using mutator functions
    bike.setDistance(travelDistance);
    bike.setTime(travelTime);

    // display the results
    cout << "--- Bicycle Speedometer ---" << endl;
    cout << "Distance Traveled: " << travelDistance << " miles" << endl;
    cout << "Time Taken: " << travelTime << " minutes" << endl;
    cout << "Average Speed: " << bike.computeAverageSpeed() << " mph" << endl;

    return 0;
}