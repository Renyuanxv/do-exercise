# 剑指offer 09.用两个栈组成队列

用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof

```cpp
class CQueue {
public:
    stack<int> putin;//入队列的栈
    stack<int> getout;//出队列的栈
    CQueue() {
    }

    void appendTail(int value) {
        putin.push(value);//加入队列 直接插入putin栈
    }

    //入队列的栈不为空，出队列的栈为空--->把队列里（入队列栈）的元素插入出队列栈
    //出队列栈的栈顶元素则为原队列的首元素
    int deleteHead() {
        if (putin.empty() && getout.empty()) {
            return -1;
        }
        else if (!putin.empty() && getout.empty()) {
            while (!putin.empty()) {
                getout.push(putin.top());
                putin.pop();
            }
        }
        int tmp = getout.top();
        getout.pop();
        return tmp;
    }
};
```
