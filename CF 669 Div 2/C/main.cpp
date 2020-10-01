#include <bits/stdc++.h>

using namespace std;

int get(int l, int r) {
    cout << "? " << l << " " << r << endl;
    int ret;
    cin >> ret;
    return ret;
}

int main() {
    cout.flush();
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i <= n; i++) {
        v.push_back(-1);
    }
    int l = 1, r = 2;
    while (r <= n) {
        int lr = get(l, r);
        int rl = get(r, l);
        if (lr > rl) {
            v[l] = lr;
            l = r;
            r++;
        }
        else {
            v[r] = rl;
            r++;
        }
    }
    v[l] = n;
    cout << "! ";
    for (int i = 1; i <= n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}


