#
# @lc app=leetcode.cn id=1584 lang=python3
#
# [1584] 连接所有点的最小费用
#

# @lc code=start
class Solution:
    # 72/72 cases passed (1756 ms)
    # Your runtime beats 51.93 % of python3 submissions
    # Your memory usage beats 22.22 % of python3 submissions (103 MB)
    def minCostConnectPoints(self, points: list[list[int]]) -> int:
        edges = []
        n = len(points)
        # Calc distance of each point
        for i in range(n):
            x1, y1 = points[i]
            for j in range(i + 1, n):
                x2, y2 = points[j]
                edges.append([i, j, abs(x1 - x2) + abs(y1 - y2)])
        # Sort by distance
        edges.sort(key=lambda edge: edge[2])
        # UnionSet
        parent = list(range(n))

        def find(x):
            if x != parent[x]:
                parent[x] = find(parent[x])
            return parent[x]

        edge, cost = 0, 0
        for i, j, dist in edges:
            pi, pj = find(i), find(j)
            # Do union
            if pi != pj:
                parent[pi] = pj
                edge += 1
                cost += dist
            if edge == n - 1:
                break
        return cost
