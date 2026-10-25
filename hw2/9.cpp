#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    system("chcp 65001 > nul");

    
    vector<double> h{0.0, 48.3, 79.1, 107.2, 118.9, 122.4, 105.8, 81.3, 44.2, 0.0};

    size_t n = h.size();
    vector<double> smoothed(n);   // все 0.0
    
    smoothed[0] = h[0];
    smoothed[n - 1] = h[n - 1];

    
    for (size_t i = 1; i + 1 < n; ++i) { // нельяз n-1 безразмерное
        smoothed[i] = (h[i - 1] + h[i] + h[i + 1]) / 3.0;
    }

   
    cout << setw(12) << "Исходный" << setw(12) << "Сглаженный" << "\n";
    cout << fixed << setprecision(2);
    for (size_t i = 0; i < n; ++i) {
        cout << setw(12) << h[i] << setw(12) << smoothed[i] << "\n";
    }
}