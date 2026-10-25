#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct Point {
    double x, y, z;
};

int main() {
    system("chcp 65001");

    double vx = 30.0, vy = 20.0, vz = 40.0;
    double dt = 1.0, t_max = 6.0;

    vector<Point> traj;
    traj.reserve((int)(t_max / dt) + 1);

    double x = 0.0, y = 0.0, z = 0.0;

    for (double t = 0.0; t <= t_max; t += dt) {
        x += vx * dt;
        y += vy * dt;
        z += vz * dt;
        traj.push_back({x, y, z});  
    }

    cout << setw(10) << "t" << setw(10) << "x" << setw(10) << "y" << setw(10) << "z" << "\n";
    double t = 0.0;
    for (size_t i = 0; i < traj.size(); ++i) {
        t += dt;
        cout << setw(10) << fixed << setprecision(2) << t
             << setw(10) << traj[i].x
             << setw(10) << traj[i].y
             << setw(10) << traj[i].z << "\n";
    }
}