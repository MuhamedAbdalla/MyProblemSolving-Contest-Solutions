#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#define ll long long
#define ld double
#define oo 2e18
#define OS tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define rnd mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

const int N = 1e2 + 5;
int n, arr[N];

void rec() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int ans = 0;
    for (int i = 1; i < n - 1; i++) {
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) ans++;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    int c = 1;
    while (t--) {
        cout << "Case #" << c << ": ";
        rec();
        c++;
    }
    return 0;
}
