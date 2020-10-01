#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("D.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;
        if (x > y) {
            cout << "Bashar" << endl;
        }
        else if (y > x) {
            cout << "Hamada" << endl;
        }
        else {
            cout << "Iskandar" << endl;
        }
    }
    return 0;
}
