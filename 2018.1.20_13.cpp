#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//version 1
//重新开辟和原数组同样大小的数组空间，扫描原数组2次，分别将奇数和偶数放入新数组，在拷贝回原数组
//优点：不改变奇数和偶数集合中数字的相对顺序
//缺点：需要O(n)的空间
//void ReorderOddEven(vector<int>& arr)
//{
//    vector<int> newarr;
//    int i;
//    for(i=0;i<arr.size();++i)
//    {
//        if(arr[i]&0x1)
//        {
//            newarr.push_back(arr[i]);
//        }
//    }
//    for(i=0;i<arr.size();++i)
//    {
//        if(!(arr[i]&0x1))
//        {
//            newarr.push_back(arr[i]);
//        }
//    }
//    arr.clear();
//    arr=newarr;
//}

//version 2
//思路:可仿照快速排序中的partition函数的思想
//优点：时间复杂度为O(n),空间复杂度为O(1)
//缺点：改变了数据的相对顺序
void ReorderOddEven(vector<int>& arr)
{
    int i=0,j=arr.size()-1;
    while(i<j)
    {
        while(i<j && (arr[i] & 0x1))
            i++;
        while(i<j && !(arr[j] & 0x1))
            j--;
        swap(arr[i],arr[j]);
    }
}

//-------测试代码------

void printarray(vector<int> arr)
{
    if(arr.size()<=0)
    {
        cout<<"Nothing!"<<endl;
        return;
    }
    int i;
    for(i=0;i<arr.size();++i)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void test()
{
    int arr[]={0,1,2,3,4,5,6,7,8,9,10};
    vector<int> v;
    int i;
    for(i=0;i<sizeof(arr)/sizeof(arr[0]);++i)
    {
        v.push_back(arr[i]);
    }
    printarray(v);
    ReorderOddEven(v);
    printarray(v);
}

int main()
{
    test();
    return 0;
}
