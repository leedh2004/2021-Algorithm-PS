#include<cstdio>
#include<cstring>
#include<cstdlib>

using namespace std;

struct Trie {
    bool finish;    //끝나는 지점을 표시해줌
    Trie* next[11];    //26가지 알파벳에 대한 트라이

    //생성자
    Trie() : finish(false) {
        memset(next, 0, sizeof(next));
    }

    //소멸자
    ~Trie() {
        for (int i = 0; i < 11; i++)
            if (next[i]) delete next[i];
    }

    bool insert(const char* key) {
        if (*key == '\0'){
            finish = true;    //문자열이 끝나는 지점일 경우# 표시
            return true;
        }

        else {
            int curr = *key - '0';

            if(next[curr]!=NULL){
                if( next[curr]->finish || *(key+1) == '\0') return false;
            }else{
                next[curr] = new Trie(); 
            }

            // 다음 문자 삽입
            return next[curr]->insert(key + 1);   
        }
    }
};

int n; 
char callbook[10000][11];

int main(){
    int t; scanf("%d",&t);
    while(t--)
    {
        memset(callbook,0,sizeof(callbook));
        Trie *root = new Trie();
        bool flag = true;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%s",callbook[i]);
            if(flag && !root->insert(callbook[i])) flag = false;
        }
        printf("%s",(flag? "YES\n": "NO\n"));
        delete(root);
    }
    return 0;
}