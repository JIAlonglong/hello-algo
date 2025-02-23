/*
 * File: array_stack.cpp
 * Created Time: 2022-11-28
 * Author: qualifier1024 (2539244001@qq.com)
 */

#include "../include/include.hpp"

/* 基于数组实现的栈 */
class ArrayStack {
private:
    vector<int> stack;
    
public:
    /* 获取栈的长度 */
    int size() {
        return stack.size();
    }

    /* 判断栈是否为空 */
    bool empty() {
        return stack.empty();
    }

    /* 入栈 */
    void push(int num) {
        stack.push_back(num);
    }

    /* 出栈 */
    int pop() {
        int oldTop = top();
        stack.pop_back();
        return oldTop;
    }

    /* 访问栈顶元素 */
    int top() {
        if(empty())
            throw out_of_range("栈为空");
        return stack.back();
    }

    /* 访问索引 index 处元素 */
    int get(int index) {
        if(index >= size())
            throw out_of_range("索引越界");
        return stack[index];
    }

    /* 返回 Vector */
    vector<int> toVector() {
        return stack;
    }
};


/* Driver Code */
int main() {
    /* 初始化栈 */
    ArrayStack* stack = new ArrayStack();

    /* 元素入栈 */
    stack->push(1);
    stack->push(3);
    stack->push(2);
    stack->push(5);
    stack->push(4);
    cout << "栈 stack = ";
    PrintUtil::printVector(stack->toVector());

    /* 访问栈顶元素 */
    int top = stack->top();
    cout << "栈顶元素 top = " << top << endl;

    /* 访问索引 index 处元素 */
    int num = stack->get(3);
    cout << "栈索引 3 处的元素为 num = " << num << endl;

    /* 元素出栈 */
    int pop = stack->pop();
    cout << "出栈元素 pop = " << pop << "，出栈后 stack = ";
    PrintUtil::printVector(stack->toVector());

    /* 获取栈的长度 */
    int size = stack->size();
    cout << "栈的长度 size = " << size << endl;

    /* 判断是否为空 */
    bool empty = stack->empty();
    cout << "栈是否为空 = " << empty << endl;

    return 0;
}
