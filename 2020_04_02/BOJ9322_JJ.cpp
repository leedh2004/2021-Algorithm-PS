#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;



int main(){
    int t;cin>>t;
    while (t--){
        map <string,int> m;
        vector<pair<int,int> > v;
        vector<string> vs;
        int n;cin>>n;
        v.resize(n);
        vs.resize(n);
        string s;
        for(int i=1;i<=n;i++){
            cin>>s;
            m.insert(make_pair(s,i));
        }
        for(int i=0;i<n;i++){
            cin>>s;
            v[i]= make_pair(i+1, m[s] );
        }
        for(int i=0;i<n;i++){
            cin>>s;
            vs[v[i].second-1] =s;
        }
        for(int i=0;i<n;i++){
            cout<<vs[i]<<" ";
        }
        cout<<"\n";
    }
    


}