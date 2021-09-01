#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> ps;
/**
 * @brief 在集合的各个元素中插入元素i
 * 
 * @param s 
 * @param i 
 * @param ps1 新的集合添加的地方
 */
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
        for (auto it = ps.begin(); it!= ps.end(); ++it)
        {
            Insert(*it, i, ps1);
        }
        ps = ps1;
    }
}

int main()
{
    Perm(3);
    return 0;
}