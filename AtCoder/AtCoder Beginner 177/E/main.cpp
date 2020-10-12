#include <bits/stdc++.h>

using namespace std;

map<int, int> p;

void PF(int n) {
    set<int> s;
	while (n % 2 == 0) {
        s.insert(2);
		n = n / 2;
	}

	for (int i = 3; i <= sqrt(n); i = i + 2) {
		while (n % i == 0) {
			n = n / i;
            s.insert(i);
		}
	}

	if (n > 2)
        s.insert(n);
    for (auto i : s) {
        p[i]++;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >> n;
    int gc = 0;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        PF(v);
        gc = __gcd(gc, v);
    }
    bool fail = 0;
    for (auto i : p) {
        if (i.second > 1) {
            fail = 1;
            break;
        }
    }
    if (!fail) {
        cout << "pairwise coprime" << endl;
    }
    else if (gc == 1) {
        cout << "setwise coprime" << endl;
    }
    else {
        cout << "not coprime" << endl;
    }
    return 0;
}

