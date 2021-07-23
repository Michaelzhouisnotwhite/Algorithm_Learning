#include <iostream>
using namespace std;
void Hanoi(int n, char x, char y, char z)
{
    if (n == 1)
    {
        printf("将盘片%d从%c搬到%c\n", n, x, z);
    }
    else
    {
        Hanoi(n - 1, x, z, y);
        printf("将盘片%d从%c搬到%c\n", n, x, z);
        Hanoi(n - 1, y, x, z);
    }
}
int main()
{
    Hanoi(3, 'x', 'y', 'z');
    return 0;
}