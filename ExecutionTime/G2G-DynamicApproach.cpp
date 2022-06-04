#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
using namespace std;
using namespace std::chrono;

long countWays(int n, int k)
{
    long total = k;
    int mod = 1000000007, same = 0, diff = k;

    for (int i = 2; i <= n; i++)
    {
        same = diff;

        diff = total * (k - 1);
        diff = diff % mod;

        total = (same + diff) % mod;
    }

    return total;
}

int main()
{
    int n = 2, k = 4;
    vector<int> values(10000);
    auto f = []() -> int { return rand() % 10000; };
    generate(values.begin(), values.end(), f);
    auto start = high_resolution_clock::now();
    cout << "Output: " << countWays(n, k) << endl;
    sort(values.begin(), values.end());
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << duration.count() << "ms" << endl;
    return 0;
}
