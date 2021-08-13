/*
 * @lc app=leetcode.cn id=621 lang=cpp
 *
 * [621] 任务调度器
 */

#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
   public:
    int leastInterval(vector<char>& tasks, int n) {
        /*
            n = 3, {A : 3, B : 3, C : 2}
            [A,B,C,_] [A,B,C,_] [A,B,_,_]
         */
        int len = tasks.size();
        vector<int> count(26);
        for (int i = 0; i < len; i++) {
            count[tasks[i] - 'A']++;
        }
        sort(count.begin(), count.end());
        int maxCount = 0;
        for (int i = 25; i >= 0 && count[i] == count[25]; i--) {
            maxCount++;
        }
        return max(len, (n + 1) * (count[25] - 1) + maxCount);
    }
};

// @lc code=end
// https://leetcode-cn.com/problems/task-scheduler/solution/ren-wu-diao-du-qi-by-leetcode-solution-ur9w/
class Solution_11 {
   public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        for (char ch : tasks) {
            ++freq[ch];
        }

        // 最多的执行次数
        int maxExec = std::max_element(freq.begin(), freq.end(), [](const auto& u, const auto& v) {
                          return u.second < v.second;
                      })->second;
        // 具有最多执行次数的任务数量
        int maxCount = std::accumulate(freq.begin(), freq.end(), 0, [=](int acc, const auto& u) {
            return acc + static_cast<int>(u.second == maxExec);
        });

        return std::max((maxExec - 1) * (n + 1) + maxCount, static_cast<int>(tasks.size()));
    }
};

int main() {
    vector<char> tasks{'A', 'A', 'B', 'B', 'C', 'C', 'D', 'D', 'E', 'E', 'F', 'F', 'G', 'G', 'H', 'H', 'I', 'I',
                       'J', 'J', 'K', 'K', 'L', 'L', 'M', 'M', 'N', 'N', 'O', 'O', 'P', 'P', 'Q', 'Q', 'R', 'R',
                       'S', 'S', 'T', 'T', 'U', 'U', 'V', 'V', 'W', 'W', 'X', 'X', 'Y', 'Y', 'Z', 'Z'};
    auto s = Solution();
    int ans = s.leastInterval(tasks, 2);
}
