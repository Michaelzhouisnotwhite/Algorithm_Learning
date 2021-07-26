#include <iostream>
#include <vector>
using namespace std;
void solve(vector<int> &a, int low, int high, int &max1, int &max2)
{
    if (low == high)
    {
        max1 = a[low];
        max2 = -INFINITY;
    }
    else if (low == high - 1)
    {
        max1 = max(a[low], a[high]);
        max2 = min(a[low], a[high]);
    }
    else
    {
        int mid = (low + high) / 2;
        int lmax1, lmax2;
        solve(a, low, mid, lmax1, lmax2);
        int rmax1, rmax2;
        solve(a, mid + 1, high, rmax1, rmax2);
        if (lmax1 > rmax1)
        {
            max1 = lmax1;
            max2 = max(lmax2, rmax1);
        }
        else
        {
            max1 = rmax1;
            max2 = max(lmax1, rmax2);
        }
    }
}
int main()
{
    vector<int> a = {2, 5, 1, 4, 6, 3};
    int max1, max2;
    solve(a, 0, 5, max1, max2);
    for (auto i: a)
    {
        printf("%d ", i);
    }
    printf("\n");
    printf("max1: %d, max2: %d\n", max1, max2);
    return 0;
}