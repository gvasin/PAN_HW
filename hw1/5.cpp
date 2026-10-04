#include <iostream>
#include <cmath>
using namespace std;

struct Aircraft {
    double m, S, T, CL, CD;
};

int main() {
 system("chcp 65001");
    const double g = 9.81, rho = 1.225, V = 70, h = 1000;
    Aircraft a[3] = {
        {4000, 16, 3000, 0.9, 0.030},
        {4300, 18, 4000, 0.8, 0.035},
        {3800, 14, 2500, 1.0, 0.028}
    };

    int i_min = -1;
    double t_min = 1000000;
    for (int i = 0; i < 3; i++) {
        double q  = 0.5 * rho * V * V * a[i].S;
        double L  = q * a[i].CL, D = q * a[i].CD;
        double ax = (a[i].T - D) / a[i].m;
        double ay = (L - a[i].m * g) / a[i].m;
        cout << "Самолет " << i + 1 << ": L = " << L << " Н, D = " << D << " Н, a = " << ax << " м/с^2, ay = " << ay << " м/с^2" << endl;
        if (ay > 0) {
            double t = sqrt(2 * h / ay);
            if (t < t_min) { 
                i_min = i; 
                t_min = t; 
            }
        }
    }

    cout << "Быстрее наберет " << h << " м самолет " << i_min + 1 << " (t = " << t_min << " с)" << endl;
    return 0;
}
