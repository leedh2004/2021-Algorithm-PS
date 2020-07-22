#include <iostream>
#include <queue>

using namespace std;
int ans[200001];
bool chk[200001];

int n, k, p;
bool flag = false;


bool makeChild(int parentIndex, int parentValue) {
    int childIndex = parentIndex * 2;
    queue<int> q;
    q.push(childIndex);
    q.push(childIndex+1);
    parentValue++;
    while(!q.empty()){
        int childIndex = q.front();
        q.pop();
        if (childIndex > n) break;
        ans[childIndex] = parentValue;
        if(parentValue > n) return false;
        chk[parentValue] = true;
        parentValue++;
        q.push(childIndex * 2);
        q.push(childIndex * 2 + 1);
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k >> p;
    ans[p] = k; // ans[5] = 3
    chk[k] = true; // chk[3] = true

    int parent = p / 2; // 2 
    int pk = k; // 5

    //부모 트리 만들기
    while(parent){
        ans[parent] = pk - 1;
        if(pk - 1 <= 0){
            cout << -1;
            return 0;
        }
        chk[pk - 1] = true;
        pk--;
        parent /= 2;
    }
    //자식 트리 만들기
    if (makeChild(p, k)){
        int tmp = 1;
        for(int i=1; i<=n; i++){
            if(ans[i]) cout << ans[i] << '\n';
            else{
                while(chk[tmp]){tmp++;}
                cout << tmp << '\n';
                chk[tmp] = 1;
            }
        }
    }else{
        cout << -1;
    }

    return 0;
}