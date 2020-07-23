#include <iostream>
using namespace std;


bool ans[4000000];
int flag;

int findLargeNum(int number){
    int ret = 1;
    while(ret < number){
        ret *= 2;
    }
    return ret - 1;
}

void solve(int start, int end, int number){ // ans[startIdx ~ range]에 number 명이 있는 경우를 처리.
    //cout << start << " " << end << " " << number << endl;
    if(number == 0) return;
    int range = end - start + 1; // 8, 15 => 8
    int mid = start + range / 2; // mid => 12
    
    if(range == number){
        for(int i=start; i<=end; i++){
            cout << i;
            ans[i] = 1;
        }
        return;
    }

    if(number > range / 2){ // 이 경우가 잘못된듯.. 규칙이 뭘까?
        if(number % 2 == 0){
            solve(start, mid-1, number / 2); 
            solve(mid, end, number / 2);
        }else{
            solve(start, mid-1, number / 2 + 1);
            solve(mid, end, number / 2);
        }
    }else{
        solve(start, mid-1, number);
        solve(mid, end, 0);
    }

}

int main(){
    int number;
    cin >> number;
    //cout << findLargeNum(number);
    int l = findLargeNum(number);
    solve(0, l, number);
    for(int i=0; i<=l; i++){
        if(ans[i]) cout << '#';
        else cout << '.';
    }
    return 0;
}