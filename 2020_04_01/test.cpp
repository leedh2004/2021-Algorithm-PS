#include <iostream>

int a(); 
int b();

int main(){
    a();
    return 0;
}

int a(){
    b();
    return 1;
}
int b(){
    return 2;
}