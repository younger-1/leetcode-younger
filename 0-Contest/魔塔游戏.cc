#include <queue>
#include <vector>

using namespace std;

class Solution {
   public:
    int magicTower(vector<int>& nums) {
        // 掉血的num存入优先队列q，如果死了血量<=0，就从q里选掉最大的伤害回一口血，然后num存入delay死亡
        priority_queue<int> q;
        long long int heart = 1, res = 0, delay = 0;
        for (int n : nums) {
            heart += n;
            if (n < 0) {
                q.push(-n);
            }
            while (heart <= 0) {
                heart += q.top();
                delay += q.top();
                q.pop();
                res += 1;
            }
        }
        if (heart <= delay) {
            return -1;
        }
        return res;
    }
};