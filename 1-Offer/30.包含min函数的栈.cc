// 剑指 Offer 30. 包含min函数的栈
// https://leetcode-cn.com/problems/bao-han-minhan-shu-de-zhan-lcof/
// 注意：本题与主站 155 题相同：https://leetcode-cn.com/problems/min-stack/

#include <stack>

using namespace std;

// pair 中存的是 {数，最小值}
// https://leetcode-cn.com/problems/bao-han-minhan-shu-de-zhan-lcof/comments/259777
class MinStack {
   public:
    /** initialize your data structure here. */
    MinStack() {}

    void push(int x) {
        if (con.empty()) {
            con.push({x, x});
            return;
        }
        con.push({x, x < min() ? x : min()});
    }

    void pop() { con.pop(); }

    int top() { return con.top().first; }

    int min() { return con.top().second; }

   private:
    stack<pair<int, int>> con;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */
