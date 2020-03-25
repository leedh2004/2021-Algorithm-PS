#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

int visited[10000000]; // 0이어야 소수임
int selected[10];
int chk[10000000];
string s;
vector<int> path;
int ans = 0;


bool isSosu(int val){
    int k = sqrt(val);
    if(val == 0 || val == 1) return false;
    for(int i=2; i<=k; i++){
        if(val%i == 0) return false;
    }
    return true;
}

void dfs(int count, int end){
    if(count == end){
        int val = 0;
        int t = 0;
        for(int i=end-1; i>=0; i--){
            val += pow(10, t)*(path[i]);
            t++;
        }
        if(!chk[val] && isSosu(val)) ans++;
        chk[val] = 1;
        return;
    }

    for(int i=0; i<s.size(); i++){
        if(selected[i]) continue;
        path.push_back(s[i]-'0');
        selected[i]=1;
        dfs(count+1, end);
        selected[i]=0;
        path.pop_back();
    }

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // visited[0] = visited[1] = 1;
    // for(int i=2; i<=9999999; i++){
    //     for(int j=i*i; j<=9999999; j=j+i){
    //         visited[j] = 1;
    //     } 
    // }

    int t;
    cin >> t;

    while(t--){
        memset(chk, 0, sizeof(chk));
        cin >> s;
        ans = 0;
        for(int i=1; i<=s.size(); i++){
            dfs(0, i);
        }
        cout << ans << endl;
    }

    return 0;
}