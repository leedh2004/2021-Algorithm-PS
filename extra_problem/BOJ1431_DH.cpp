#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp (string &a, string &b){
    if(a.size() == b.size()){
        int asum = 0;
        int bsum = 0;

        for(int i=0; i<a.size(); i++){
            int aa = a[i]-'0';
            int bb = b[i]-'0';
            if( aa < 10 && aa > 0) asum += aa;
            if( bb < 10 && bb > 0) bsum += bb;    
        }
        if(asum == bsum){
            return a < b;
        }
        return asum < bsum;
    }

    return a.size() < b.size();
}

int main(){
    int n;
    cin >> n;
    vector<string> v;
    while(n--){
        string s; cin >> s;
        v.push_back(s);
    }
    sort(v.begin(), v.end(), cmp);
    for(int i=0; i<v.size(); i++) cout << v[i] << endl;
    return 0;
}