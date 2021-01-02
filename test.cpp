#include <string>
#include <vector>
#include <iostream> 

using namespace std;

typedef struct Node{
    Node* next[26];
    int count = 0;
}Node;

Node* root = new Node();
vector<int> answer;
void insert(string &s, Node * node, int i){
    if (i == s.size()) {
        node->count++;
        return;
    }
    if (node->next[s[i]-'a'] == NULL)
        node->next[s[i]-'a'] = new Node();
    insert(s, node->next[s[i]-'a'], i+1);
}

void find(string &s, Node * node, int i, int order){
    cout << s << " " << s[i] << " " << order << endl;
    if (i == s.size()){
        answer[order] += node->count;
    }
    if(s[i] == '?'){
        for(int j=0; j<26; j++){
            if (node->next[j] != NULL)
                find(s, node->next[j], i+1, order);
        }
    }else{
        if(node->next[s[i]-'a'] != NULL)
            find(s, node->next[s[i]-'a'], i+1, order);
    }
}

vector<int> solution(vector<string> words, vector<string> queries) {
    answer = vector<int>(queries.size(), 0);
    for(int i=0; i<words.size(); i++){
        insert(words[i], root, 0);
    }
    for(int i=0; i<queries.size(); i++){
        find(queries[i], root, 0, i);
    }
    return answer;
}

int main(){
    cout << 'z'-'a' << endl;
    return 0;
    vector<string> words = {"frodo", "front", "frost", "frozen", "frame", "kakao"};
    vector<string> queries = {"fro??", "????o", "fr???", "fro???", "pro?"};
    answer = solution(words, queries);
    for(auto i : answer){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}