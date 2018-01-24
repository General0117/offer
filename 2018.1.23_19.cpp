#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> re;
        if (matrix.size() == 0 || matrix[0].size() == 0) return re;
        int left = 0, right = matrix[0].size() - 1;
        int top = 0, bottom = matrix.size() - 1;
        // ������Ҫ�жϣ���Ϊ���β�һ��Ϊ������
        while (left <= right && top <= bottom) {
            for (int i = left; i <= right; i++) re.push_back(matrix[top][i]);
            for (int i = top + 1; i <= bottom; i++) re.push_back(matrix[i][right]);
            // ��ֹtop��bottom���ʱͬһ�д�ӡ����
            // ��ֹleft��right���ʱͬһ�д�ӡ����
            if (top != bottom) for (int i = right - 1; i >= left; i--) re.push_back(matrix[bottom][i]);
            if (left != right) for (int i = bottom - 1; i >= top+1; i--) re.push_back(matrix[i][left]);
            top++,bottom--,left++,right--;
        }
        return re;
    }
};
int main()
{

}
