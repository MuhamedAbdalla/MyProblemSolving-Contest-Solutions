#include <bits/stdc++.h>

using namespace std;

const int MAX = 3e5 + 5, LG = 21;
int dp[MAX][LG], val[MAX][LG], dep[MAX];
vector<pair<int, int>> e[MAX];

void init() {
    memset(dp, -1, sizeof(dp));
    fill(dep, dep + MAX, 0);
    for (int i = 0; i < MAX; i++)
        fill(val[i], val[i] + LG, 2e9);
}

void dfs(int n, int pre, int cost) {
    dp[n][0] = pre;
    val[n][0] = cost;
    for (auto i : e[n]) {
        if (pre != i.first) {
            dep[i.first] = dep[n] + 1;
            dfs(i.first, n, i.second);
        }
    }
}

int all;

void initLCA() {
    for (int j = 1; j < LG; j++)
        for (int i = 1; i <= all; i++)
            if (dp[i][j - 1] != -1)
                dp[i][j] = dp[dp[i][j - 1]][j - 1], val[i][j] = min(val[i][j - 1], val[dp[i][j - 1]][j - 1]);
}

int LCA(int a, int b) {
    if (dep[a] > dep[b])
        swap(a, b);

    for (int i = LG - 1; i >= 0; i--)
        if (dep[b] - (1 << i) >= dep[a])
            b = dp[b][i];

    if (a == b)
        return a;

    for (int i = LG - 1; i >= 0; i--)
        if (dp[a][i] != -1 && dp[b][i] != -1 && dp[b][i] != dp[a][i])
            b = dp[b][i], a = dp[a][i];

    return dp[a][0];
}

int liftUp(int &n, int c) {
    int mn = 2e9;
    for (int i = LG - 1; i >= 0; i--)
        if (dp[n][i] != -1 && c - (1 << i) >= 0)
            mn = min(mn, val[n][i]), n = dp[n][i], c -= (1 << i);
    return mn;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("D.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    all = n;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    init();
    dfs(1, 1, 0);
    initLCA();
    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        int lc = LCA(a, b);
        int toA = dep[a] - dep[lc];
        int toB = dep[b] - dep[lc];
        int c1 = liftUp(a, toA);
        int c2 = liftUp(b, toB);
        c1 = min(c1, c2);
        if (c1 == 2e9) {
            cout << 0 << endl;
        }
        else {
            cout << c1 << endl;
        }
    }
    return 0;
}


