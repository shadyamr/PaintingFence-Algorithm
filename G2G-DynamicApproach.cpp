#include <iostream>
using namespace std;
long countWays(int n, int k)
{
    long total = k;
    int mod = 1000000007;
    int same = 0, diff = k;
    for (int i = 2; i <= n; i++) {
        same = diff;
        diff = total * (k - 1);
        diff = diff % mod;
        total = (same + diff) % mod;
    }
    return total;
}
int main()
{
    int n =4 , k = 5;
    cout << countWays(n, k) << endl;
    return 0;
}
