#include <iostream>
#include <string>
using namespace std;

int cnt[10];

int main(){
    string s;
    cin >> s;
    int ans = 1;

    for(int i=0; i<s.size(); i++){
        if(s[i] == '2' || s[i] == '0' || s[i] =='1' || s[i] == '8'){
            cnt[s[i]-'0']++;
        }else{
            cout << 0;
            return 0;
        }
    }

    if(cnt[2] * cnt[0] * cnt[1] * cnt[8] > 0){
        ans = 2;
        if(cnt[2] == cnt[0] && cnt[2] == cnt[1] && cnt[2] == cnt[8])
            ans = 8;
    } 

    cout << ans;
    return 0;
}