写给我弟的C语言学习方法，共享之

一、基础练习

<http://www.runoob.com/cprogramming/c-tutorial.html>

跟随这个教程里面的说明，将 “实例” 一个一个的手写到这个在线编辑器中运行

<http://www.runoob.com/try/runcode.php?filename=helloworld&type=c>

不要拘泥于现在学到什么程度，计算机这条路子上，自学才是正途，老师只是领你进门。需要适应这种，自己看文档，自己学东西，自己写代码的节奏

二、进阶练习

<http://www.runoob.com/cprogramming/c-examples.html>

根据第一步C教程中的实例写出这些代码。不明白的地方可以先复习教程中的例子，再比较来写。
运行不出来，需要不断调试修改。不断运行看错误的地方。感觉有大的壁垒解决不了，再看下边的答案，反复揣摩自己没能写出来的部分，做笔记记录上。再不明白的地方及时问我便好。

三、高阶练习

语言毕竟是工具，用于开发当然最好，不过你现在所学甚少，尚不能参加电子设计大赛、飞思卡尔汽车模型大赛这种偏底层硬件的比赛（我就是大一参加的，意义不大，大二读了计算机组成原理、模拟电路和数字电路以后才算明白些）

但有一个方向是非常重要的，即便是到顶尖的编程公司（微软、谷歌、阿里）都非常推崇，那就是 poj

简单说就是使用精简的编程语言，解决算法难题

北大：<http://poj.org/problemlist>

不说大话，poj如果能够刷过1500题，数学建模大赛/ACM 斩获金奖。

本科毕业即可面试BAT，这一件事就能包你入职。

阿里有个未来星计划，本科毕业年薪60W+ 未尝不可一试

你哥我当年便折在这个比赛上，参加了两次，都未能拿到名次



## 队列 & 栈



### 队列：先入先出的数据结构



#### [622] 设计循环队列

> design-circular-queue

```c
#include <iostream>
#include <vector>
using namespace std;

//52ms 15.4MB
class MyCircularQueue0 {
private:
    vector<int> data;
    int p_start;
    int p_end;
    int length;
public:
    MyCircularQueue(int _capacity = 0) :data(_capacity, 0) { //列表初始化对象成员
        p_start = 0;
        p_end = 0;
        length = 0;
    }
    bool isEmpty() {
        return 0 == length; // or p_start==p_end;
    }
    bool isFull() {
        return data.size() == length;
    }
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        data[p_end] = value;
        p_end = (p_end + 1) % data.size();
        length++;
        return true;
    }
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        p_start = (p_start + 1) % data.size();
        length--;
        return true;
    };
    int Front() {
        if (isEmpty()) 
            return -1;
        return data[p_start];
    };
    int Rear() {
        if (isEmpty()) 
            return -1;
        return data[(p_end + data.size() - 1) % data.size()]; //呵呵
    }
};

// tail记录入队的次数，head记录了出队的次数
class MyCircularQueue {
private:
    vector<int> data;
    int head = 0;
    int tail = 0;
    int cap = 0;
public:
    MyCircularQueue(int k) {
        data.resize(k);
        cap = k;
    }
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        data[tail % cap] = value;
        tail = tail + 1;
        return true;
    }
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        head = head + 1;
        return true;
    }
    int Front() {
        if (isEmpty()) {
            return -1;
        }
        return data[head % cap];
    }
    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        return data[(tail - 1) % cap];
    }
    bool isEmpty() {
        return tail == head;
    }
    bool isFull() {
        return tail == head + cap;
    }
};
```



### 队列和广度优先搜索



#### [200] 岛屿数量

```cpp
// 80ms 11.4MB
// 优点：不改变输入的二维向量
class Solution0 {
   public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty())
            return 0;
        int nums = 0;
        int height = grid.size();
        int width = grid[0].size();
        std::set<int> visited;
        for (int i = 0; i != height; i++) {
            for (int j = 0; j != width; j++) {
                //找到一个‘1’，广度优先搜索把‘1’所在的岛屿全加入已访问
                if ('1' == grid[i][j] &&
                    visited.end() == visited.find(width * i + j)) {
                    nums++;
                    std::queue<int> q;
                    q.push(width * i + j);
                    visited.insert(width * i + j);
                    while (!q.empty()) {
                        int current = q.front();
                        q.pop();
                        int row = current / width;
                        int col = current % width;
                        if (row != 0 && '1' == grid[row - 1][col])
                            if (visited.end() ==
                                visited.find(width * (row - 1) + col)) {
                                q.push(width * (row - 1) + col);
                                visited.insert(width * (row - 1) + col);
                            }
                        if (row != height - 1 && '1' == grid[row + 1][col])
                            if (visited.end() ==
                                visited.find(width * (row + 1) + col)) {
                                q.push(width * (row + 1) + col);
                                visited.insert(width * (row + 1) + col);
                            }
                        if (col != 0 && '1' == grid[row][col - 1])
                            if (visited.end() ==
                                visited.find(width * row + col - 1)) {
                                q.push(width * row + col - 1);
                                visited.insert(width * row + col - 1);
                            }
                        if (col != width - 1 && '1' == grid[row][col + 1])
                            if (visited.end() ==
                                visited.find(width * row + col + 1)) {
                                q.push(width * row + col + 1);
                                visited.insert(width * row + col + 1);
                            }
                    }
                }
            }
        }
        return nums;
    }
};

//0ms
class Solution1 {
public:
   private:
    void dfs(vector<vector<char>>& grid, int r, int c) {
        int nr = grid.size();
        int nc = grid[0].size();

        grid[r][c] = '0';
        if (r - 1 >= 0 && grid[r-1][c] == '1') dfs(grid, r - 1, c);
        if (r + 1 < nr && grid[r+1][c] == '1') dfs(grid, r + 1, c);
        if (c - 1 >= 0 && grid[r][c-1] == '1') dfs(grid, r, c - 1);
        if (c + 1 < nc && grid[r][c+1] == '1') dfs(grid, r, c + 1);
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int nr = grid.size();
        if (!nr) return 0;
        int nc = grid[0].size();

        int num_islands = 0;
        for (int r = 0; r < nr; ++r) {
            for (int c = 0; c < nc; ++c) {
                if (grid[r][c] == '1') {
                    ++num_islands;
                    dfs(grid, r, c);
                }
            }
        }

        return num_islands;
    }
};
```



