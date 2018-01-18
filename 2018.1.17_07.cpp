#include<iostream>
using namespace std;

class Solution {
public:
    int Fibonacci(int n) {
		int re[2]={0,1};
        if(n<2)
            return re[n];

        long long fibNMinusOne = 1;
        long long fibNMinusTwo = 0;
        long long fibN = 0;
        for(unsigned int i = 2;i <= n;i++)
        {
            fibN = fibNMinusOne + fibNMinusTwo;
            fibNMinusTwo = fibNMinusOne;
            fibNMinusOne = fibN;
        }
        return fibN;
    }
};

int main(){
    int n;
    cin>>n;
    Solution s;
    cout<<s.Fibonacci(n);
}
