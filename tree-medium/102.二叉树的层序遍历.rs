/*
 * @lc app=leetcode.cn id=102 lang=rust
 *
 * [102] 二叉树的层序遍历
 */

// Definition for a binary tree node.
#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
    pub val: i32,
    pub left: Option<Rc<RefCell<TreeNode>>>,
    pub right: Option<Rc<RefCell<TreeNode>>>,
}

impl TreeNode {
    #[inline]
    pub fn new(val: i32) -> Self {
        TreeNode {
            val,
            left: None,
            right: None,
        }
    }
}

// @lc code=start
use std::cell::RefCell;
use std::rc::Rc;

// 34/34 cases passed (0 ms)
// Your runtime beats 100 % of rust submissions
// Your memory usage beats 42.55 % of rust submissions (2.1 MB)
impl Solution {
    // DFS
    pub fn level_order(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<Vec<i32>> {
        let mut res = vec![];
        Self::dfs(root, 0, &mut res);
        res
    }

    fn dfs(root: Option<Rc<RefCell<TreeNode>>>, level: usize, res: &mut Vec<Vec<i32>>) {
        if let Some(node) = root {
            if level + 1 > res.len() {
                res.push(vec![]);
            }
            res[level].push(node.borrow().val);
            Self::dfs(node.borrow_mut().left.take(), level + 1, res);
            Self::dfs(node.borrow_mut().right.take(), level + 1, res);
        }
    }
}
// @lc code=end
