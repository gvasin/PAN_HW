#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    system("chcp 65001");
    double v0 = 50.0, g = 9.8, dt = 1.0;

    vector<double> times;
    vector<double> heights;

    for (double t = 0.0;;t += dt) {
        double h = v0*t - 0.5*g*t*t;
        if (h < 0) {
            break;              
        }
         else {
            times.push_back(t);
            heights.push_back(h);
        }
    }

    cout << setw(10) << "Время" << setw(10) << "Высота" << "\n";
    for (size_t i = 0; i < times.size(); ++i) {
        cout << setw(10) << setprecision(2) << fixed << times[i]
             << setw(10) << heights[i] << "\n";
    }
}