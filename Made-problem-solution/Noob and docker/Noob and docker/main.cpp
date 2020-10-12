#include <iostream>

using namespace std;

int main()
{
    int n;
    string s[10] = {
        "                  ##         .         ",
        "            ## ## ##        ==         ",
        "         ## ## ## ## ##    ===         ",
        "     /\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\\___/ ===       ",
        "~~~ {~~ ~~~~ ~~~ ~~~~ ~~~ ~ /  ===- ~~~",
        "     \\_______o           __/           ",
        "       \\     \\        __/              ",
        "        \\_____\\______/                 ",
    };
    cin >> n;
    for (int i = n; i < 8; i++) {
        cout << s[i] << endl;
    }
    for (int i = 0; i < n; i++) {
        cout << s[i] << endl;
    }
    return 0;
}
