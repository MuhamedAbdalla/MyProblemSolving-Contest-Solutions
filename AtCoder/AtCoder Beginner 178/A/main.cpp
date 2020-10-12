#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << max(max(a * c, b * d), max(a * d, b * c)) << endl;
    return 0;
}




