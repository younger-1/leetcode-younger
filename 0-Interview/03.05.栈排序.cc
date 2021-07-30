// 面试题 03.05. 栈排序
// https://leetcode-cn.com/problems/sort-of-stacks-lcci/

#include <stack>

using namespace std;

class SortedStack {
   public:
    SortedStack() {}

    void push(int val) {
        while (!min.empty() && min.top() < val) {
            con.push(min.top());
            min.pop();
        }
        min.push(val);
        while (!con.empty()) {
            min.push(con.top());
            con.pop();
        }
    }

    void pop() {
        if (isEmpty()) {
            return;
        }
        min.pop();
    }

    int peek() {
        if (isEmpty()) {
            return -1;
        }
        return min.top();
    }

    bool isEmpty() { return min.empty(); }

   private:
    stack<int> min, con;
};

/**
 * Your SortedStack object will be instantiated and called as such:
 * SortedStack* obj = new SortedStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->isEmpty();
 */
