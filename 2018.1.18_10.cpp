#include<iostream>
using namespace std;

class Solution {
public:
    int rectCover(int number) {
       	int re[3]={0,1,2};
        if(number<3)
            return re[number];

        long long fibNMinusOne = 1;
        long long fibNMinusTwo = 2;
        long long fibN = 0;
        for(unsigned int i = 3;i <= number;i++)
        {
            fibN = fibNMinusOne + fibNMinusTwo;
            fibNMinusOne = fibNMinusTwo;
            fibNMinusTwo = fibN;
        }
        return fibN;
    }
};

int main(){
    int n;
    cin>>n;
    Solution s;
    cout<<s.rectCover(n);
}

/*�赱ǰ����Ϊn��2*1С���ι��ɣ�������ѡ�����ŷ�����ŷţ���ѡ�����ŷ�
��������ʱ��ʣ�²���Ϊf(n-1)�ַŷ����ɴ˿ɼ���Ϊ쳲��������С�*/
