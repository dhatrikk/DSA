# #199 — Binary Tree Right Side View

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | C++ |
| **Submitted** | 25 July 2026 at 04:30 pm IST |
| **Runtime** | 0 ms *(beats 100.0%)* |
| **Memory** | 15 MB *(beats 41.3%)* |
| **Topics** | `Tree` `Depth-First Search` `Breadth-First Search` `Binary Tree` |

🔗 [View on LeetCode](https://leetcode.com/problems/binary-tree-right-side-view/)

---

## 📋 Problem Description

Given the `root` of a binary tree, imagine yourself standing on the **right side** of it, return *the values of the nodes you can see ordered from top to bottom*.

 

**Example 1:**

**Input:** root = [1,2,3,null,5,null,4]

**Output:** [1,3,4]

**Explanation:**

**Example 2:**

**Input:** root = [1,2,3,4,null,null,null,5]

**Output:** [1,3,4,5]

**Explanation:**

**Example 3:**

**Input:** root = [1,null,3]

**Output:** [1,3]

**Example 4:**

**Input:** root = []

**Output:** []

 

**Constraints:**

	- The number of nodes in the tree is in the range `[0, 100]`.

	- `-100 <= Node.val <= 100`

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
    vector<int> rightSideView(TreeNode* root) {
        if(!root){
            return {};
        }
        vector<int> ans;
        int n,s=0;
        queue<TreeNode*> q;
        TreeNode* node;
        q.push(root);

        while(!q.empty()){
            n=q.size();
            ans.push_back(-1);
            for(int i=0;i<n;i++){
                node=q.front();
                q.pop();
                if(ans[s]==-1){
                    ans[s]=node->val;
                }
                if(node->right){
                    q.push(node->right);
                }
                if(node->left){
                    q.push(node->left);
                }
            }
            s++;
        }
        return ans;
    }
};
```
