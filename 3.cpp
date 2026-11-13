#include <iostream>
using namespace std;

class Engine {
private:
    double thrust;
    double fuelFlow;

public:
    Engine(double t, double f) {
        thrust = t;
        fuelFlow = f;
    }

    double getSpecificImpulse() {
        if (fuelFlow == 0) return 0;
        return thrust / (fuelFlow * 9.81);
    }

    void printInfo() {
        cout <<  thrust << endl << fuelFlow << endl << getSpecificImpulse() << endl;
    }
};

int main() {
    Engine e1(5000, 2.5);
    e1.printInfo();
    return 0;
}