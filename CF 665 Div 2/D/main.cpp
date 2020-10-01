#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 5;
const long long MOD = 1e9 + 7;
int all;
vector<int> edj[MAX], val;
vector<long long> rep;

void init(int n) {
    val.clear();
    rep.clear();
    for (int i = 0; i <= n; i++) {
        edj[i].clear();
    }
}

int dfs(int n, int pre) {
    int r = 1;
    for (auto i : edj[n]) {
        if (i == pre) continue;
        int ret = dfs(i, n);
        rep.push_back(1LL * ret * (all - ret));
        r += ret;
    }
    return r;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("input.txt","r",stdin);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        all = n;
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            edj[u].push_back(v);
            edj[v].push_back(u);
        }
        dfs(1, -1);
        int m;
        cin >> m;
        for (int i = 0; i < m; i++) {
            int a;
            cin >> a;
            val.push_back(a);
        }
        sort(val.begin(), val.end());
        sort(rep.begin(), rep.end());
        while(m > n - 1) {
            int v = val.back();
            val.pop_back();
            m--;
            rep.back() = (rep.back() * v) % MOD;
        }
        while(val.size() < n - 1) val.push_back(1);
        sort(val.begin(), val.end());
        long long res = 0;
        for (int i = 0; i < n - 1; i++) {
            res = (res + (rep[i] * val[i]) % MOD) % MOD;
        }
        cout << res << endl;
        init(n);
    }
    return 0;
}
