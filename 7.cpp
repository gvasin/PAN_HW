#include <iostream>
using namespace std;

class FlightComputer {
private:
    double altitude;
    double velocity;
    double fuel;
    double thrust;

public:
    FlightComputer(double alt, double vel, double f, double t) {
        altitude = alt;
        velocity = vel;
        fuel = f;
        thrust = t;
    }

    void simulateStep(double dt) {
        velocity += (thrust / 1000.0 - 9.8) * dt;
        altitude += velocity * dt;
        fuel -= dt * 2;
    }

    void printStatus() {
        cout << altitude << " " << velocity << " " << fuel << endl;
    }
};

int main() {
    FlightComputer fc(0, 0, 100, 12000);
    for (int i = 0; i < 5; i++) {
        fc.simulateStep(0.5);
        fc.printStatus();
    }
    return 0;
}