// 面试题 03.03. 堆盘子
// https://leetcode-cn.com/problems/stack-of-plates-lcci/

/**
 * Your StackOfPlates object will be instantiated and called as such:
 * StackOfPlates* obj = new StackOfPlates(cap);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAt(index);
 */

#include <list>
#include <stack>

using namespace std;

class StackOfPlates {
   public:
    StackOfPlates(int cap) : cap_(cap) {}

    void push(int val) {
        if (cap_ == 0) {
            return;
        }
        if (li.empty() || li.back().size() == cap_) {
            li.emplace_back(stack<int>());
        }
        li.back().push(val);
    }

    int pop() {
        if (li.empty()) {
            return -1;
        }
        int ans = li.back().top();
        li.back().pop();

        if (li.back().empty()) {
            li.pop_back();
        }
        return ans;
    }

    int popAt(int index) {
        if (index >= li.size()) {
            return -1;
        }
        auto it = li.begin();
        std::advance(it, index);

        int ans = (*it).top();
        (*it).pop();

        if ((*it).empty()) {
            li.erase(it);
        }
        return ans;
    }

   private:
    int cap_;
    list<stack<int>> li;
};

#include <vector>

// https://leetcode-cn.com/problems/stack-of-plates-lcci/solution/c-vector-stack-by-coeker-gc40/906455
class StackOfPlates_1 {
   private:
    vector<stack<int>> stacks;
    int capacity;

   public:
    StackOfPlates_1(int cap) : capacity(cap) {}

    void push(int val) {
        if (capacity > 0) {
            if (stacks.empty() or static_cast<int>(stacks.back().size()) >= capacity)
                stacks.emplace_back();
            stacks.back().emplace(val);
        }
    }

    int pop() { return popAt(static_cast<int>(stacks.size()) - 1); }

    int popAt(int index) {
        int res = -1;
        if (index >= 0 and index < static_cast<int>(stacks.size())) {
            res = stacks[index].top();
            stacks[index].pop();
            if (stacks[index].empty())
                stacks.erase(next(stacks.begin(), index));
        }
        return res;
    }
};
