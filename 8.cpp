#include <iostream>
#include <cmath>
#include <string>
using namespace std;

struct Aircraft {
    string name;
    double m, T, CL, CD;   
    double ay, t;          
};

int main() {
    system("chcp 65001");
    const double g = 9.81, rho = 1.225, V = 70, S = 16, h = 1000;
    const int N = 4;
    Aircraft a[N] = {
        {"1 самолет", 4000, 3000, 0.90, 0.030},
        {"2 самолет", 3800, 4000, 0.80, 0.035},
        {"3 самолет", 3800, 2500, 1.00, 0.028},
        {"4 самолет", 4100, 3500, 0.95, 0.032}
    };

    for (int i = 0; i < N; i++) {
        double L = 0.5 * rho * V * V * S * a[i].CL;
        a[i].ay = (L - a[i].m * g) / a[i].m;
        a[i].t = sqrt(2 * h / a[i].ay);
    }

    for (int i = 0; i < N - 1; i++)
        for (int j = 0; j < N - 1 - i; j++)
            if (a[j].t > a[j + 1].t) {
                Aircraft tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }

    for (int i = 0; i < N; i++)
        cout << "Самолет " << a[i].name << ": ay = " << a[i].ay << " м/с^2,   t = " << a[i].t << " с" << endl;
    return 0;
}
