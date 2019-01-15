#include<iostream>
#include<vector>
using namespace std;

class Solution
{
  public:
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
        if(CheckInvalidArray(numbers))
            return 0;
        int result = numbers[0];
        int times = 1;
        for (vector<int>::iterator i = numbers.begin(); i != numbers.end();i++) {
            if(times == 0) {
                result = *i;
                times = 1;
            }
            else if(*i == result)
                times++;
            else
            
                times--;
        }
        if(!CheckMoreThanHalf(numbers,result))
            result = 0;
        return result;
    }
  private:
    bool g_bInputInvalid = false;
    bool CheckInvalidArray(vector<int> numbers) {
        g_bInputInvalid = false;
        if(numbers.empty())
            g_bInputInvalid = true;
        return g_bInputInvalid;
    }

    bool CheckMoreThanHalf(vector<int> numbers,int number) {
        int times = 0;
        for (vector<int>::iterator i = numbers.begin(); i != numbers.end();i++) {
            if(*i == number)
                times++;
        }
        bool isMoreThanHalf = true;
        if(times * 2 <= numbers.size()) {
            g_bInputInvalid = true;
            isMoreThanHalf = false;
        }
        return isMoreThanHalf;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> numbers;
    int N;
    cin >> N;
    int temp = 0;
    while(temp < N) {
        int x;
        cin >> x;
        numbers.push_back(x);
        temp++;
    }
    Solution s;
    cout << s.MoreThanHalfNum_Solution(numbers);
    system("pause");
    return 0;
}
