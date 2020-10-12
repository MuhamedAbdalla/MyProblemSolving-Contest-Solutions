#include <bits/stdc++.h>

using namespace std;

int main() {

	int n;
	cin >> n;
	vector<vector<long long>> v(n, vector<long long>(n));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(i & 1) {
				v[i][j] = (1ll << (i + j));
			}
		}
	}	

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cout << v[i][j] << ' ';
		}
		cout << endl;
	}

	int q;
	cin >> q;
	while(q--) {
		long long s;
		cin >> s;
		vector<int> v;
		for(int i = 0; i < 2*n-1; i++) {
			if(s & (1ll << i)) v.push_back(1);
			else v.push_back(0);
		}
		int r = 1, c = 1;
		cout << r << ' ' << c << endl;
		for(int i = 1; i < v.size(); i++) {
			if(v[i] == v[i-1]) c++;
			else r++;
			cout << r << ' ' << c << endl;
		}
	}

	return 0;
}
