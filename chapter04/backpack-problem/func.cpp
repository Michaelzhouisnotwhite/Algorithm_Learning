#include "func.h"

vector<vector<int>> ps; // 存放幂集
/**
 * @brief 幂集迭代器
 * 
 * @param n 集合内元素个数
 */
void Pset(int n) // 求1-n的幂集
{
    vector<int> s;
    ps.push_back(s); // 加入空集

    for (int i = 1; i <= n; i++)
    {
        vector<vector<int>> ps1(ps);
        for (auto it = ps1.begin(); it != ps1.end(); ++it)
        {
            it->push_back(i);
        }
        for (auto it = ps1.begin(); it != ps1.end(); ++it)
        {
            ps.push_back(*it);
        }
    }
}

/**
 * @brief 求最佳方案
 * 
 * @param w 每个物品的重量
 * @param v 每个物品的价值
 * @param W 限定最大容量
 */
void Knap(int *w, int *v, int W)
{
    int count = 0;  // 方案编号
    int sumw, sumv; // sum weight & sum value
    int maxi = 0;
    int maxsumw = 0;
    int maxsumv = 0;
    printf_s("序号\t选中物品\t总重量\t总价值\t能否装入\n");

    for (auto it = ps.begin(); it != ps.end(); ++it)
    {
        printf("%d\t", count + 1);
        sumv = sumw = 0;
        printf("{");
        for (auto sit = it->begin(); sit != (*it).end(); ++sit)
        {
            printf("%d ", *sit);
            sumw += w[*sit - 1];
            sumv += v[*sit - 1];
        }
        printf("}\t\t%d\t%d\t", sumw, sumv);
        if (sumw <= W)
        {
            printf("能\n");
            if (sumv > maxsumv)
            {
                maxsumw = sumw;
                maxsumv = sumv;
                maxi = count;
            }
        }
        else
            printf("否\n");

        count++;
    }
    printf("最佳方案：");
    printf("选中物品");
    printf("{");
    for (auto sit = ps[maxi].begin(); sit != ps[maxi].end(); ++sit)
    {
        printf("%d ", *sit);
    }
    printf("}, ");
    printf("总重量：%d, 总价值：%d\n", maxsumw, maxsumv);
}