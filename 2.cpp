#include <iostream>
using namespace std;

double sopr(double rho, double V, double S, double CD) {
    return 0.5 * rho * V * V * S * CD;
}

int main() {
    system("chcp 65001");
    double rho, V, S, CD;
    cout << "Плотность воздуха: "; 
    cin >> rho;
    cout << "Скорость: ";               
    cin >> V;
    cout << "Площадь крыла: ";          
    cin >> S;
    cout << "Коэффициент сопротивления: ";  
    cin >> CD;
    cout << "Сопротивление = " << sopr(rho, V, S, CD) << " Н" << endl;
    return 0;
}
