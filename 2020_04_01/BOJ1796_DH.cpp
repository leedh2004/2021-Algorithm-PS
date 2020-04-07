#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

int dp[30][2]; // dp[2][0] 가장왼쪽의 'c' 로 끝날 때 키를 누르는 최솟값
               // dp[2][1] 가장오른쪽의 'c'로 끝날 때 키를 누르는 최솟값
// dp[?][0] = dp[?-1][1] + abs(right[?-1] - right[?]) + abs(right[?] - left[?]) + cnt[?]

int r[30];
int l[30];
int cnt[30];

int main(){
    memset(l, -1, sizeof(l));
    string s, tmp;
    cin >> s;
    tmp = s;
    sort(tmp.begin(), tmp.end());
    vector<char> alphabet;
    int size = s.size();
    alphabet.push_back(tmp[0]);
    for(int i=0; i<size; i++){
        if (l[s[i]-'a'] == -1) l[s[i]-'a'] = i;
        r[s[i]-'a'] = max(r[s[i]-'a'], i);
        cnt[s[i]-'a']++;
    }
    for(int i=1; i<size; i++)
        if(tmp[i] != tmp[i-1]) alphabet.push_back(tmp[i]);
    
    for(int i=0; i<alphabet.size(); i++){
        char here = alphabet[i];
        int idx = here - 'a';
        if(i==0){
            dp[idx][0] = r[idx] + abs(r[idx] - l[idx]) + cnt[idx];
            dp[idx][1] = r[idx] + cnt[idx];
            // cout << here << endl;
            // cout << dp[idx][0] << " " << dp[idx][1] << endl;
            if(i == alphabet.size() - 1){
                cout << min (dp[idx][0], dp[idx][1]);
            }
        }else{
            char before = alphabet[i-1];
            int bidx = before - 'a';
            dp[idx][0] = dp[bidx][1] + abs(r[bidx] - r[idx]);
            dp[idx][0] = min(dp[idx][0], dp[bidx][0] + abs(l[bidx] - r[idx]));
            dp[idx][1] = dp[bidx][1] + abs(r[bidx] - l[idx]);
            dp[idx][1] = min(dp[idx][1], dp[bidx][0] + abs(l[bidx] - l[idx]));
            dp[idx][0] += abs(r[idx] - l[idx]) + cnt[idx];
            dp[idx][1] += abs(r[idx] - l[idx]) + cnt[idx];
            // cout << here << endl;
            // cout << dp[idx][0] << " " << dp[idx][1] << endl;
            if(i == alphabet.size() - 1){
                cout << min (dp[idx][0], dp[idx][1]);
            }
        }
    }


    return 0;
}