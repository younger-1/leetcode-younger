#
# @lc app=leetcode.cn id=684 lang=python3
#
# [684] 冗余连接
#


# @lc code=start
class Solution:
    # 39/39 cases passed (52 ms)
    # Your runtime beats 98.7 % of python3 submissions
    # Your memory usage beats 36.83 % of python3 submissions (15.1 MB)
    def findRedundantConnection(self, edges: list[list[int]]) -> list[int]:
        nodesCount = len(edges)
        parent = list(range(nodesCount + 1))

        def find(index: int) -> int:
            if parent[index] != index:
                parent[index] = find(parent[index])
            return parent[index]

        def union(a: int, b: int):
            parent[find(a)] = find(b)

        for node1, node2 in edges:
            if find(node1) != find(node2):
                union(node1, node2)
            else:
                return [node1, node2]


# @lc code=end
