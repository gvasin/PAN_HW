#include <iostream>
using namespace std;

int main() {
    system("chcp 65001");
    const double rho = 1.225, V = 70;
    int N;
    cout << "Количество самолетов N: "; 
    cin >> N;

    int i_max = 0;
    double a_max = -1000000;
    
    for (int i = 0; i < N; i++) {
        double m, S, T, CL, CD;
        cout << "Самолет " << i + 1 << " (m S T CL CD): ";
        cin >> m >> S >> T >> CL >> CD;

        double q = 0.5 * rho * V * V * S;
        double L = q * CL, D = q * CD, a = (T - D) / m;
        cout << "  L = " << L << " Н, D = " << D << " Н, a = " << a << " м/с^2" << endl;

        if (a > a_max){
            i_max = i; 
            a_max = a; 
        }
    }
    cout << "Наибольшее ускорение у самолета " << i_max + 1 << ": a = " << a_max << " м/с^2" << endl;
    return 0;
}
