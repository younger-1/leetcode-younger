/*
 * @lc app=leetcode.cn id=528 lang=cpp
 *
 * [528] 按权重随机选择
 */

#include <algorithm>
#include <iterator>
#include <numeric>
#include <random>
#include <vector>

using namespace std;

/*
mt19937: 头文件是<random> 是伪随机数产生器，用于产生高性能的随机数
uniform_int_distribution: 头文件在<random>中，是一个随机数分布类，参数为生成随机数的类型，构造函数接受两个值表示区间段
accumulate: 头文件在<numeric>中，求特定范围内所有元素的和。
partial_sum: 头文件在<numeric>，对(first, last)内的元素逐个求累计和，放在result容器内
back_inserter: 头文件<iterator>，用于在末尾插入元素。
lower_bound: 头文件在<algorithm>，用于找出范围内不大于num的第一个元素
 */

// @lc code=start

// TODO: redo
class Solution {
   public:
    Solution(vector<int>& w) : gen(random_device{}()), dis(1, accumulate(w.begin(), w.end(), 0)) {
        partial_sum(w.begin(), w.end(), back_inserter(pre));
    }

    int pickIndex() {
        int x = dis(gen);
        return lower_bound(pre.begin(), pre.end(), x) - pre.begin();
    }

   private:
    mt19937 gen;
    uniform_int_distribution<int> dis;
    vector<int> pre;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
// @lc code=end
