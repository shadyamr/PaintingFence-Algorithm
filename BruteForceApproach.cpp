#include <iostream>
using namespace std;

string s;
int ans;

void PaintFenceBF(int idx, int n)
{
    if (idx == n) {
        int cnt = 0;
        for (int i = 0; i < n - 1; ++i)
        {
            if (s[i] == s[i + 1])
            {
                cnt++;
                if (cnt > 1)
                    break;
            }
            else
            {
                cnt = 0;
            }
        }
        if (cnt <= 1)
        {
            cout << s << endl;
            ans++;
        }
        return;
    }

    for (char ch : {'A', 'B', 'C'})
    {
        s[idx] = ch;
        PaintFenceBF(idx + 1, n);
    }
}


int main()
{
    int n;
    cin >> n;
    s = "ABCD";
    PaintFenceBF(0, n);
    cout << ans;

    return 0;
