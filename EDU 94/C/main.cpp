#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("D.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        int x;
        string s;
        cin >> s >> x;
        int n = s.size();
        int cnt[n + 1];
        int out[n + 1];
        bool vis[n + 1];
        bool can = 1;
        fill(cnt, cnt + n, 0);
        fill(out, out + n, 0);
        fill(vis, vis + n, 0);
        for (int i = 0; i < n; i++) {
            int l = i - x, r = i + x;
            if(l >= 0 && r < n) {
                if (s[i] == '0') {
                    if ((out[l] != s[i] - '0' && vis[l]) || (out[r] != s[i] - '0' && vis[r])) {
                        can = 0;
                        break;
                    }
                    out[l] = (s[i] - '0');
                    vis[l] = 1;
                    out[r] = (s[i] - '0');
                    vis[r] = 1;
                }
                else {
                    cnt[l]++;
                    cnt[r]++;
                }
            }
            else if (l >= 0) {
                if (s[i] - '0' != out[l] && vis[l]) {
                    can = 0;
                    break;
                }
                out[l] = (s[i] - '0');
                vis[l] = 1;

            }
            else if (r < n){
                if (s[i] - '0' != out[r] && vis[r]) {
                    can = 0;
                    break;
                }
                out[r] = (s[i] - '0');
                vis[r] = 1;
            }
            else {
                if (s[i] != '0') {
                    can = 0;
                    break;
                }
                out[i] = 0;
                vis[i] = 1;
            }
        }
        if (!can) {
            cout << -1 << endl;
            continue;
        }
        for (int i = 0; i < n; i++) {
            if (cnt[i] > 0) {
                int l = i, r = i + 2 * x;
                if (s[l + x] == '0' || (l - x >= 0 && s[l - x] == '0')) {
                    if (s[r - x] == '0' || (r + x < n && s[r + x] == '0')) {
                        can = 0;
                        break;
                    }
                    else {
                        out[r] = 1;
                        cnt[l]--, cnt[r]--;
                    }
                }
                else {
                    cnt[l]--, cnt[r]--;
                    out[l] = 1;
                }
            }
        }
        if(!can) {
            cout << -1 << endl;
        }
        else {
            for (int i = 0; i < n; i++) {
                cout << out[i];
            }
            cout << endl;
        }
    }
    return 0;
}
