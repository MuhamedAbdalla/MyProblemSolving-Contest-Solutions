#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("D.txt", "r", stdin);
    long long n;
    cin >> n;
    long long a[n + 1];
    for (int i = 0; i < n; i++) cin >> a[i];
    if (n == 1) {
        cout << n << " " << n << endl;
        cout << 0 << endl;
        cout << n << " " << n << endl;
        cout << 0 << endl;
        cout << n << " " << n << endl;
        cout << -a[n - 1] << endl;
        return 0;
    }
    cout << 1 << " " << n << endl;
    for (int i = 0; i < n; i++) {
        cout << -a[i] * n << " ";
    }
    cout << endl;
    cout << 1 << " " << n - 1 << endl;
    for (int i = 0; i + 1 < n; i++) {
        cout << a[i] * (n - 1) << " ";
    }
    cout << endl;
    cout << n << " " << n << endl;
    cout << a[n - 1] * (n - 1);
    cout << endl;
    return 0;
}
