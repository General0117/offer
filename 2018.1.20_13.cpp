#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//version 1
//���¿��ٺ�ԭ����ͬ����С������ռ䣬ɨ��ԭ����2�Σ��ֱ�������ż�����������飬�ڿ�����ԭ����
//�ŵ㣺���ı�������ż�����������ֵ����˳��
//ȱ�㣺��ҪO(n)�Ŀռ�
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
//˼·:�ɷ��տ��������е�partition������˼��
//�ŵ㣺ʱ�临�Ӷ�ΪO(n),�ռ临�Ӷ�ΪO(1)
//ȱ�㣺�ı������ݵ����˳��
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

//-------���Դ���------

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
