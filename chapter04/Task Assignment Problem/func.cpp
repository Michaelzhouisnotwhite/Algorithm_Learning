#include "func.h"

int n = 4;
int c[MAXN][MAXN] = {{9, 2, 7, 8}, {6, 4, 3, 7}, {5, 8, 1, 8}, {7, 6, 9, 4}};
vector<vector<int>> ps;
void Insert(vector<int> s, int i, vector<vector<int>> &ps1)
{
    vector<int> s1;
    for (int j = 0; j < i; j++)
    {
        s1 = s;
        auto it = s1.begin() + j;
        s1.insert(it, i);
        ps1.push_back(s1);
    }
}

/**
 * @brief 求1~n的所有全排列
 * 
 * @param n 
 */
void Perm(int n)
{
    vector<vector<int>>::iterator it;
    vector<int> s, s1;
    s.push_back(1); // 放入第一个元素
    ps.push_back(s);
    for (int i = 2; i <= n; i++)
    {
        vector<vector<int>> ps1;
        for (auto it = ps.begin(); it != ps.end(); ++it)
        {
            Insert(*it, i, ps1);
        }
        ps = ps1;
    }
}

/**
 * @brief 求任务分配最佳方案
 * 
 * @param n 任务个数
 * @param mini 最优方案ps索引
 * @param minc 最有方案的成本
 */
void Allocate(int n, int &mini, int &minc)
{
    Perm(n);                            //求出全排列ps
    for (int i = 0; i < ps.size(); i++) //求每个方案的成本
    {
        int cost = 0;
        for (int j = 0; j < ps[i].size(); j++)
            cost += c[j][ps[i][j] - 1];
        if (cost <= minc) //比较求最小成本的方案
        {
            minc = cost;
            mini = i;
        }
    }
}