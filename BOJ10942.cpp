#include <iostream>
#include <cstring>
using namespace std;

int arr[2001];
int dp[2001][2001];

int isPellindrom(int st, int ed){

    int& ret = dp[st][ed];
    if(ret != -1) return ret;

    if(st == ed) return ret = 1;
    if( st + 1 == ed ) return arr[st] == arr[ed];
    
    if(arr[st] != arr[ed]) return ret = 0;
    else return ret = isPellindrom(st+1, ed-1);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); // 입출력 향상
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    for(int i=0; i<n; i++) cin >> arr[i];
    int m;
    cin >> m;
    for(int i=0; i<m; i++){
        int st, ed;
        cin >> st >> ed;
        cout << isPellindrom(st-1, ed-1) << '\n';
    }
    return 0;
}