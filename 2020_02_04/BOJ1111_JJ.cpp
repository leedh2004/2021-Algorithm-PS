#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    bool flag=false;
    int a,b;
    for(int i=0;i<n;i++) cin>>v[i];
    if(n==1) //1개인경우 a,b 특정불가능
    {
        cout<<"A";
        return 0;
    }
    else if(n==2) //2개인경우 
    {
        if(v[0]==v[1])
        {
            cout<<v[0];
            return 0;
        }
        cout<<"A";
        return 0;
    }
    else
    {
        if(v[1]==v[0]) //맨앞2개가 같다면 a,b값과 관계없이 다음 결과도 같아야한다.
        {
            a=1;
            b=0;
        }
        else
        {
            a=(v[2]-v[1])/(v[1]-v[0]);
            b=v[1]-a*v[0];
        }
        for(int i=0;i<n-1;i++) //식에 모든 값 부합 여부 확인
        {
            if(v[i+1]!=(v[i]*a+b)) flag=true;
        }
        if(flag) cout<<'B';
        else cout<<v[n-1]*a+b;
    }
    return 0;
}