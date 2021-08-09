#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> ps; // 存放幂集

/**
 * @brief 幂集迭代器
 * 
 * @param n 集合内元素个数
 */
void Pset(int n) // 求1-n的幂集
{
    vector<vector<int>> ps1;
    vector<vector<int>>::iterator it;
    vector<int> s;
    ps.push_back(s); // 加入空集

    for (int i = 1; i <=n ; i ++)
    {
        ps1 = ps;
        for (it = ps1.begin(); it != ps1.end(); ++it)
        {
            it->push_back(i);
        }
        for (it = ps1.begin(); it != ps1.end(); ++it)
        {
            ps.push_back(*it);
        }
    }
}

int main()
{
    Pset(3);
    return 0;
}