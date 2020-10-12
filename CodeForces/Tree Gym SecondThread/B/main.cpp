#include <bits/stdc++.h>

using namespace std;

const int MAX = 3e5 + 5, LG = 20;
int dp[MAX][LG], dep[MAX];
int mx, vert = 1;
vector<int> e[MAX];

void init() {
    memset(dp, -1, sizeof(dp));
    fill(dep, dep + MAX, 0);
}

void dfs(int n, int pre, int lvl) {
    if (lvl > mx) {
        mx = lvl;
        vert = n;
    }
    dp[n][0] = pre;
    for (auto i : e[n]) {
        if (pre != i) {
            dep[i] = dep[n] + 1;
            dfs(i, n, lvl + 1);
        }
    }
}

int all;

void initLCA() {
    for (int j = 1; j < LG; j++)
        for (int i = 1; i <= all; i++)
            if (dp[i][j - 1] != -1)
                dp[i][j] = dp[dp[i][j - 1]][j - 1];
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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("D.txt", "r", stdin);
    int n;
    cin >> n;
    all = n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    vector<int> v;
    dfs(1, -1, 0);
    v.push_back(vert);
    mx = 0;
    dfs(vert, -1, 0);
    v.push_back(vert);
    v.push_back(mx);
    init();
    dfs(1, -1, 0);
    initLCA();
    for (int i = 1; i <= n; i++) {
        mx = 0;
        int lc = LCA(i, v[0]);
        mx = max(mx, dep[i] + dep[v[0]] - 2 * dep[lc]);
        lc = LCA(i, v[1]);
        mx = max(mx, dep[i] + dep[v[1]] - 2 * dep[lc]);
        cout << max(++mx, v[2]) << endl;
    }
    return 0;
}

