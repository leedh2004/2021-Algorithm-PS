#include <iostream>
#include <string>
#include <utility>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

pair<int, int> before[26][2];
pair<int, int> after[26][2];

int main(){
    for(int i=0; i<26; i++){
        before[i][0].first = before[i][1].first = -1;
        after[i][0].first = after[i][1].first = -1;
    }
    int n;
    cin >> n;
    vector<string> s(n);
    //first는 위치, second는 index
    for(int i=0; i<n; i++){
        cin >> s[i];
        for(int j=0; j<s[i].size(); i++){
            char alphabet = s[i][j];
            int beforeVal = j; // alphabet 전의 문자열 개수
            int afterVal = s[i].size() - 1 - j; // alphabet 후의 문자열 개수
            if (before[alphabet-'a'][0].first == -1){
                before[alphabet-'a'][0] = {beforeVal, i};
            }else{
                int first = before[alphabet-'a'][0].first;
                int firstIdx = before[alphabet-'a'][0].second;
                int second = before[alphabet-'a'][1].first;
                int secondIdx = before[alphabet-'a'][1].second;
                if(beforeVal < first){
                    before[alphabet-'a'][1] = before[alphabet-'a'][0];
                    before[alphabet-'a'][0] = {beforeVal, i};
                }else if(beforeVal < second){
                    before[alphabet-'a'][1] = {beforeVal, i};
                }
            }

            if (after[alphabet-'a'][0].first == -1){
                after[alphabet-'a'][0] = {afterVal, i};
            }else{
                int first = after[alphabet-'a'][0].first;
                int firstIdx = after[alphabet-'a'][0].second;
                int second = after[alphabet-'a'][1].first;
                int secondIdx = after[alphabet-'a'][1].second;
                if(afterVal > first){
                    after[alphabet-'a'][1] = after[alphabet-'a'][0];
                    after[alphabet-'a'][0] = {afterVal, i};
                }else if(afterVal > second){
                    after[alphabet-'a'][1] = {afterVal, i};
                }
            }
            //앞 부분이므로 가장 많아야해
            //뒷 부분이므로 가장 적어야함 (음수화)
        }
    }
    int ans = 987654321;
    for(int i=0; i<26; i++){
        if(after[i][0].second == before[i][0].second){

        }else{
            ans = min(ans, after[i][0].first + before[i][0].first);
        }
    }
    cout << ans;
    return 0;
}