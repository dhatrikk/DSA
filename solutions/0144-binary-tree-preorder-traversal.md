# #144 — Binary Tree Preorder Traversal

| Field | Details |
|---|---|
| **Difficulty** | 🟢 Easy |
| **Language** | C++ |
| **Submitted** | 11 July 2026 at 09:18 am IST |
| **Runtime** | 0 ms *(beats 100.0%)* |
| **Memory** | 10.8 MB *(beats 73.7%)* |
| **Topics** | `Stack` `Tree` `Depth-First Search` `Binary Tree` |

🔗 [View on LeetCode](https://leetcode.com/problems/binary-tree-preorder-traversal/)

---

## 📋 Problem Description

Given the `root` of a binary tree, return *the preorder traversal of its nodes' values*.

 

**Example 1:**

**Input:** root = [1,null,2,3]

**Output:** [1,2,3]

**Explanation:**

**Example 2:**

**Input:** root = [1,2,3,4,5,null,8,null,null,6,7,9]

**Output:** [1,2,4,5,6,7,3,8,9]

**Explanation:**

**Example 3:**

**Input:** root = []

**Output:** []

**Example 4:**

**Input:** root = [1]

**Output:** [1]

 

**Constraints:**

	- The number of nodes in the tree is in the range `[0, 100]`.

	- `-100 <= Node.val <= 100`

 

**Follow up:** Recursive solution is trivial, could you do it iteratively?

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
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root){
            return {};
        }
        stack<TreeNode*> st;
        vector<int> ans;

        st.push(root);
        TreeNode* n;

        while(!st.empty()){
            n=st.top();
            st.pop();
            ans.push_back(n->val);
            if(n->right){
                st.push(n->right);
            }
            if(n->left){
                st.push(n->left);
            }
        }
        return ans;
    }
};
```
