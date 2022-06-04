#include <iostream>
using namespace std;

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
    cout << "* Output: " << PaintFenceDynamic(2, 4) << endl;
}
