#include <iostream>
#include <vector>
using namespace std;

int a[401][401];
int main(){

    int n, k;
    cin >> n >> k;
    for(int i=0; i<k; i++){
        int from, to;
        cin >> from >> to;
        a[from][to] = -1;
        a[to][from] = 1;
    }
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if( (a[i][k] == 1 || a[i][k] == -1) && a[i][k] == a[k][j]){
                    a[i][j] = a[i][k];
                }
            }
        }
    }
    int l;
    cin >> l;
    for(int i=0; i<l; i++){
        int from, to;
        cin >> from >> to;
        cout << a[from][to] << endl;
    }
    return 0;
}