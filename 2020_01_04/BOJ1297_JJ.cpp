#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    float s,h,w;
    double t;
    cin>>s>>h>>w;
    t=s/sqrt(h*h+w*w);
    cout<<int( h*t )<<" "<<int( w*t );
    return 0;
}