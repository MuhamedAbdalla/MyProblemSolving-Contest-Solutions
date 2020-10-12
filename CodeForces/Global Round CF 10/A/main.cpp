#include <bits/stdc++.h>

using namespace std;

int main() {

	int T;
	cin >> T;

	while(T--) {
		int n;
		long long k;
		cin >> n >> k;
		vector<long long> a(n);
		long long mx = -1e18, mx2 = -1e18;
		for(int i = 0; i < n; i++) cin >> a[i], mx = max(mx, a[i]);
		for(int i = 0; i < n; i++) a[i] = mx - a[i], mx2 = max(mx2, a[i]);
		vector<long long> b(n);
		for(int i = 0; i < n; i++) b[i] = mx2 - a[i];
		if(k & 1) {
			for(auto i  : a) cout << i << ' ';
		}
		else {
			for(auto i : b) cout << i << ' ';
		}
		cout << '\n'; 
	}

	return 0;
}
