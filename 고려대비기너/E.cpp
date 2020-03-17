#include <iostream>
#include <string>
using namespace std;

int main(){

    string s;
    cin >> s;
    int sz = s.size();

    int n;
    cin >> n;

    double ans = -1;
    string ansStr;

    while(n--){
        string tmp; cin >> tmp;
        int gbs; cin >> gbs;
        int idx = 0;

        for(int j=0; j<tmp.size(); j++){ // 만들 수 있는지 없는지를 판별
            if(idx == sz) break;
            if(tmp[j] == s[idx]){
                idx++;
            }
        }
        if(idx == sz){ // 만들 수 있는경우
            double a = double(gbs) / (tmp.size() - sz);
            //cout << tmp << " " << a << endl;
            if(a > ans){
                ans = a;
                ansStr = tmp;
            }
        }
    }

    if(ans == -1) cout << "No Jam";
    else{
        cout << ansStr;
    }
    return 0;
}