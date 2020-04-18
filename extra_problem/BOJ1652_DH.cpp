#include <iostream>
using namespace std;
bool row[101][101];
bool col[101][101];

int main(){
    char b[101][101];
    
    int n; cin >> n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> b[i][j];
    int r=0, c=0;
    for(int i=0; i<n; i++){
        for(int j=1; j<n; j++){
            if(b[i][j] == '.'){
                if(b[i][j-1] == '.'){
                    if(!row[i][j-1]){
                        row[i][j] = 1;
                        r++;
                    }else
                        row[i][j] = 1;
                }
            }
        }
    }
     for(int j=0; j<n; j++){
        for(int i=1; i<n; i++){
            if(b[i][j] == '.'){
                if(b[i-1][j] == '.'){
                    if(!col[j][i-1]){
                        col[j][i] = 1;
                        c++;
                    }else{
                        col[j][i] = 1;
                    }
                }
            }
        }
    }
     
    cout << r << " " << c;
    return 0;
}