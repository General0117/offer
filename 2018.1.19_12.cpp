#include<iostream>
using namespace std;

class Solution {
public:
    bool g_InvalidInput = false;
    double Power(double base, int exponent) {
    	g_InvalidInput = false;

        if(base == 0.0&&exponent < 0)
        {
            g_InvalidInput = true;
            return 0.0;
        }
        unsigned int absExponent = (unsigned int )(exponent);
        if(exponent < 0)
        {
            absExponent = (unsigned int)(-exponent);
        }

        double re = PowerWithUnsignedExponent(base,absExponent);
        if(exponent < 0)
            re = 1.0 / re;
       	return re;
    }
   	double PowerWithUnsignedExponent(double base,unsigned int exponent){
    	double re = 1.0;
        for(int i = 1;i <= exponent;i++)
            re *= base;
        return re;
  	}
};

int main()
{
    double base;
    int exponent;
    cin>>base;
    cin>>exponent;
    Solution s;
    cout<<s.Power(base,exponent);
}
