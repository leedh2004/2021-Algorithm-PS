#include <iostream>
#include <cstdio>

using namespace std;
int psum[100001];
int main(){
    //ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m, tmp, a, b;
    scanf("%d %d", &n, &m);
//    cin >> n >> m;
    for(int i=1; i<=n; i++){
        scanf("%d", &tmp);
        psum[i] = psum[i-1] + tmp;
    }
    while(m--){
        scanf("%d %d", &a, &b);
        printf("%d\n", psum[b]-psum[a-1]);
        //cout << psum[b] - psum[a-1] << endl;
    }
    return 0;
}