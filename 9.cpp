#include <iostream>
using namespace std;

class AutonomousControl {
private:
    double altitude;
    double thrust;
    double targetAltitude;

public:
    AutonomousControl(double alt, double t, double target) {
        altitude = alt;
        thrust = t;
        targetAltitude = target;
    }

    void updateControl() {
        if (altitude < targetAltitude) {
            thrust += 100;
        } else {
            thrust -= 100;
        }
    }

    void simulateStep(double dt) {
        altitude += (thrust / 500.0) * dt;
    }

    void printStatus() {
        cout << altitude << " " << thrust << endl;
    }
};

int main() {
    AutonomousControl ac(0, 2000, 5000);
    for (int i = 0; i < 5; ++i) {
        ac.updateControl();
        ac.simulateStep(1.0);
        ac.printStatus();
    }
    return 0;
}