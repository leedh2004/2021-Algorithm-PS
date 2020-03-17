#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int visited[4000001];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> v(m);
    for(int i=0; i<m; i++) cin >> v[i];
    sort(v.begin(), v.end());
    vector<int>::iterator iter;
    for(int i=0; i<k; i++){
        int tmp; cin >> tmp;
        iter = upper_bound(v.begin(), v.end(), tmp);
        while(1){
            if(!visited[*iter]){
                cout << *iter << '\n';
                visited[*iter] = 1;
                break;
            }
            else{
                iter++;
            }
        }
    }
    return 0;
}