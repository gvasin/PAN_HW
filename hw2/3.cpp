#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    system("chcp 65001");
    double v0 = 50.0, g = 9.8, dt = 1.0;
    double t_max = v0 / g;
    vector<double> times;
    vector<double> velocities;

    for (double t = 0.0; t <= t_max; t += dt) {
        double v = v0 - g * t;
        times.push_back(t);
        velocities.push_back(v);
    }

    cout << setw(10) << "Время" << setw(10) << "Скорость" << "\n";
    for (size_t i = 0; i < times.size(); ++i) {
        cout << setw(10) << setprecision(2) << fixed << times[i]
             << setw(10) << velocities[i] << "\n";
    }
}