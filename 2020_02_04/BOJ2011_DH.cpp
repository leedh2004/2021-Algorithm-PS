#include <iostream>
#include <string>

#define MOD 1000000
using namespace std;
int dp[5002];

int main(){
	string s;
	cin >> s;
	int len = s.length();
	s = ' ' + s; 
	dp[0] = 1;
	if( (s[1] - '0') != 0) dp[1] = 1;
	for(int i=2; i<=len; i++){
		if(s[i] - '0' > 0) dp[i] += dp[i-1];
		int val = (s[i-1] - '0') * 10 + (s[i] - '0');
		if ( 10 <= val && val <= 26)
			dp[i] += dp[i-2];
		dp[i] %= MOD;
	}
	cout << dp[len];
	return 0;
}