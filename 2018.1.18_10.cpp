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

/*设当前矩形为n个2*1小矩形构成，有两种选择，竖着放与横着放，当选择竖着放
到最左面时，剩下部分为f(n-1)种放法，由此可见仍为斐波那契数列。*/
