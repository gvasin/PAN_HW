#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
    system("chcp 65001 > nul");

    double g = 9.8, dt = 1.0;

    
    double v0_1 = 50.0, t_max1 = 20.0;
    vector<double> times1, heights1;

    for (double t = 0.0; t <= t_max1; t += dt) {
        double h = v0_1 * t - 0.5 * g * t * t;
        times1.push_back(t);
        heights1.push_back(h);
    }
    double v0_2 = 70.0, t_max2 = 20.0;
    vector<double> times2, heights2;

    for (double t = 0.0; t <= t_max2; t += dt) {
        double h = v0_2 * t - 0.5 * g * t * t;
        times2.push_back(t);
        heights2.push_back(h);
    }

    


    auto it1 = max_element(heights1.begin(), heights1.end());
    size_t idx_max1 = distance(heights1.begin(), it1);
    double max1 = *it1; // место = инфо
    auto it2 = max_element(heights2.begin(), heights2.end());
    size_t idx_max2 = distance(heights2.begin(), it2);
    double max2 = *it2;

    
    auto fall_it1 = find_if(heights1.begin() + 1, heights1.end(),
    [](double h) { return h <= 0.0; });

    auto fall_it2 = find_if(heights2.begin() + 1, heights2.end(),
    [](double h) { return h <= 0.0; });

    cout << fixed << setprecision(2);

    cout << "Ракета 1: max_height =" << max1 << " (t =" << times1[idx_max1] << ")"<<"\n";
    if (fall_it1 != heights1.end()) {
        size_t idx_fall1 = distance(heights1.begin(), fall_it1);
        cout << ", time_of_fall=" << times1[idx_fall1] << "\n";
    } else {
        cout << ", падения не было в этом диапазоне"<<"\n";
    }

    cout << "Ракета 2: max_height =" << max2 << " (t =" << times2[idx_max2] << ")" << "\n";
    if (fall_it2 != heights2.end()) {
        size_t idx_fall2 = distance(heights2.begin(), fall_it2);
        cout << ", time_of_fall=" << times2[idx_fall2] << "\n";
    } else {
        cout << ", падения не было в этом диапазоне"<<"\n";
    }


    cout << (max1 > max2 ? "Ракета 1" : "Ракета 2") << " поднялась выше"<<"\n"; //verilog 

    if (fall_it1 != heights1.end() && fall_it2 != heights2.end()) {
        double t_fall1 = times1[distance(heights1.begin(), fall_it1)];
        double t_fall2 = times2[distance(heights2.begin(), fall_it2)];
        cout << (t_fall1 > t_fall2 ? "Ракета 1" : "Ракета 2") << " дольше находилась в воздухе"<<"\n";
    } else if (fall_it1 == heights1.end() && fall_it2 != heights2.end()) {
        cout << "Ракета 1 дольше в воздухе "<<"\n";
    } else if (fall_it2 == heights2.end() && fall_it1 != heights1.end()) {
        cout << "Ракета 2 дольше в воздухе "<<"\n";
    } else {
        cout << "Обе ракеты ещё в воздухе, сравнить нельзя"<<"\n";
    }
}