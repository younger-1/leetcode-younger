// https://leetcode-cn.com/problems/number-of-orders-in-the-backlog/

#include <functional>
#include <queue>
#include <vector>

using namespace std;

class Solution {
   public:
    typedef pair<int, int> PII;
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        priority_queue<PII> A, B;
        int MOD = 1e9 + 7;
        long long ans = 0;
        for (auto& i : orders) {
            if (i[2] == 0) {
                A.push({i[0], i[1]});
            } else {
                B.push({-i[0], i[1]});
            }
            ans += i[1];
            while (!A.empty()) {
                if (B.empty() || -B.top().first > A.top().first) {
                    break;
                }
                PII x = A.top();
                A.pop();
                PII y = B.top();
                B.pop();

                int nu = min(x.second, y.second);
                x.second -= nu;
                y.second -= nu;
                ans -= 2 * nu;
                if (x.second)
                    A.push(x);
                else
                    B.push(y);
            }
        }
        return ans % MOD;
    }
};

// 执行用时： 284 ms , 在所有 C++ 提交中击败了 100.00% 的用户
// 内存消耗： 62.8 MB , 在所有 C++ 提交中击败了 100.00% 的用户
class Solution_0 {
   public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        const int MOD = 1e9 + 7;
        auto cmp = [](auto& a, auto& b) { return a.first < b.first; };
        auto dmp = [](auto& a, auto& b) { return a.first > b.first; };

        using _pair = pair<int, int>;
        using _container = vector<_pair>;
        priority_queue<_pair, _container, decltype(cmp)> buyOrders(cmp);
        priority_queue<_pair, _container, decltype(dmp)> sellOrders(dmp);

        function<void(vector<int>&)> putOrder = [&](vector<int>& order) {
            if (order[1] == 0) {
                return;
            }
            if (order[2] == 0 && sellOrders.empty()) {
                buyOrders.push(make_pair(order[0], order[1]));
                return;
            }
            if (order[2] == 1 && buyOrders.empty()) {
                sellOrders.push(make_pair(order[0], order[1]));
                return;
            }

            if (order[2] == 0) {
                // 不能用引用，top返回的是右值
                auto sellMin = sellOrders.top();
                if (order[0] < sellMin.first) {
                    buyOrders.push(make_pair(order[0], order[1]));
                    return;
                } else {
                    if (order[1] < sellMin.second) {
                        sellMin.second -= order[1];
                        sellOrders.pop();
                        sellOrders.push(sellMin);
                    } else {
                        order[1] -= sellMin.second;
                        sellOrders.pop();
                        putOrder(order);
                    }
                }
            }
            if (order[2] == 1) {
                // 不能用引用，top返回的是右值
                auto buyMax = buyOrders.top();
                if (order[0] > buyMax.first) {
                    sellOrders.push(make_pair(order[0], order[1]));
                    return;
                } else {
                    if (order[1] < buyMax.second) {
                        buyMax.second -= order[1];
                        buyOrders.pop();
                        buyOrders.push(buyMax);
                    } else {
                        order[1] -= buyMax.second;
                        buyOrders.pop();
                        putOrder(order);
                    }
                }
            }
        };

        for (auto order : orders) {
            putOrder(order);
        }
        int sum = 0;
        while (!buyOrders.empty()) {
            sum = (sum + buyOrders.top().second) % MOD;
            buyOrders.pop();
        }
        while (!sellOrders.empty()) {
            sum = (sum + sellOrders.top().second) % MOD;
            sellOrders.pop();
        }
        return sum % MOD;
    }
};

#include <iostream>
int main() {
    vector<int> v1 = {10, 5, 0};
    vector<int> v2 = {15, 2, 1};
    vector<int> v3 = {25, 1, 1};
    vector<int> v4 = {30, 4, 0};

    vector<vector<int>> vv;
    vv.push_back(v1);
    vv.push_back(v2);
    vv.push_back(v3);
    vv.push_back(v4);
    auto so = Solution();
    cout << so.getNumberOfBacklogOrders(vv);
}