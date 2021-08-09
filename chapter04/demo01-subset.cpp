#include <iostream>
#include <vector>
using namespace std;
void inc(vector<int> &b, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (b[i])
        {
            b[i] = 0;
        }
        else
        {
            b[i] = 1;
            break;
        }
    }
}
void PSet(vector<int> a, vector<int> &b, int n)
{
    int i, k;
    int pw = (int)pow(2, n);
    printf("1~%d的幂集:\n", n);

    for (i = 0; i < pw; i++)
    {
        printf("{ ");
        for (k = 0; k < n; k++)
        {
            if (b[k])
            {
                printf("%d ", a[k]);
            }
        }
        printf("} ");
        inc(b, n);
    }
    printf("\n");
}
int main()
{
    vector<int> a = {1, 2, 3};
    vector<int> b = {0, 0, 0};
    PSet(a, b, 3);
    return 0;
}