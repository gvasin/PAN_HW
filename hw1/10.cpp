#include <iostream>
#include <cmath>
using namespace std;

int main() {
    system("chcp 65001");
    const double g = 9.81, rho = 1.225, V = 70, S = 16, CL = 0.9, CD = 0.03;
    const double m = 4000, h = 1000;
    const double T_min = 1000, T_max = 5000, dT = 250;

    double L = 0.5 * rho * V * V * S * CL;   
    double D = 0.5 * rho * V * V * S * CD;   

    double T_opt = 0;
    double t_min = 1000000;   

    for (double T = T_min; T <= T_max; T += dT) {
        double ay = (L + (T - D) - m * g) / m;
        if (ay > 0) {
            double t = sqrt(2 * h / ay);
            cout << "T = " << T << " Н: ay = " << ay << " м/с^2, t = " << t << " с" << endl;
            if (t < t_min) {
                t_min = t;
                T_opt = T;
            }
        }
    }

    cout << "Оптимальная тяга T = " << T_opt << " Н, время t = " << t_min << " с" << endl;
    return 0;
}
