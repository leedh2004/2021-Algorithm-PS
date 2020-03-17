#include <iostream>
using namespace std;

char arr[3] = {'R', 'S', 'P'};

int main(){
    char A, B, C, D; // R S P
    cin >> A >> B >> C >> D;
    
    if(A == B){
        if(A == 'R'){
            if(C == 'P' || D == 'P'){
                cout << "TK";
                return 0;
            }
        }
        if(A == 'S'){
            if(C == 'R' || D == 'R'){
                cout << "TK";
                return 0;
            }
        }
        if(A == 'P'){
            if(C == 'S' || D == 'S'){
                cout << "TK";
                return 0;
            }
        }
    }

    if(C == D){
        if(C == 'R'){
            if(A == 'P' || B == 'P'){
                cout << "MS";
                return 0;
            }
        }
        if(C == 'S'){
            if(A == 'R' || B == 'R'){
                cout << "MS";
                return 0;
            }
        }
        if(C == 'P'){
            if(A == 'S' || B == 'S'){
                cout << "MS";
                return 0;
            }
        }
    }

    cout << "?";

    return 0;
}