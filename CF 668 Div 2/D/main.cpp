#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int dis[N];
int mx, node;
vector<int> v[N];

void init(int n) {
    for (int i = 0; i <= n + 1; i++) v[i].clear();
    fill(dis, dis + n + 1, 0);
    mx = 0, node = 1;
}

void dfs(int n, int pre) {
    if (dis[n] >= mx) {
        mx = dis[n];
        node = n;
    }
    for (auto i : v[n]) {
        if (i != pre) {
            dis[i] = dis[n] + 1;
            dfs(i, n);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("D.txt", "r", stdin);
    int t;
    cin >> t;
    int n, a, b, da, db;
    while (t--) {
        cin >> n >> a >> b >> da >> db;
        for (int i = 0; i < n - 1; i++) {
            int u, vv;
            cin >> u >> vv;
            v[u].push_back(vv);
            v[vv].push_back(u);
        }
        if (2 * da >= db) {
            cout << "Alice" << endl;
            init(n);
            continue;
        }
        dfs(a, -1);
        if (dis[b] <= da) {
            cout << "Alice" << endl;
            init(n);
            continue;
        }
        mx = 0;
        fill(dis, dis + n + 1, 0);
        dfs(node, -1);
        if (mx <= 2 * da) {
            cout << "Alice" << endl;
            init(n);
            continue;
        }
        cout << "Bob" << endl;
        init(n);
    }
    return 0;
}
