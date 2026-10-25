#include <iostream>
#include <vector>
#include <iomanip>
#include <numeric>
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
    double sum = accumulate(velocities.begin(),velocities.end(),0.0);
    double avg = sum/velocities.size();
    cout << setprecision(2) << avg;
}