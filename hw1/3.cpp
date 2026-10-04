#include <iostream>
using namespace std;

int main() {
    system("chcp 65001");
    const double g = 9.81;
    double m, L, D, T;
    cout << "Масса: ";            
    cin >> m;
    cout << "Подъемная сила: ";    
    cin >> L;
    cout << "Сопротивление: ";     
    cin >> D;
    cout << "Тяга: ";              
    cin >> T;

    cout << "Ускорение вдоль движения a = " << (T - D) / m << " м/с^2" << endl;
    cout << "Вертикальное ускорение ay = " << (L - m * g) / m << " м/с^2" << endl;
    return 0;
}
