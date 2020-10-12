#include <bits/stdc++.h>

using namespace std;

const int MAX = 3e5 + 5;
int mx, vert = 1;
vector<int> e[MAX];

void dfs(int n, int pre, int dep) {
    if (dep > mx) {
        mx = dep;
        vert = n;
    }
    for (auto i : e[n]) {
        if (pre != i) {
            dfs(i, n, dep + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, -1, 0);
    dfs(vert, -1, 0);
    cout << 3 * mx << endl;
    return 0;
}

