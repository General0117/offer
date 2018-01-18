#include<iostream>
using namespace std;

class Solution {
public:
    int jumpFloor(int number) {
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
    cout<<s.jumpFloor(n);
}