#### [752] 打开转盘锁



```python
# 776ms 14.7 MB
class Solution1:
    def openLock(self, deadends: List[str], target: str) -> int:
        def neighbors(node):
            for i in range(4):
                x = int(node[i])
                for d in (-1, 1):
                    y = (x + d) % 10
                    yield node[:i] + str(y) + node[i + 1:]

        dead = set(deadends)
        queue = deque([('0000', 0)])
        seen = {'0000'}
        while queue:
            node, depth = queue.popleft()
            if node == target:
                return depth
            if node in dead:
                continue
            for nei in neighbors(node):
                if nei not in seen:
                    seen.add(nei)
                    queue.append((nei, depth + 1))
        return -1
```



#### [279] 完全平方数

```python
# @暴力递归
class Solution1(object):
    def numSquares(self, n):
        square_nums = [i**2 for i in range(1, int(math.sqrt(n)) + 1)]

        def minNumSquares(k):
            """ recursive solution """
            # bottom cases: find a square number
            if k in square_nums:
                return 1

            min_num = float('inf')
            # Find the minimal value among all possible solutions
            for square in square_nums:
                if k < square:
                    break
                new_num = minNumSquares(k - square) + 1
                min_num = min(min_num, new_num)

            return min_num

        return minNumSquares(n)


# 5248ms 13.8MB
# @DP
class Solution2:
    def numSquares(self, n: int) -> int:
        square_nums = [i**2 for i in range(1, int(math.sqrt(n)) + 1)]
        dp = [float('inf')] * (n + 1)
        dp[0] = 0
        for i in range(1, n + 1):
            for square in square_nums:
                if i < square:
                    break
                dp[i] = min(dp[i], dp[i - square] + 1)

        return dp[-1]


# 76ms 14.3MB
# @贪心枚举
class Solution3:
    def numSquares(self, n):
        def is_divided_by(n, count):
            """
                return: true if "n" can be decomposed into "count" number of perfect square numbers.
                e.g. n=12, count=3:  true.
                     n=12, count=2:  false
            """
            if count == 1:
                return n in square_nums
            for k in square_nums:
                if is_divided_by(n - k, count - 1):
                    return True
            return False

        square_nums = set([i * i for i in range(1, int(n**0.5) + 1)])
        for count in range(1, n + 1):
            if is_divided_by(n, count):
                return count


# 200-296ms 14.8MB
# @BFS
class Solution4:
    def numSquares(self, n):

        square_nums = [i * i for i in range(1, int(n**0.5) + 1)]
        level = 0
        queue = {n}
        while queue:
            level += 1
            # use set() instead of list() to eliminate the redundancy,
            # which would even provide a 5-times speedup, 200ms vs. 1000ms.
            next_queue = set()
            for q in queue:
                for square in square_nums:
                    if q == square:
                        return level
                    elif q < square:
                        break
                    else:
                        next_queue.add(q - square)

            queue = next_queue

        return 0


# 380ms 14.6MB
# @BFS
class Solution4_1:
    def numSquares(self, n: int) -> int:
        deq = deque()
        visited = set()

        deq.append((n, 0))
        while deq:
            number, step = deq.popleft()
            targets = [number - i * i for i in range(1, int(number**0.5) + 1)]
            for target in targets:
                if target == 0:
                    return step + 1
                if target not in visited:
                    deq.append((target, step + 1))
                    visited.add(target)
        return -1


# 48ms 13.5MB
# @math
class Solution5:
    def isSquare(self, n: int) -> bool:
        sq = int(math.sqrt(n))
        return sq * sq == n

    def numSquares(self, n: int) -> int:

        if self.isSquare(n):
            return 1

        # four-square and three-square theorems
        while (n & 3) == 0:  # n % 4 == 0
            n >>= 2  # reducing the 4^k factor from number
        if (n & 7) == 7:  # n % 8 == 7
            return 4

        # check if the number can be decomposed into sum of two squares
        for i in range(1, int(n**(0.5)) + 1):
            if self.isSquare(n - i * i):
                return 2
        # bottom case from the three-square theorem
        return 3
```



### 栈：后入先出的数据结构



### 栈和深度优先搜索



### 小结
