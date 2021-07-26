#include <iostream>
int BinSearch(int *a, int low, int high, int k)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        if (a[mid] == k)
        {
            return mid;
        }
        if (k < a[mid])
        {
            return BinSearch(a, low, mid - 1, k);
        }
        else
        {
            return BinSearch(a, mid + 1, high, k);
        }
    }
}
int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    printf("%d", BinSearch(a, 0, 8, 4));
    return 0;
}