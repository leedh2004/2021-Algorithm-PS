#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

int n,k,tmp;
int arr[500001];
int arr2[500001];
stack<int> f;
stack<int> s;

void except_one_digit()
{
    int now=k;
    while(!s.empty())
    {
        tmp=s.top();
        //cout<<tmp<<" ";
        s.pop();
        if(!s.empty()&&tmp<s.top()&&now>0)
        {
            now--;
            if(f.size()>0)
            {
                tmp=f.top();
                f.pop();
                s.push(tmp);
            }
        }
        else
        {
            f.push(tmp);

        }
    }
}

int main()
{
    scanf("%d",&n);
    scanf("%d",&k);
    for(int i=0;i<n;i++) scanf("%1d",&arr[i]);
    for(int i=0;i<n;i++) s.push(arr[n-i-1]);
    except_one_digit();
    tmp=f.size();
    //cout<<"size : "<<tmp;
    for(int i=tmp-1;i>=0;i--) 
    {
        arr2[i]=f.top();
        f.pop();
    }
    for(int i=0;i<n-k;i++) printf("%d",arr2[i]);
    return 0;
}


#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, k; // k개 지움
    cin >> n >> k;
    stack<char> s;
    char temp;
    int cnt = 0;
    bool end = false;
    for(int i=0; i<n; i++){ // n-1 개를 넣는다.
        cin >> temp;
        while(!s.empty() && !end){
            if(cnt == k) end = true;
            else if(s.top() < temp){
                s.pop();
                cnt++;
            }else{
                s.push(temp);
                break;
            }
        }
        if(s.empty() || end) s.push(temp);    
    }
    vector<char> v;

    while(!s.empty()){
        v.push_back(s.top());
        s.pop();
    }
    cnt = 0;
    for(int i=v.size()-1; i>=0 && cnt < n - k; i--, cnt++) cout << v[i];
    return 0;
}