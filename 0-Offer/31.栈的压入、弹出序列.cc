// 剑指 Offer 31. 栈的压入、弹出序列
// https://leetcode-cn.com/problems/zhan-de-ya-ru-dan-chu-xu-lie-lcof/

#include <stack>
#include <vector>

using namespace std;

class Solution {
   public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int j = 0;
        for (int n : pushed) {
            s.push(n);
            while (!s.empty() && s.top() == popped[j]) {
                s.pop();
                j++;
            }
        }
        return s.empty();
    }
};
