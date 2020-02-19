#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

//이름,부모
map<string,int> m;

int parent[200010],cnt[200010];

int get_parent(int x)
{
    if(parent[x]==x) return x;
    return parent[x]=get_parent(parent[x]);
}
    

int union_parent(int a, int b)
{
    a= get_parent(a);
    b= get_parent(b);

    if (a != b) 
    {
		parent[a] = b;
		cnt[b] = cnt[b]+cnt[a];
	}
	return cnt[b];
}


int main()
{
    int t,n;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%d",&n);

        //값 초기화
        for(int i=0;i<200001;i++)
        {
            parent[i]=i;
            cnt[i]=1;
        }
        m.clear();
        int index=0;

        //간선 입력
        for(int j=0;j<n;j++)
        {
            char a[21], b[21];
			scanf("%s %s", &a, &b);
            if(m.find(a)==m.end()) m.insert({a,index++});
            if(m.find(b)==m.end()) m.insert({b,index++});
            printf("%d\n",union_parent(m[a],m[b]));
        }
    }
    return 0;
}

