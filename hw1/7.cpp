#include <iostream>
using namespace std;

int main() {
  system("chcp 65001");
    const double g = 9.81;
    double T, L, D;
    cout << "Тяга: ";            
    cin >> T;
    cout << "Подъемная сила: ";  
    cin >> L;
    cout << "Сопротивление: ";   
    cin >> D;

    double m = L / g;          
    double a = (T - D) / m;
    cout << "Ускорение a = " << a << " м/с^2" << endl;

    if (a > 0.5){
        cout << "Режим: набор высоты" << endl;
    }   
    else if (a >= 0){
        cout << "Режим: горизонтальный полет" << endl;
    }
    else {
        cout << "Режим: снижение" << endl;
    }    
    return 0;
}
