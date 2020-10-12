#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    string s;
    cin >> s;
    if (s.back() == 's') {
        s.push_back('e');
        s.push_back('s');
    }
    else {
        s.push_back('s');
    }
    cout << s << endl;
    return 0;
}




