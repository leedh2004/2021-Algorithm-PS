#include <iostream>
#include <vector>
#include <string> 
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

int priority[26]; // 알파벳 우선순위 값. 
// priority[1] = 1000 는 'B'의 우선순위가 1000임을 나타냄. 우선순위가 클 수록 큰 값을 부여.

int main(){

    int n;
    cin >> n;
    vector<string> s(n);

    for(int i=0; i<n; i++){
        cin >> s[i];
        int len = s[i].size();
        for(int j=0; j<len; j++){
            priority[s[i][j]-'A'] += pow(10, (len - 1) - j); 
        }
    }
    // 우선순위를 부여하자. 우선순위가 가장큰개 결국 9, 우선순위는 자릿수로 판별.
    
    vector<pair<int, char> > v;
    for(int i=0; i<26; i++){
        if(priority[i]){ 
            v.push_back({priority[i] , 'A'+i});
        }
    }
    
    sort(v.begin(), v.end());

    int value[26];
    int val = 9;

    for(int i=v.size()-1; i>=0; i--){
        value[v[i].second - 'A'] = val--;
    }
    int ans = 0;

    for(int i=0; i<n; i++){
        int len = s[i].size();
        for(int j=0; j<len; j++){
            ans += value[s[i][j] - 'A'] * pow(10, (len - 1) - j);
        }
    }

    cout << ans;
    return 0;
}