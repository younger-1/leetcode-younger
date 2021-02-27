#
# @lc app=leetcode.cn id=36 lang=python3
#
# [36] 有效的数独
#

# @lc code=start
class Solution:
    # 507/507 cases passed (36 ms)
    # Your runtime beats 99.38 % of python3 submissions
    # Your memory usage beats 65.13 % of python3 submissions (14.8 MB)
    def isValidSudoku(self, board: list[list[str]]) -> bool:
        # Init data
        rows = [dict() for i in range(9)]
        cols = [dict() for i in range(9)]
        boxes = [dict() for i in range(9)]
        for i in range(9):
            for j in range(9):
                num = board[i][j]
                if num != ".":
                    box_index = (i // 3) * 3 + (j // 3)
                    # Fill rows, cols, boxes
                    rows[i][num] = rows[i].get(num, 0) + 1
                    cols[j][num] = cols[j].get(num, 0) + 1
                    boxes[box_index][num] = boxes[box_index].get(num, 0) + 1
                    # Check duplicate
                    if (
                        rows[i].get(num) > 1
                        or cols[j].get(num) > 1
                        or boxes[box_index].get(num) > 1
                    ):
                        return False
        return True


# @lc code=end


class Solution_1:
    def isValidSudoku(self, board: list[list[str]]) -> bool:
        matrix_line = [set() for i in range(9)]
        matrix_column = [set() for i in range(9)]
        matrix_area = [set() for i in range(9)]
        for i in range(9):
            for j in range(9):
                item = board[i][j]
                pos = (i // 3) * 3 + j // 3
                if item != ".":
                    if (
                        item not in matrix_line[i]
                        and item not in matrix_column[j]
                        and item not in matrix_area[pos]
                    ):
                        matrix_line[i].add(item)
                        matrix_column[j].add(item)
                        matrix_area[pos].add(item)
                    else:
                        return False
        return True