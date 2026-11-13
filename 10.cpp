#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class DroneFlight {
private:
    vector<double> x, y;
    double totalDistance;

public:
    DroneFlight() {
        x.push_back(0);
        y.push_back(0);
        totalDistance = 0;
    }

    void addPoint(double newX, double newY) {
        double dx = newX - x.back();
        double dy = newY - y.back();
        totalDistance += sqrt(dx * dx + dy * dy);
        x.push_back(newX);
        y.push_back(newY);
    }

    double getTotalDistance() {
        return totalDistance;
    }

    void printPath() {
        for (size_t i = 0; i < x.size(); i++) {
            cout << x[i] << " " << y[i] << endl;
        }
    }
};

int main() {
    DroneFlight d;
    d.addPoint(0, 0);
    d.addPoint(3, 4);
    d.addPoint(6, 8);
    d.printPath();
    cout << d.getTotalDistance() << endl;
    return 0;
}