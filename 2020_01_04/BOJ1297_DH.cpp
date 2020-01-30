#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int d, w, h;
    cin >> d >> h >> w;
    double a = sqrt(pow(d, 2) / (pow(w, 2) + pow(h, 2)));
    cout << int(a*h) << " " << int(a*w);
    return 0;
}