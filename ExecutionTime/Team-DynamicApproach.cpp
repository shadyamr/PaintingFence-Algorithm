/* Execution Time / Complexity by our team. */
#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
using namespace std;
using namespace std::chrono;
int PaintFenceDynamic(int NumberOfPosts, int NumberOfColors)
{
    if (NumberOfPosts == 0)
    {
        return 0;
    }
    if (NumberOfPosts == 1)
    {
        return NumberOfPosts;
    }
    int same = NumberOfColors, diff = NumberOfColors * (NumberOfColors - 1);
    for (int i = 3; i <= NumberOfPosts; i++)
    {
        int PrevDiff = diff;
        diff = (same + diff) * (NumberOfColors - 1);
        same = PrevDiff * 1;
    }
    return same + diff;
}

int main()
{
    vector<int> values(10000);
    auto f = []() -> int { return rand() % 10000; };
    generate(values.begin(), values.end(), f);
    auto start = high_resolution_clock::now();
    cout << "* Output: " << PaintFenceDynamic(2, 4) << endl;
    sort(values.begin(), values.end());
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << duration.count() << "ms" << endl;
}
