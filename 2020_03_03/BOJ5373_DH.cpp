#include <iostream>
using namespace std;

char U[3][3];  
char D[3][3]; 
char F[3][3];
char B[3][3];
char L[3][3];
char R[3][3];

char tmp[3]; // 3개의 tmp 배열.
// 무조건 흰 면 기준에서 생각한다.

void Left(){ // 흰면의 왼쪽을 반시계로 돌림
    for(int i=0; i<3; i++){
        tmp[i] = U[i][0];
        U[i][0] = F[i][0];
        F[i][0] = D[i][0];
        D[i][0] = B[i][0];
        B[i][0] = tmp[i];
    }   
}

void Up(){ // 흰면의 위를 반시계로 돌림
    for(int i=0; i<3; i++){
        tmp[i] = U[0][i];
        U[0][i] = R[0][i];
        R[0][i] = D[0][i];
        D[0][i] = L[0][i];
        L[0][i] = tmp[i];
    }
}

void Down(){
    for(int i=0; i<3; i++){
        tmp[i] = U[2][i];
        U[2][i] = R[2][i];
        R[2][i] = D[2][i];
        D[2][i] = L[2][i];
        L[2][i] = tmp[i];
    }
}

void Right(){
    for(int i=0; i<3; i++){
        tmp[i] = U[i][2];
        U[i][2] = F[i][2];
        F[i][2] = D[i][2];
        D[i][2] = B[i][2];
        B[i][2] = tmp[i];
    }
}

// 문제는 흰면을 돌릴때를 생각못했다.
void WhitePlus(){
    for(int i=0; i<3; i++){
        tmp[i] = L[0][i];
        L[0][i] = F[0][i];
        F[0][i] = R[0][i];
        R[0][i] = B[0][i];
        B[0][i] = tmp[i];
    }
    char W[3][3]; //임시배열
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            W[i][j] = U[i][j];
        }
    }
    U[0][0] = W[2][0];
    U[0][1] = W[1][0];
    U[0][2] = W[0][0];
    U[1][0] = W[2][1];
    U[1][2] = W[0][1];
    U[2][0] = W[2][2];
    U[2][1] = W[1][2];
    U[2][2] = W[0][2];
}

void YellowPlus(){
     for(int i=0; i<3; i++){
        tmp[i] = L[2][i];
        L[2][i] = F[2][i];
        F[2][i] = R[2][i];
        R[2][i] = B[2][i];
        B[2][i] = tmp[i];
    }
}

int main(){

    int t;
    cin >> t;
    while(t--){
        int l; cin >> l;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                U[i][j] = 'w';
                D[i][j] = 'y';
                F[i][j] = 'r';
                B[i][j] = 'o';
                L[i][j] = 'g';
                R[i][j] = 'b';
            }
        }
        while(l--){
            char ap, op;
            cin >> ap >> op;
            if(ap == 'L'){
                if(op =='+'){
                    Left();
                    Left();
                    Left();
                }else{
                    Left();
                }
            }
            if(ap == 'R'){
                if(op =='+'){
                    Right();
                }else{
                    Right();
                    Right();
                    Right();
                }
            }
            if(ap == 'F'){
                if(op =='+'){
                    Down();
                    Down();
                    Down();
                }else{
                    Down();
                }
            }
            if(ap == 'B'){
                if(op =='+'){
                    Up();
                }else{
                    Up();
                    Up();
                    Up();
                }
            }
            if(ap == 'U'){
                if(op =='+'){
                    WhitePlus();
                }else{
                    WhitePlus();
                    WhitePlus();
                    WhitePlus();
                }
            }
            if(ap == 'D'){
                if(op =='+'){
                    YellowPlus();
                    YellowPlus();
                    YellowPlus();
                }else{
                    YellowPlus();
                }
            }
        }
        for(int i=0;i<3;i++, cout<<'\n')
            for(int j=0;j<3;j++)
                cout << U[i][j];
    }

    return 0;
}