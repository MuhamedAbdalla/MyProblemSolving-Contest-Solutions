#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("D.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n + 1];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        long long res = 0;
        long long Lcnt[n + 1], Rcnt[n + 1];
        for (int i = 0; i < n; i++) {
            fill(Lcnt, Lcnt + n + 1, 0);
            fill(Rcnt, Rcnt + n + 1, 0);
            for (int j = i + 2; j < n; j++) Rcnt[a[j]]++;
            long long sum = 0;
            for (int j = i + 1; j < n; j++) {
                if (a[i] == a[j])
                    res += sum;
                if (j + 1 < n) {
                    sum -= Lcnt[a[j + 1]];
                    Rcnt[a[j + 1]]--;
                }
                sum += Rcnt[a[j]];
                Lcnt[a[j]]++;
            }
        }
        cout << res << "\n";
    }
    return 0;
}
