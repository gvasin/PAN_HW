#include <iostream>
#include <cmath>
using namespace std;

int main() {
    system("chcp 65001");
    double ay, h;
    cout << "Вертикальное ускорение: "; 
    cin >> ay;
    cout << "Высота: ";                      
    cin >> h;

    if (ay <= 0 || h <= 0) {
        cout << "Ошибка: ускорение и высота должны быть > 0" << endl;
    }
    else {
        cout << "Время набора высоты t = " << sqrt(2 * h / ay) << " с" << endl;
    }
    return 0;
}
