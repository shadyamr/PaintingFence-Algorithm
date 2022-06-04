#include <iostream>
using namespace std;

string s;
int n;
int ans;
void permute(int idx) {
    if (idx == n) {
        int cnt = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == s[i + 1]) {
                cnt++;
                if (cnt > 1)
                    break;
            }
            else {
                cnt = 0;
            }
        }
        if (cnt <= 1) {
            cout << s << endl;
            ans++;
        }
        return;
    }

    for (char ch : {'A', 'B', 'C'}) {
        s[idx] = ch;
        permute(idx + 1);
    }
}


int main() {
    cin >> n;
    s = "ABCD";
    permute(0);
    cout << ans;

    return 0;
}
