## NoCode

要命, 编译出错

```cpp
    int i = -1;
    while (i < m - 1) {
        i += 1;
    }
```



## Algorithm problem

2021届秋招大厂高频算法题汇总
<https://blog.csdn.net/SDDDLLL/article/details/109723251>



## Good

[BFS 的使用场景总结：层序遍历、最短路径问题](https://leetcode-cn.com/problems/binary-tree-level-order-traversal/solution/bfs-de-shi-yong-chang-jing-zong-jie-ceng-xu-bian-l/)

- 可以看到，「BFS 遍历」、「层序遍历」、「最短路径」实际上是递进的关系。
- 在 BFS 遍历的基础上区分遍历的每一层，就得到了层序遍历。在层序遍历的基础上记录层数，就得到了最短路径

[LeetCode 例题精讲 | 12 岛屿问题：网格结构中的 DFS](https://mp.weixin.qq.com/s?__biz=MzA5ODk3ODA4OQ==&mid=2648167208&idx=1&sn=d8118c7c0e0f57ea2bdd8aa4d6ac7ab7&chksm=88aa236ebfddaa78a6183cf6dcf88f82c5ff5efb7f5c55d6844d9104b307862869eb9032bd1f&scene=178&cur_album_id=1338094723818668033#rd)

```java
void dfs(int[][] grid, int r, int c) {
    // 判断 base case
    if (!inArea(grid, r, c)) {
        return;
    }
    // 如果这个格子不是岛屿，直接返回
    if (grid[r][c] != 1) {
        return;
    }
    grid[r][c] = 2; // 将格子标记为「已遍历过」
    
    // 访问上、下、左、右四个相邻结点
    dfs(grid, r - 1, c);
    dfs(grid, r + 1, c);
    dfs(grid, r, c - 1);
    dfs(grid, r, c + 1);
}

// 判断坐标 (r, c) 是否在网格中
boolean inArea(int[][] grid, int r, int c) {
    return 0 <= r && r < grid.length 
         && 0 <= c && c < grid[0].length;
}
```

[最大人工岛](https://leetcode-cn.com/problems/making-a-large-island/solution/zui-da-ren-gong-dao-by-leetcode/)

- 方法1：stack 用作 DFS
- 方法2：使用了生成器 `def neighbors(r, c):`;


[【柱状图中最大的矩形】单调栈入门，使用单调栈快速寻找边界](https://leetcode-cn.com/problems/largest-rectangle-in-histogram/solution/84-by-ikaruga/)

- 对于单调递增栈：

1. 当元素出栈时，新元素是出栈（栈顶）元素向后找（右边）第一个比其小的元素。
2. 栈顶元素是新入栈元素向前找（左边）第一个比其小的元素。或者说，栈内每个元素左边第一个（往栈底方向）元素是向前找（左边）第一个比其小的元素。
3. 栈内相邻元素之间“消失”的所有元素，都比它们大
4. 1用于出栈；2用于入栈。

[回溯算法入门级详解 + 练习](https://leetcode-cn.com/problems/permutations/solution/hui-su-suan-fa-python-dai-ma-java-dai-ma-by-liweiw/)

- <https://leetcode-cn.com/problems/permutations/solution/quan-pai-lie-by-leetcode-solution-2/>
- <https://leetcode-cn.com/problems/palindrome-partitioning/solution/hui-su-you-hua-jia-liao-dong-tai-gui-hua-by-liweiw/>



### Binary Search

<https://leetcode-cn.com/problems/search-insert-position/solution/te-bie-hao-yong-de-er-fen-cha-fa-fa-mo-ban-python-/>



## REDO

- 92
- 896
- 38 <https://leetcode-cn.com/problems/count-and-say/solution/xun-huan-he-di-gui-liang-chong-jie-fa-di-oof8/>
- 25 <https://leetcode-cn.com/problems/reverse-nodes-in-k-group/solution/k-ge-yi-zu-fan-zhuan-lian-biao-by-leetcode-solutio/>
- 304 using c++
- 450



## TODO

- 8

KMP & DFA: <https://leetcode-cn.com/problems/implement-strstr/solution/kmp-suan-fa-xiang-jie-by-labuladong/>

```python
INT_MAX = 2 ** 31 - 1
INT_MIN = -2 ** 31

class Automaton:
    def __init__(self):
        self.state = 'start'
        self.sign = 1
        self.ans = 0
        self.table = {
            'start': ['start', 'signed', 'in_number', 'end'],
            'signed': ['end', 'end', 'in_number', 'end'],
            'in_number': ['end', 'end', 'in_number', 'end'],
            'end': ['end', 'end', 'end', 'end'],
        }
        
    def get_col(self, c):
        if c.isspace():
            return 0
        if c == '+' or c == '-':
            return 1
        if c.isdigit():
            return 2
        return 3

    def get(self, c):
        self.state = self.table[self.state][self.get_col(c)]
        if self.state == 'in_number':
            self.ans = self.ans * 10 + int(c)
            self.ans = min(self.ans, INT_MAX) if self.sign == 1 else min(self.ans, -INT_MIN)
        elif self.state == 'signed':
            self.sign = 1 if c == '+' else -1

class Solution:
    def myAtoi(self, str: str) -> int:
        automaton = Automaton()
        for c in str:
            automaton.get(c)
        return automaton.sign * automaton.ans

```

```java
class Solution {
    public int myAtoi(String str) {
         int state = 0;
        long s = 0;
        int sign = 1;

        for (int i = 0; i < str.length(); i++) {
            char t = str.charAt(i);
            if (state == 0 && t == ' ') {
                state = 0;
            } else if (state == 0 && (t == '-' || t == '+')) {
                state = 1;
            } else if ((state == 0 || state == 1 || state == 2) && (t >= '0' && t <= '9')) {
                state = 2;
            } else {
                state = 3;
            }
            if (state == 1) sign = t == '-' ? -1 : 1;

            if (state == 2) {
                s = s * 10 + (int) (t - 48);
                if (s * sign >= Integer.MAX_VALUE) return Integer.MAX_VALUE;
                if (s * sign <= Integer.MIN_VALUE) return Integer.MIN_VALUE;
            }
            if (state == 3) break;
        }
        return (int) s != 0 ? (int) s * sign : 0;
    }
}
```

- 234

```java
// 其一，find mid node 使用快慢指针找到链表中点。 其二，reverse 逆序后半部分。 其三，check 从头、中点，开始比较是否相同。
bool isPalindrome(ListNode* head) {//O(n)、O(1)
    ListNode* slow = head, *fast = head,  *prev = nullptr;
    while (fast){//find mid node
        slow = slow->next;
        fast = fast->next ? fast->next->next: fast->next;
    }
    while (slow){//reverse
        ListNode* temp = slow->next;
        slow->next = prev;
        prev = slow;
        slow = temp;
    }
    while (head && prev){//check
        if (head->val != prev->val){
            return false;
        }
        head = head->next;
        prev = prev->next;
    }
    return true;
}
```

```python
# 数学方法
def isPalindrome(self, head):
    s1=0
    s2=0
    t=1
    while head != None:
        s1 = s1 * 10 + head.val
        s2 = s2 + t * head.val
        t = t * 10
        head = head.next
    return s1 == s2
```

- 765

```cpp
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int ret = 0;
        for (int i = 0; i < row.size(); i += 2) {
            int a = row[i];
            // 异或
            int b = a ^ 1;
            if (row[i + 1] == b) continue;
            for (int j = i + 1; j < row.size(); ++j) {
                if (row[j] == b) {
                    swap(row[j], row[i + 1]);
                    ret += 1;
                    break;
                }
            }
        }
        return ret;
    }
};
```

- 102 二叉树的层序遍历

```rust
impl Solution {
    pub fn level_order(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<Vec<i32>> {
        let mut ret = vec![];
        dfs(root, 0, &mut ret);
        ret
    }
}

fn dfs(node: Option<Rc<RefCell<TreeNode>>>, level: usize, ret: &mut Vec<Vec<i32>>) {
    if let Some(n) = node {
        if ret.len() < level+1 { ret.push(vec![]); }
        ret[level].push(n.borrow().val);
        dfs(n.borrow_mut().left.take(), level+1, ret);
        dfs(n.borrow_mut().right.take(), level+1, ret);
    }
}
```

- 827

```python
class UnionFind:                        # 默写并查集模板
    def __init__(self, n):
        self.n = n
        self.part = n
        self.parent = [x for x in range(n)]
        self.size = [1 for _ in range(n)]
    
    def Find(self, x: int) -> int:
        if self.parent[x] != x:
            self.parent[x] = self.Find(self.parent[x])
        return self.parent[x]
    
    def Union(self, x: int, y : int) -> bool:
        root_x = self.Find(x)
        root_y = self.Find(y)
        if root_x == root_y:
            return False
        if self.size[root_x] > self.size[root_y]:
            root_x, root_y = root_y, root_x
        self.parent[root_x] =  root_y
        self.size[root_y] += self.size[root_x]
        self.part -= 1
        return True
    
    def inthesamepart(self, x: int, y : int) -> bool:
        return self.Find(x) == self.Find(y)
    
    def getpartsize(self, x: int) -> int:
        root_x = self.Find(x)
        return self.size[root_x]

class Solution:
    def largestIsland(self, grid: List[List[int]]) -> int:
        R, C = len(grid), len(grid[0])
        UF = UnionFind(R * C)
        for r in range(R):
            for c in range(C):
                if grid[r][c] == 1:                 # 初始化并查集  把陆地都连接在一起
                    for dr,dc in ((1, 0), (0, 1)):
                        nr = r + dr
                        nc = c + dc
                        if 0 <= nr < R and 0 <= nc < C and grid[nr][nc] == 1:
                            UF.Union(r * C + c,   nr * C + nc)
        res = max(UF.size)                          # 当前最大的区域
        for r in range(R):
            for c in range(C):
                if grid[r][c] == 0:                 # 按照题意  把一块海洋，变成陆地
                    tmp = 1                         # 当前这块就 + 1
                    root_set = set()
                    for dr,dc in ((-1,0), (0,1), (1,0), (0,-1)):    # 4个方向  最多有可能连接4块区域
                        nr,  nc = r + dr,  c + dc
                        if 0 <= nr < R and 0 <= nc < C and grid[nr][nc] == 1:   # 在矩阵内且是陆地
                            part_root = UF.Find(nr * C + nc)
                            if part_root not in root_set:                       # 且还没统计过
                                tmp += UF.size[part_root]
                                root_set.add(part_root)
                    res = max(res, tmp)
        return res
```

- 1162 地图分析


0-1 背包问题

```cpp
int knapsack(int W, int N, vector<int>& wt, vector<int>& val) {
    vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= W; j++) {
            if (j - wt[i - 1] < 0) {
                dp[i][j] = dp[i - 1][j];
            } else {
                // 如果你把这第i个物品装入了背包，那么dp[i][w]应该等于 dp[i-1][w-wt[i-1]] + val[i-1]。
                // dp[i-1][w-wt[i-1]] 表示在装第i个物品的前提下，背包能装的最大价值
                // 如果你没有把这第i个物品装入背包，那么很显然，最大价值dp[i][w]应该等于dp[i-1][w]。你不装嘛，那就继承之前的结果
                dp[i][j] = max(dp[i - 1][j - wt[i - 1]] + val[i - 1], dp[i - 1][w]);
            }
        }
    }
    return dp[N][M];
}
```
