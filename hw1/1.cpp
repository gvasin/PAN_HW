#include <iostream>
using namespace std;

int main() {
   system("chcp 65001");
    double rho, V, S, CL;
    cout << "Плотность воздуха: "; 
    cin >> rho;
    cout << "Скорость: ";               
    cin >> V;
    cout << "Площадь крыла: ";          
    cin >> S;
    cout << "Коэффициент подъемной силы: ";  
    cin >> CL;

    double L = 0.5 * rho * V * V * S * CL;
    cout << "Подъемная сила L = " << L << " Н" << endl;
    return 0;
}
