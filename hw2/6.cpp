#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
    system("chcp 65001 > nul");

    vector<double> heights = {5.0, 15.0, 8.0, 20.0, 7.0, 25.0,13.0,18.0};

    cout << "До удаления: ";
    for (double h : heights) cout << h << " ";
    cout << "\n";

    auto new_end = remove_if(heights.begin(), heights.end(),
                              [](double h) { return h < 10.0; });// лябф
    heights.erase(new_end, heights.end());

    cout << "После удаления: ";
    for (double h : heights) cout << h << " ";
    cout << "\n";

    cout << "Размер вектора: " << heights.size() << "\n";
}