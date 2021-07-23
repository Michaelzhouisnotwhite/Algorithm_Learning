#include <iostream>
#include <vector>
using namespace std;

void Merge(vector<int> &a, int low, int mid, int high)
{
    int *tmpa;
    int i = low;
    int j = mid + 1;
    int k = 0;
    tmpa = (int *)malloc((high - low + 1) * sizeof(int));

    while (i <= mid && j <= high)
    {
        if (a[i] <= a[j])
        {
            tmpa[k] = a[i];
            i++;
            k++;
        }
        else
        {
            tmpa[k] = a[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        tmpa[k] = a[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        tmpa[k] = a[j];
        j++;
        k++;
    }
    for (k = 0, i = low; i <= high; k++, i++)
    {
        a[i] = tmpa[k];
    }
    free(tmpa);
}

void MergePass(vector<int> &a, int length, int n)
{
    int i;
    for (i = 0; i + 2 * length - 1 < n; i = i + 2 * length)
    {
        Merge(a, i, i + length - 1, i + 2 * length - 1);
    }
    if (i + length - 1 < n)
    {
        Merge(a, i, i + length - 1, n - 1);
    }
}

void MergeSort(vector<int> &a, int n)
{
    int length;
    for (length = 1; length < n; length = 2 * length)
    {
        MergePass(a, length, n);
    }
}
int main()
{
    vector<int> a = {2, 5, 1, 7, 10, 6, 9, 4, 3, 8};
    cout << "before:" << endl;
    for (auto aa:a)
    {
        cout << aa << " ";
    }
    cout << endl;
    MergeSort(a, 10);
    cout << "after:" << endl;
    for (auto aa:a)
    {
        cout << aa << " ";
    }
    cout << endl;
    return 0;
}