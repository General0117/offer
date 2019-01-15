#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int temp = 1;
        int i = array.size()-1;
        int j = 0;
        while(temp==1)
        {
            if(i<0||j>=array[0].size())
            {
                temp=0;
            }
            else if(target > array[i][j])
            {
                j++;
                continue;
            }
            else if(target < array[i][j])
            {
                i--;
                continue;
            }
            else
                return true;
        }
        return false;
    }
};

int main()
{
    vector<vector<int> >array(4,vector<int>(4));  //����һ��4*4�Ķ�ά����
    //������Ԫ�ظ�ֵ
    array[0][0]=1;
    array[0][1]=2;
    array[0][2]=3;
    array[0][3]=4;
    array[1][0]=2;
    array[1][1]=3;
    array[1][2]=6;
    array[1][3]=7;
    array[2][0]=3;
    array[2][1]=4;
    array[2][2]=7;
    array[2][3]=8;
    array[3][0]=5;
    array[3][1]=6;
    array[3][2]=9;
    array[3][3]=10;
    Solution s;
    cout<<s.Find(9,array);
    system("pause");
    return 0;
}
