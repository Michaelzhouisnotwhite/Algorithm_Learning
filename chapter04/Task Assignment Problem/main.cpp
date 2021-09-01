#include "func.h"
#include <iostream>
int main()
{
    int mincost = INT_FAST32_MAX, mini;
    int n = 4;
    //mincost为最小成本,mini为ps中最优方案编号
    Allocate(n, mini, mincost);
    printf("最优方案:\n");
    for (int k = 0; k < ps[mini].size(); k++)
        printf(" 第%d个人安排任务%d\n", k + 1, ps[mini][k]);
    printf(" 总成本=%d\n", mincost);
    return 0;
}