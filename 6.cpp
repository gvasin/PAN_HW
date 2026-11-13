#include <iostream>
using namespace std;

class RocketStage {
private:
    double thrust;
    double mass;
    double burnTime;



public:
RocketStage(double  t, double m, double b){
        thrust = t;
        mass = m;
        burnTime = b;
}
    double getDeltaV() {
        if (mass == 0) return 0;
        return thrust *burnTime / mass;
    }

    void printInfo() {
        cout <<  getDeltaV() << endl;
    }
};

int main() {
    double totalVelocity=0;
    RocketStage s1(5000, 10, 1000); 
    RocketStage s2(7000, 8, 900); 
    RocketStage s3(9000, 6, 800); 
    totalVelocity=s1.getDeltaV()+totalVelocity;
    totalVelocity=s2.getDeltaV()+totalVelocity;
    totalVelocity=s3.getDeltaV()+totalVelocity;
    cout <<totalVelocity;

    return 0;
}