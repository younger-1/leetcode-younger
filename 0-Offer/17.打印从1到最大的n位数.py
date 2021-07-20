# 剑指 Offer 17. 打印从1到最大的n位数
# https://leetcode-cn.com/problems/da-yin-cong-1dao-zui-da-de-nwei-shu-lcof/

# 作者：jyd
# 链接：https://leetcode-cn.com/problems/da-yin-cong-1dao-zui-da-de-nwei-shu-lcof/solution/mian-shi-ti-17-da-yin-cong-1-dao-zui-da-de-n-wei-2/

# 在此方法下，各数字字符串被逗号隔开，共同组成长字符串
""" 观察可知，当前的生成方法仍有以下问题：
1. 诸如 00, 01, 02, 应显示为 0, 1, 2
2. 此方法从 0 开始生成，而题目要求列表从 1 开始
"""
class Solution_demo:
    def printNumbers(self, n: int):
        def dfs(x):
            if x == n: # 终止条件：已固定完所有位
                res.append(''.join(num)) # 拼接 num 并添加至 res 尾部
                return
            for i in range(10): # 遍历 0 - 9
                num[x] = str(i) # 固定第 x 位为 i
                dfs(x + 1) # 开启固定第 x + 1 位
        
        num = ['0'] * n # 起始数字定义为 n 个 0 组成的字符列表
        res = [] # 数字字符串列表
        dfs(0) # 开启全排列递归
        return ','.join(res)  # 拼接所有数字字符串，使用逗号隔开，并返回


class Solution:
    def printNumbers(self, n: int):
        def dfs(x):
            if x == n:
                s = ''.join(num[self.start:])
                if s != '0':
                    res.append(int(s))
                if n - self.start == self.nine:
                    self.start -= 1
                return
            for i in range(10):
                if i == 9:
                    self.nine += 1
                num[x] = str(i)
                dfs(x + 1)
            self.nine -= 1
        
        num, res = ['0'] * n, []
        self.nine = 0
        self.start = n - 1
        dfs(0)
        return res

if __name__ == '__main__':
    s = Solution()
    res = s.printNumbers(1)
    print(res)
