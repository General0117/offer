#include<iostream>
#include<stack>
using namespace std;


class Solution {
public:
    void push(int value) {
            stack1.push(value);
    }
    void pop() {
        stack1.pop();
    }
    int top() {
        return stack1.top();
    }

    int min() { //用一另一个栈存放读入的数据
        int minNum=0;
        if(!stack1.empty())
        {
            minNum =stack1.top();
            stack2.push(stack1.top());
            stack1.pop();
        }
        while (!stack1.empty())
        {
            if (minNum > stack1.top())
            {
                minNum = stack1.top();
                stack2.push(stack1.top());
                stack1.pop();
            }
            else
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        while(!stack2.empty())
        {
            stack1.push(stack2.top());
            stack2.pop();
        }
        return minNum;
    }
private:
    stack<int> stack1;
    stack<int> stack2;
};
