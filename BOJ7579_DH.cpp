// DP
#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

struct my {
	int b; // byte
	int c; // cost
};

vector<my> v;
int n, m;
int dp[101][10001]; // dp[cur][cost] cost만큼 앱을 닫았을 때 최대 byte 값

int go(int cur, int cost) {
	
	int& ret = dp[cur][cost];
	if (ret != -1) return ret;

	if (cur == n) return 0;

	ret = go(cur + 1, cost); // 앱을 비활성화 하지 않음
	if (cost - v[cur].c >= 0)
		ret = max(ret, go(cur + 1, cost - v[cur].c) + v[cur].b);

	return ret;
}


int main() {
	cin >> n >> m;
	v.resize(n); // first 사용중인 메모리, second 비활성화 소모비용
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; i++)
		cin >> v[i].b;
	for (int i = 0; i < n; i++)
		cin >> v[i].c;
	for (int i = 0; i <= 10000; i++) {
		if (go(0, i) >= m) {
			cout << i;
			break;
		}
	}
	return 0;
}
