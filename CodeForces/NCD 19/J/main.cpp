#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int a[N + 5], cnt[N + 5];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("D.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        fill(cnt, cnt + n + 2, 0);
        for (int i = 0; i < m; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++) {
            int v;
            cin >> v;
            if (v == 0) {
                cnt[a[i]]++;
                cnt[a[i] + 1]--;
            }
            else if (abs(v) == n) {
                cnt[1]++;
                cnt[n + 1]--;
                cnt[a[i]]++;
                cnt[a[i] + 1]--;
            }
            else {
                if (v > 0) {
                    int to = a[i] + v - 1;
                    to %= n;
                    to++;
                    if (to <= a[i]) {
                        cnt[a[i]]++, cnt[n + 1]--;
                        cnt[1]++, cnt[to + 1]--;
                    }
                    else {
                        cnt[a[i]]++, cnt[to + 1]--;
                    }
                }
                else {
                    v %= n;
                    v += n;
                    v %= n;
                    int to = a[i] + v - 1;
                    to %= n;
                    to++;
                    if (to <= a[i]) {
                        cnt[to]++, cnt[a[i] + 1]--;
                    }
                    else {
                        cnt[1]++, cnt[a[i] + 1]--;
                        cnt[to]++, cnt[n + 1]--;
                    }
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            cnt[i] += cnt[i - 1];
        }
        int mx = -1, res = 0;
        for (int i = 1; i <= n; i++) {
            if (cnt[i] > mx) {
                mx = cnt[i];
                res = i;
            }
        }
        cout << res << " " << mx << endl;
    }
    return 0;
}
