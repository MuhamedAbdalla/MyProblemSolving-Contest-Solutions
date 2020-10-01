#include <bits/stdc++.h>

using namespace std;

int main() {

	int T;
	cin >> T;

	while(T--) {
		long long n;
		cin >> n;
		vector<long long> a(n+1), dp(n+2);
		for(int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		dp[1] = a[1];
		for(int i = 2; i <= n; i++) {
			dp[i] = max(dp[i-1], a[i]);
		}
		for(int i = 1; i <= n; i++) {
			dp[i] = dp[i] - a[i];
		}
		long long ans = 0, cur = 0;
		for(int i = n; i > 0; i--) {
			if(dp[i+1] < dp[i]) ans += dp[i] - dp[i+1];
		}
		cout << ans << '\n';
	}

	return 0;
}
