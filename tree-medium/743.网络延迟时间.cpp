/*
 * @lc app=leetcode.cn id=743 lang=cpp
 *
 * [743] 网络延迟时间
 */

#include <cmath>
#include <queue>
#include <vector>

using namespace std;

// @lc code=start

// TODO: redo
// https://leetcode-cn.com/problems/network-delay-time/comments/79452
class Solution {
   public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        queue<int> myQue;                                          // 该队列用于即将访问的节点
        vector<int> distToK(N + 1, INT_MAX);                       // distToK[index]表示点K到点index的最短距离
        vector<vector<int>> graph(N + 1, vector<int>(N + 1, -1));  // 邻接矩阵
        for (auto& time : times) {
            graph[time[0]][time[1]] = time[2];
        }
        myQue.push(K);
        // K到自己的最短距离为0
        distToK[K] = 0;
        // 开始搜索各个点到k的最短距离
        while (!myQue.empty()) {
            int front = myQue.front();
            myQue.pop();
            // 利用当前front节点，尝试稀疏点k到所有节点的最短距离
            for (int target = 1; target <= N; ++target) {
                if (graph[front][target] != -1 && distToK[front] + graph[front][target] < distToK[target]) {
                    distToK[target] = distToK[front] + graph[front][target];
                    myQue.push(target);
                }
            }
        }
        // 寻找点k到各个点的最短距离的最大值
        int maxRes = 0;
        for (int i = 1; i <= N; ++i) {
            maxRes = max(maxRes, distToK[i]);
        }
        return maxRes == INT_MAX ? -1 : maxRes;
    }
};
// @lc code=end
