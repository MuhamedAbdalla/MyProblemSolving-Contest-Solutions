#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int par[N], sz[N];

void init(int n) {
    iota(par, par + N, 0);
    fill(sz, sz + N, 1);
}

int get(int idx) {
    while (idx != par[idx]) {
        par[idx] = par[par[idx]], idx = par[idx];
    }
    return idx;
}

void Union(int a, int b) {
    int i = get(a), j = get(b);
    if (i != j) {
        if (sz[i] >= sz[j]) {
            par[j] = i, sz[i] += sz[j];
            sz[j] = 0;
        }
        else {
            par[i] = j, sz[j] += sz[i];
            sz[i] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    init(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        Union(u, v);
    }
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        mx = max(mx, sz[i]);
    }
    cout << mx << endl;
    return 0;
}




