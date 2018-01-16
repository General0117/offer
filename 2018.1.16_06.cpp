#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray)
    {
        if(rotateArray.size()<=0)
            return 0;
        else
        {
            int p1 = 0;
            int p2 = rotateArray.size() - 1;
            int Mid = p1;
            while(rotateArray[p1] >= rotateArray[p2])
            {
                if(p2 - p1 == 1)
                {
                    Mid = p2;
                    break;
                }

                Mid = (p1 + p2) / 2;

                if(rotateArray[p1] == rotateArray[p2]&&rotateArray[Mid] == rotateArray[p1])
                    return MinInOrder(rotateArray,p1,p2);
                if(rotateArray[Mid] >= rotateArray[p1])
                    p1 = Mid;
                else if(rotateArray[Mid] <= rotateArray[p2])
                    p2 = Mid;
            }
            return rotateArray[Mid];
        }
    }
    int MinInOrder(vector<int> rotateArray,int p1,int p2)
    {
        int result = rotateArray[p1];
        for(int i = p1 + 1;i <= p2; i++)
        {
            if(result > rotateArray[i])
        	result = rotateArray[i];
        }
        return result;
    }
};

int main()
{
    vector<int> rotateArray;
    int n;
    cin>>n;
    for(int i = 0;i < n;i++)
    {
        int a;
        cin>>a;
        rotateArray.push_back(a);
    }
    /*for(std::vector<int>::iterator m=rotateArray.begin();m!=rotateArray.end();m++)
    {
        cout<<*m<<endl;
    }*/
    Solution s;
    cout<<s.minNumberInRotateArray(rotateArray);
}
