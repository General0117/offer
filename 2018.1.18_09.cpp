#include<iostream>
using namespace std;

class Solution {
public:
    int jumpFloorII(int number) {
		int a=1;
        return a<<(number-1);
    }
};

int main(){
    int n;
    cin>>n;
    Solution s;
    cout<<s.jumpFloorII(n);
}

/*f(n) = f(n - 1) + f(n - 2) + ... + f(1);
f(n - 1) = f(n - 2) + ... + f(1);
*/
