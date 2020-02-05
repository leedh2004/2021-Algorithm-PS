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