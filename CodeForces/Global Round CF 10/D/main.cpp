#include <bits/stdc++.h>

using namespace std;

int main() {

	int T;
	cin >> T;

	while(T--) {
		int n;
		string s;
		cin >> n >> s;
		vector<int> v;
		int cur = 1;
		for(int i = 1; i < n; i++) {
			if(s[i] == s[i-1]) {
				cur++;
			}
			else {
				v.push_back(cur);
				cur = 1;
			}
		}
		v.push_back(cur);
		if(v.size() == 1) {
			int x = v[0]/3;
			if(v[0] % 3 != 0) x++;
			cout << x << '\n';
		}
		else {
			if(s[0] == s[n-1]) {
				v[0] += v.back();
				v.pop_back();
			}
			int ans = 0;
			for(auto i : v) ans += (i/3);
			cout << ans << '\n';
		}
	}

	return 0;
}
