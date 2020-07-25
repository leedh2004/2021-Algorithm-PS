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

// 8 4, 4
// 9 5, 4
// 9 - tmp 
// 10 

void solve(int start, int end, int number){ // ans[startIdx ~ range]에 number 명이 있는 경우를 처리.
    int range = end - start + 1; // 8, 15 => 8
    int mid = start + range / 2; // mid => 12
    cout << start << " " << end << " " << number << endl;
    if(start == end){
        if(number) cout << '#';
        else cout << '.';
        return;
    }    

    if(number > range / 2){ // 이 경우가 잘못된듯.. 규칙이 뭘까?
        int tmp = 1;
        while(number - tmp >= tmp) tmp *= 2;
        //tmp /= 2;
        cout << tmp << endl;
        exit(0);
        solve(start, mid-1, tmp);
        solve(mid, end, number - tmp);
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
    return 0;
}