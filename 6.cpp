#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  system("chcp 65001");
    const int N = 5;
    const double S = 16, CL = 0.9;
    double V[N]   = {60, 70, 80, 90, 100};
    double rho[N] = {1.225, 1.112, 1.007, 0.909, 0.819};

    cout << fixed << setprecision(2);
    cout << "| Шаг | Скорость | Плотность | Подъемная сила |" << endl;
    for (int i = 0; i < N; i++) {
        double L = 0.5 * rho[i] * V[i] * V[i] * S * CL;
        cout << "| " << setw(3) << i + 1 << " | " << setw(8) << V[i] << " | " << setw(9) << rho[i] << " | " << setw(14) << L << " |" << endl;
    }
    return 0;
}
