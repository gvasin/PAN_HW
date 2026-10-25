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

    
    
        if (heights.empty()) {
    cout << "Данных нет\n";
    return 1;
}

size_t id_max = 0;
for (size_t i = 0; i < heights.size(); i++) {
    if (heights[i] > heights[id_max]) {
        id_max = i;
    }
}

cout << "\nМаксимальная высота: " << fixed << setprecision(2) << heights[id_max]
     << " в момент времени t = " << times[id_max] << "\n";

    
}