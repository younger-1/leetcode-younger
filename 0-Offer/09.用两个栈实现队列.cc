// 剑指 Offer 09. 用两个栈实现队列
// https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof/

#include <stack>
using namespace std;

// 维护两个栈，第一个栈支持插入操作，第二个栈支持删除操作
class CQueue {
   private:
    stack<int> stack1, stack2;

   public:
    CQueue() {}

    void appendTail(int value) { stack1.push(value); }

    int deleteHead() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        if (stack2.empty()) {
            return -1;
        } else {
            int deleteItem = stack2.top();
            stack2.pop();
            return deleteItem;
        }
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */