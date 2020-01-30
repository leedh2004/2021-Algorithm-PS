#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000000];
int lis[1000000]; // lis[x] 는 길이가 x일때 마지막 수열의 최소값
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    for(int i=0; i<n; i++) cin >> arr[i];
    int ans = 0;
    for(int i=0; i<n; i++){
        if(lis[ans] < arr[i]) lis[++ans] = arr[i];
        else{
            int* p = lower_bound(lis + 1, lis + ans, arr[i]);
            *p = min(*p, arr[i]);
        }
    }
    cout << ans;
    return 0;
}