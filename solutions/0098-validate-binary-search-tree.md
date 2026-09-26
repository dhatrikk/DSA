# #98 — Validate Binary Search Tree

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | C++ |
| **Submitted** | 27 September 2026 at 02:53 am IST |
| **Runtime** | 0 ms *(beats 100.0%)* |
| **Memory** | 21.9 MB *(beats 74.5%)* |
| **Topics** | `Tree` `Depth-First Search` `Binary Search Tree` `Binary Tree` |

🔗 [View on LeetCode](https://leetcode.com/problems/validate-binary-search-tree/)

---

## 📋 Problem Description

Given the `root` of a binary tree, *determine if it is a valid binary search tree (BST)*.

A **valid BST** is defined as follows:

	- The left subtree of a node contains only nodes with keys **strictly less than** the node's key.

	- The right subtree of a node contains only nodes with keys **strictly greater than** the node's key.

	- Both the left and right subtrees must also be binary search trees.

 

**Example 1:**

```
**Input:** root = [2,1,3]
**Output:** true
```

**Example 2:**

```
**Input:** root = [5,1,4,null,null,3,6]
**Output:** false
**Explanation:** The root node's value is 5 but its right child's value is 4.
```

 

**Constraints:**

	- The number of nodes in the tree is in the range `[1, 10^4]`.

	- `-2^31 <= Node.val <= 2^31 - 1`

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
class Solution {
    bool f(TreeNode* node, long long int x, long long int y){
        if(!node){
            return true;
        }
        if(node->val<=x || node->val>=y){
            return false;
        }
        return f(node->left, x, node->val) && f(node->right, node->val, y);
    }
public:
    bool isValidBST(TreeNode* root) {
        return f(root, 1ll*INT_MIN-10, 1ll*INT_MAX+10);
   } 
};
```
