#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution
{
  public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
    {
        intSet leastNumbers; //leastNumbers用于存储k个元素
        vector<int> result;
        if (k < 1 || (input.size()) < (unsigned long)k) //判断输入是否有意义
            return result;
        vector<int>::const_iterator iter = input.begin();
        for (; iter != input.end(); iter++)
        {
            if ((leastNumbers.size()) < (unsigned long)k) //将前k个数插入leastNumbers中
                leastNumbers.insert(*iter);
            else
            { //将后面的进行比较，如果得到的数字比leastNumbers中的最大值大，则舍去，否则删掉最大值，插入得到的数字
                setIterator iterGreatest = leastNumbers.begin();
                if (*iter < *(leastNumbers.begin()))
                {
                    leastNumbers.erase(iterGreatest);
                    leastNumbers.insert(*iter);
                }
            }
        }
        while (!leastNumbers.empty())
        { //将multiset中的数转存到vector中，时从大到小的排列
            setIterator iterGreatest = leastNumbers.begin();
            result.push_back(*iterGreatest);
            leastNumbers.erase(iterGreatest);
        }
        return result;
    }

    typedef multiset<int, greater<int>> intSet; //greater<int>表示第一个元素（根）是最大的
    typedef multiset<int, greater<int>>::iterator setIterator;
};

int main() {
    int n;
    cin >> n;
    vector<int> input,result;
    for (int i = 0; i < n;i++) {
        int m;
        cin >> m;
        input.push_back(m);
    }
    int k;
    cin >> k;
    Solution S;
    result = S.GetLeastNumbers_Solution(input, k);
    for (vector<int>::iterator i = result.begin(); i != result.end();i++) {
        cout << *i<<" ";
    }
    system("pause");
    return 0;
}