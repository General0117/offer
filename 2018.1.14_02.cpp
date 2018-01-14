#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

class Solution {
public:
    void replaceSpace(char *str, int length) {
        if (str == NULL || length <= 0)
            return;

        int newlength = strlen(str);
        int oldlength = strlen(str);
        int i = 0;
        while(str[i] != '\0')
        {
            if(str[i] == ' ')
            {
                newlength += 2;
            }
            i++;
        }

        if(newlength == length)
            return;

        while(oldlength != newlength)
        {
            if(str[oldlength] == ' ')
            {
                str[newlength--] = '0';
                str[newlength--] = '2';
                str[newlength] = '%';
            }
            else
            {
                str[newlength] = str[oldlength];
            }
            newlength--;
            oldlength--;
        }
    }
};

int main()
{
    Solution s;
    char str[100] = "we are happy.";
    s.replaceSpace(str, 100);
    cout << str << endl << "len" << strlen(str) << endl;;
    return 0;
}
