#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int arr[205][205];
int p[205];

int union_find(int here){
    if( p[here] == here ) return here;
    else return p[here] = union_find(p[here]);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    memset(p, -1, sizeof(p));

    int n, m;
    cin >> n >> m;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
            if(p[i] == -1) p[i] = i; // 부모가 없으면 자신이 부모다.
            if(p[j] == -1) p[j] = j;
            if ( arr[i][j] ) {
                p[i] = max(p[i], p[j]);
                p[j] = max(p[i], p[j]); // 더 큰 값이 부모다.
            }
        }
    }
    for(int i=0; i<n; i++)
        union_find(i);

    int temp;
    cin >> temp;
    int k = p[temp-1];

    for(int i=0; i<m-1; i++){
        cin >> temp;
        if( k != p[temp-1] ){
            cout << "NO";
            exit(0);
        }
    }

    cout << "YES";
    return 0;
}