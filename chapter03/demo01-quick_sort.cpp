#include <iostream>

int Partition(int a[], int s, int t) //划分算法
{
    int i = s, j = t;
    int tmp = a[s];
    while (i!= j)
    {
        while (j > i && a[j] >= tmp)
        {
            j--;
        }
        a[i] = a[j];
        while (i < j && a[i] <= tmp)
        {
            i++;
        }
        a[j] = a[i];
    }
    a[i] = tmp;
    return i;
}
void QuickSort(int a[], int s, int t)
{
    if ( s < t)
    {
        int i = Partition(a, s, t);
        QuickSort(a, s, i - 1);
        QuickSort(a, i+1, t);
    }
}
int main()
{
    int a[] = {2, 5, 1, 7, 10, 6, 9, 4, 3, 8};
    std::cout << "before:";
    for (auto i : a)
    {
        std::cout << i << " ";
    }
    std::cout.put('\n');
    QuickSort(a, 0, 9);
    std::cout << "after:";
    for (auto i : a)
    {
        std::cout << i << " ";
    }
    std::cout.put('\n');
    return 0;
}