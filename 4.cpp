#include <iostream>
using namespace std;

class Gyroscope {
private:
    double angularVelocity;
    bool calibrationRequired;

public:
    Gyroscope(double velocity, bool required) {
        angularVelocity = velocity;
        calibrationRequired = required;
    }

    void calibrate() {
        calibrationRequired = false;
    }

    void printStatus() {
        cout << angularVelocity << " | ";
        if (calibrationRequired) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }
};

int main() {
    Gyroscope g1(120.5, true);
    g1.printStatus();
    g1.calibrate();
    g1.printStatus();
    return 0;
}