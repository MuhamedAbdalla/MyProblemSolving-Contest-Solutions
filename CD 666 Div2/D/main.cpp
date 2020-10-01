#include <bits/stdc++.h>

using namespace std;

priority_queue<int> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("D.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            v.push(a);
        }
        bool cur = 1;
        int p1 = 0, p2 = 0;
        if (v.size() % 2) v.push(0);
        while (v.size()) {
            p1 = v.top();
            v.pop();
            if (!p1) {
                cur = 1;
                break;
            }
            p2 = v.top();
            v.pop();
            if (!p2) {
                cur = 0;
                break;
            }
            p1--, p2--;
            v.push(p1);
            v.push(p2);
        }
        if (!cur) {
            cout << "T" << endl;
        }
        else {
            cout << "HL" << endl;
        }
    }
    return 0;
}
