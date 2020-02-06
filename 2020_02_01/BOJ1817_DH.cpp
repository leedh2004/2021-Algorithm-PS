#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int arr[100001];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    stack<int> s;
    for(int i=0; i<n; i++){
        int temp; cin >> temp;
        s.push(temp);
    }
    int w = 0;
    int ans = 0;
    while(!s.empty()){
        int top = s.top();
        if ( w + top > m ){
            w = 0;
            ans++;
        }else{
            w += top;
            s.pop();
        }
    }
    if(w) ans++;
    cout << ans;
    /*
    sort(arr, arr + n);
    // 투 인덱스.. 맨 앞과 맨 뒤로 해서 > m 보다 크다면 더 이상 선택할 수 없는 것 아닌가?
    int start = 0; int end = n - 1;
    int w = 0 ;
    int ans = 0;
    
    while(start < end){ // 기저조건 나중에 확인
        w = arr[end] + arr[start];
        //cout << start << " " << end << endl;
        if ( w > m ){
            ans++;
            end--;
        }else{
            while(start < end){
                start++;
                w += arr[start];
                if ( w > m ){
                    end--;
                    ans++;
                    break;
                }
            }
            if(start == end) ans++;
        }
    }
    cout << ans;
    */
    return 0;
}