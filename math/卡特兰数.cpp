#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<unordered_map> 
#include<deque>
#include<cstring>
using namespace std;

long long dp[1005] = { 0 };

int main() {
	int n;
	cin >> n;
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= n; ++i) {
		dp[i] = dp[i - 1] * (4 * i - 2) / (i + 1);
	}
	cout << dp[n] << endl;
}
