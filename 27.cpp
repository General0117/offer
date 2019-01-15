#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include<stdlib.h>
using namespace std;

void per(vector<string> &res, string str, int index)
{ //注意传入的参数要用引用
    if (index == str.size() - 1)
    { //递归结束的条件就是，第一位和最后一位交换完成
        res.push_back(str);
        return;
    }
    for (int i = index; i < str.size(); i++)
    {                                           //让第一位和每一位交换
        if (i != index && str[index] == str[i]) //如果第一位和非第一位重复了，就不交换了
            continue;
        swap(str[index], str[i]);
        per(res, str, index + 1); //递归，第一位固定了，将除了第一位，后面的字符串全排序。
        swap(str[index], str[i]); //交换完成还要换回来，保证第一位不变
    }
}

vector<string> Permutation(string str)
{
    vector<string> res;
    if (str.size() == 0)
        return res; //判断输入的是空
    per(res, str, 0);
    sort(res.begin(), res.end()); //要求排序，所以全部打印出来后，用sort排一下序
    return res;
}

int main()
{
    string str;
    cin >> str;
    vector<string> result;
    result = Permutation(str);
    for (int i = 0; i < result.size();i++)
        cout << result[i] << endl;

    system("pause");
    return 0;
}
