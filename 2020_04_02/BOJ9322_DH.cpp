#include <iostream>
#include <map>
#include <string>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        map<string, int> a;
        string b[1001], c[1001], d[1001];
        for(int i=0; i<n; i++){
            string s;
            cin >> s;
            a[s] = i;
        }
        for(int i=0; i<n; i++){
            cin >> b[i];
        }
        for(int i=0; i<n; i++){
            cin >> c[i];
        }
        //b[i]의 단어가 a배열 어디에 있는가?
        for(int i=0; i<n; i++){
            string s = b[i];
            int idx = a[s];
            d[idx] = c[i];
        }
        for(int i=0; i<n; i++)
            cout << d[i] << " ";
        cout <<'\n';
    }
    return 0;
}