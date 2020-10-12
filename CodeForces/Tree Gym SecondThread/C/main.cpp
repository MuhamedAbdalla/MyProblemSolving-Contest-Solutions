#include <bits/stdc++.h>

using namespace std;

const int MAX = 3e5 + 5, LG = 21;
int dp[MAX][LG], dep[MAX];
vector<int> e[MAX];

void init() {
    memset(dp, -1, sizeof(dp));
    fill(dep, dep + MAX, 0);
}

void dfs(int n, int pre) {
    dp[n][0] = pre;
    for (auto i : e[n]) {
        if (pre != i) {
            dep[i] = dep[n] + 1;
            dfs(i, n);
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

void liftUp(int &n, int c) {
    for (int i = LG - 1; i >= 0; i--)
        if (dp[n][i] != -1 && c - (1 << i) >= 0)
            n = dp[n][i], c -= (1 << i);
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
    init();
    dfs(1, 1);
    initLCA();
    int q;
    cin >> q;
    while (q--) {
        int a, b, c;
        cin >> a >> b >> c;
        int lc = LCA(a, b);
        if (dep[a] + dep[b] - 2 * dep[lc] <= c) {
            cout << b << endl;
        }
        else {
            int toA = dep[a] - dep[lc], toB = dep[b] - dep[lc];
            if (toA >= c) {
                liftUp(a, c);
                cout << a << endl;
            }
            else {
                c -= toA;
                c = toB - c;
                liftUp(b, c);
                cout << b << endl;
            }
        }
    }
    return 0;
}

