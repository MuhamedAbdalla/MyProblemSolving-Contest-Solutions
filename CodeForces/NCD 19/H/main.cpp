#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int t, n, m, q, par[N];

void init() {
    for(int i = 1; i <= n; i ++)
        par[i] = i;
}

int get(int x) {
    if(par[x] != x) par[x] = get(par[x]);
    return par[x];
}

void Uni(int x, int y) {
    int xr = get(x);
    int yr = get(y);
    if(xr != yr) {
        par[xr] = yr;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("D.txt", "r", stdin);
    cin >> t;
    while (t--) {
    	cin >> n >> m >> q;
    	init();
    	for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            Uni(u, v);
    	}
    	string s = "";
        while (q--) {
            int a, b;
            cin >> a >> b;
            if (get(a) == get(b)) s += '1';
            else s += '0';
        }
        cout << s << endl;
    }
    return 0;
}
