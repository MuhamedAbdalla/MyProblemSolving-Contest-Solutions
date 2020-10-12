#include <bits/stdc++.h>

using namespace std;

double EPS = 1e-9;

void check(double x, double y) {
    if (fabs(x - y) <= EPS) {
        cout << "Lazy" << endl;
    }
    else if (x > y) {
        cout << "HaHa" << endl;
    }
    else {
        cout << "Congrats" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("D.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a == 0 || c == 0) {
            check(double(a), double(c));
        }
        else {
            double x = double(b) * log(double(a));
            double y = double(d) * log(double(c));
            check(x, y);
        }
    }
    return 0;
}
