#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

string original[100];
char trans[100][100];

char before[10] = {'.', 'O', '-', '|', '/', '\\', '^', '<', 'v', '>' };
char after[10] = {'.', 'O', '|', '-', '\\', '/', '<', 'v', '>', '^'};

int main(){
    int y, x;
    cin >> y >> x;

    for(int i=0; i<y; i++){
        cin >> original[i];
        for(int j=0; j<x; j++){
            for(int idx=0; idx<10; idx++){
                if(before[idx] == original[i][j]){
                    trans[x-j-1][i] = after[idx];
                }
            }
        }
    }
    
    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            cout << trans[i][j];
        }
        cout << endl;
    }
    return 0;
}