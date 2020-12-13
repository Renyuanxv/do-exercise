# LeetCode 232. 用栈实现队列

请你仅使用两个栈实现先入先出队列。队列应当支持一般队列的支持的所有操作（push、pop、peek、empty）：

实现 MyQueue 类：

* void push(int x) 将元素 x 推到队列的末尾
* int pop() 从队列的开头移除并返回元素
* int peek() 返回队列开头的元素
* boolean empty() 如果队列为空，返回 true ；否则，返回 false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/implement-queue-using-stacks

```cpp
class MyQueue {
    stack<int> In;入队列的栈
    stack<int> Out;出队列的栈
public:
    /** Initialize your data structure here. */
    MyQueue() {
    }
    
    /** Push element x to the back of queue. */
    //尾插队列:直接进入 入队列的栈
    void push(int x) {
        In.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    //从队列开头删除并返回元素:出队列栈为空，则从入队列栈向其中插入元素，队列的头元素即为出队列栈的top()；取出并删除
    int pop() {
        if(Out.empty()){
            while(!In.empty()){
                Out.push(In.top());
                In.pop();
            }
        }
        int result=Out.top();
        Out.pop();
        return result;
    }
    
    /** Get the front element. */
    //返回队列开头的元素：调用pop()来获取队列开头元素并保存，注意不能删除队列开头元素，需要再将其插入队列中
    int peek() {
        int res=pop();
        Out.push(res);
        return res;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return In.empty()&&Out.empty();
    }
};
```
