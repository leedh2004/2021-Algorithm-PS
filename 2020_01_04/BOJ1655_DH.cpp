#include <iostream>
#include <queue>

using namespace std;
priority_queue<int, vector<int>, less<int> > max_heap;
priority_queue<int, vector<int>, greater<int> > min_heap;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    int minSize = 0;
    int maxSize = 0;
    for(int i=0; i<n; i++){
        int node;
        cin >> node;
        if(i == 0){ 
            max_heap.push(node);
            maxSize++;
        }
        else{
            if (max_heap.top() < node){
                min_heap.push(node);
                minSize++;
            }else{
                max_heap.push(node);
                maxSize++;
            }
            if(maxSize < minSize){
                max_heap.push(min_heap.top());
                min_heap.pop();
                maxSize++;
                minSize--;
            }
            else if( maxSize > minSize + 1){
                min_heap.push(max_heap.top());
                max_heap.pop();
                minSize++;
                maxSize--;
            }
        }
        cout << max_heap.top() << '\n';
    }

    return 0;
}