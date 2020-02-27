#include <iostream>
using namespace std;

const int INF = 987654321;

int dp[1<<16];
int a[16][16];
int n;
int ans = INF;

int solve(int bit, int j){ // 켜져있는 bit 중 j를 키는데 필요한 최소 cost 반환
    int answer = INF;

    for(int i=0; i<n; i++){
        int mask = (1 << i);
        if ( bit & mask ) answer = min(answer, a[n-1-i][j]);
    }
    return answer;
}

int count(int bit){
    int cnt = 0;
    for(int i=0; i<n; i++){
        int mask = (1 << i);
        if ( bit & mask ) cnt++;
    }
    return cnt;
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> a[i][j];
    for(int i=0; i < 1<<16; i++)
        dp[i] = INF; // 무한대값으로 초기화
    string s;
    cin >> s;
    int start = (1 << n) - 1;
    bool flag = false;

    for(int i=0; i<s.size(); i++){
        if(s[i] == 'N'){
            int k = (1 << (n - 1 - i));
            start -= k;
        }else
            flag = true;
    }
    dp[start] = 0;
    int p;
    cin >> p;

    if(!flag){
        if(p ==0) cout << 0;
        else cout << -1;
        return 0;
    }
    if(n < p){
        cout << -1;
        return 0;
    }

    for(int i = 0; i < (1 << n); i++){
        for(int j=0; j<n; j++){
            int temp = (1 << n) - 1;
            int mask = (1 << j);
            temp = temp ^ mask;
            int target = i & temp;
            if( target == i) continue;
            dp[i] = min(dp[i], dp[target] + solve(target, n-1-j));// dp[target] + 켜져있는 발전기 중 j를 키는데 최소값
            if( count(i) >= p) ans = min(ans, dp[i]);
        }
    }
    if(ans == INF){
        cout << -1;
    }else{
        cout << ans;
    }
    return 0;
}