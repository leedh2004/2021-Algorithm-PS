#include <iostream>
using namespace std;

// s:start / e:end / x:채워야할 사람수
void f(int s, int e, int x){
    //printf("start:%d end:%d num:%d\n",s,e,x);
	if(s == e){
		if(x) cout << "#";
		else cout << ".";
		return;
	}
    //길이(들어갈 수 있는 사람의 수)
	int len = e - s + 1;


	if(x <= len / 2){
		int m = s + e >> 1;
        //문제 조건 - 무조건 왼쪽부터 채운다.
		f(s, m, x); f(m+1, e, 0);
	}else{
		int m = s + e >> 1;
		int xx = 1;
		while(xx * 2 <= x - xx * 2 && xx * 2 <= e-m) xx = xx * 2;
		if(x - xx > m - s + 1) xx = x - (m - s + 1);
		f(s, m, x - xx); f(m+1, e, xx);
	}
}

//n보다 같거나 큰 2의 제곱수 반환
int f(int n){
	int ret = 1;
	for(; ret < n; ret <<= 1);
	return ret;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
    printf("%d\n",f(n));
	f(1, f(n), n);
}