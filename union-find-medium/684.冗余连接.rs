/*
 * @lc app=leetcode.cn id=684 lang=rust
 *
 * [684] 冗余连接
 */

// @lc code=start
impl Solution {
    // 39/39 cases passed (0 ms)
    // Your runtime beats 100 % of rust submissions
    // Your memory usage beats 16.67 % of rust submissions (2.2 MB)
    pub fn find_redundant_connection(edges: Vec<Vec<i32>>) -> Vec<i32> {
        let n = edges.len();
        let mut parents = vec![0usize; n + 1];
        (1..=n).for_each(|i| parents[i] = i);

        fn find(parents: &mut Vec<usize>, index: usize) -> usize {
            if parents[index] != index {
                parents[index] = find(parents, parents[index]);
            }
            parents[index]
        }

        fn union(parents: &mut Vec<usize>, a: usize, b: usize) {
            let parents_of_a = find(parents, a);
            parents[parents_of_a] = find(parents, b);
        }

        for edge in edges.iter() {
            if find(&mut parents, edge[0] as usize) != find(&mut parents, edge[1] as usize) {
                union(&mut parents, edge[0] as usize, edge[1] as usize);
            } else {
                return edge.clone();
            }
        }

        vec![]
    }
}
// @lc code=end

impl Solution_0 {
    // 39/39 cases passed (0 ms)
    // Your runtime beats 100 % of rust submissions
    // Your memory usage beats 66.67 % of rust submissions (2 MB)
    pub fn find_redundant_connection(edges: Vec<Vec<i32>>) -> Vec<i32> {
        let n = edges.len();
        let mut parents = vec![0; n + 1];
        (1..=n).for_each(|i| parents[i] = i);
        for i in 0..n {
            let mut a = edges[i][0] as usize;
            let mut b = edges[i][1] as usize;
            while parents[a] != a {
                a = parents[a];
            }
            while parents[b] != b {
                b = parents[b];
            }
            if a != b {
                parents[b] = a;
            } else {
                return edges[i].clone();
            }
        }
        Vec::new()
    }
}
