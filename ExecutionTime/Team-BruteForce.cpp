#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
using namespace std;
using namespace std::chrono;
string s;
int ans;

void permute(int idx, int n) {
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
        permute(idx + 1, n);
    }
}


int main()
{
    int n = 4;
    s = "ABCD";
    permute(0, n);
    vector<int> values(10000);
    auto f = []() -> int { return rand() % 10000; };
    generate(values.begin(), values.end(), f);
    auto start = high_resolution_clock::now();
    cout << ans << endl;
    sort(values.begin(), values.end());
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << duration.count() << "ms" << endl;
    return 0;
}
