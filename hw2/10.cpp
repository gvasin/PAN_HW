#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct Point {
    double x = 0.0, y = 0.0, z = 0.0;
};

int main() {
    system("chcp 65001 > nul");

    
    vector<double> vx{10, 15, 5, -10, 0};
    vector<double> vy{0, -5, 10, 0, 20};
    vector<double> vz{50, 40, 60, 45, 55};

    size_t numRockets = vx.size();
    double dt = 1.0, T = 10.0;

    
    vector<double> x(numRockets, 0.0);
    vector<double> y(numRockets, 0.0);
    vector<double> z(numRockets, 0.0);

    
    vector<vector<Point>> trajectories(numRockets);

    for (double t = 0.0; t <= T; t += dt) {
        for (size_t i = 0; i < numRockets; ++i) {
            x[i] += vx[i] * dt;
            y[i] += vy[i] * dt;
            z[i] += vz[i] * dt;

            trajectories[i].push_back({x[i], y[i], z[i]});
        }
    }

    cout << fixed << setprecision(2);
    for (size_t i = 0; i < numRockets; ++i) {
        cout << "Ракета " << i + 1 << ": финальная позиция ("
             << x[i] << ", " << y[i] << ", " << z[i] << ")\n";
    }
}