#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
    system("chcp 65001 > nul");

    double v0 = 50.0, g = 9.8, dt = 1.0, t_max = 20.0;
    vector<double> times, heights;

    for (double t = 0.0;t <= t_max;  t += dt) {
        double h = v0 * t - 0.5 * g * t * t;

        times.push_back(t);
        heights.push_back(h);
    }

    auto it = find_if(heights.begin()+1, heights.end(),
                       [](double h) { return h <= 0.0; });

    if (it == heights.end()) {
        cout << "Падения не было в этом диапазоне\n";
    } else {
        size_t idx = distance(heights.begin(), it);
        double t_fall = times[idx];
        cout << fixed << setprecision(2);
        cout << "Момент падения: t = " << t_fall << ", h = " << heights[idx] << "\n";
    }
}