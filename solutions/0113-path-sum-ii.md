# #113 — Path Sum II

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | C++ |
| **Submitted** | 30 September 2026 at 10:42 pm IST |
| **Runtime** | 0 ms *(beats 100.0%)* |
| **Memory** | 20.8 MB *(beats 88.1%)* |
| **Topics** | `Backtracking` `Tree` `Depth-First Search` `Binary Tree` |

🔗 [View on LeetCode](https://leetcode.com/problems/path-sum-ii/)

---

## 📋 Problem Description

Given the `root` of a binary tree and an integer `targetSum`, return *all **root-to-leaf** paths where the sum of the node values in the path equals *`targetSum`*. Each path should be returned as a list of the node **values**, not node references*.

A **root-to-leaf** path is a path starting from the root and ending at any leaf node. A **leaf** is a node with no children.

 

**Example 1:**

```
**Input:** root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
**Output:** [[5,4,11,2],[5,8,4,5]]
**Explanation:** There are two paths whose sum equals targetSum:
5 + 4 + 11 + 2 = 22
5 + 8 + 4 + 5 = 22
```

**Example 2:**

```
**Input:** root = [1,2,3], targetSum = 5
**Output:** []
```

**Example 3:**

```
**Input:** root = [1,2], targetSum = 0
**Output:** []
```

 

**Constraints:**

	- The number of nodes in the tree is in the range `[0, 5000]`.

	- `-1000 <= Node.val <= 1000`

	- `-1000 <= targetSum <= 1000`

---

## ✅ Accepted Solution

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution{
        void f(TreeNode* node, vector<vector<int>>& ans, vector<int>& curr, int sum){
            if(!node){
                return;
            }
            sum-=node->val;
            curr.push_back(node->val);
            if(node->left==nullptr && node->right==nullptr && sum==0){
                ans.push_back(curr);
                curr.pop_back();
                return;
            }
            
            f(node->left, ans, curr, sum);
            f(node->right, ans, curr, sum);
            curr.pop_back();
            return;
        }
	public:
		vector<vector<int>> pathSum(TreeNode* root, int targetSum){
            //your code goes here
            vector<vector<int>> ans;
            vector<int> curr;
            f(root, ans, curr, targetSum);
            return ans;
		}
};
```
