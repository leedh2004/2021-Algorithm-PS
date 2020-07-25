#include <iostream>

using namespace std;

void f(int s, int e, int x){
	if(s == e){
		if(x) cout << "#";
		else cout << ".";
		return;
	}
	int len = e - s + 1;
	if(x <= len / 2){
		int m = (s + e) >> 1;
		f(s, m, x); f(m+1, e, 0);
	}else{
		int m = (s + e) >> 1;
		int xx = 1;
		while(xx * 2 <= x - xx * 2 && xx * 2 <= e-m) xx = xx * 2;
		if(x - xx > m - s + 1) xx = x - (m - s + 1);
		f(s, m, x - xx); f(m+1, e, xx);
	}
}

int f(int n){
	int ret = 1;
	for(; ret < n; ret <<= 1);
	return ret;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	f(1, f(n), n);
}