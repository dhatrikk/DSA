# #145 — Binary Tree Postorder Traversal

| Field | Details |
|---|---|
| **Difficulty** | 🟢 Easy |
| **Language** | C++ |
| **Submitted** | 23 July 2026 at 02:51 pm IST |
| **Runtime** | 0 ms *(beats 100.0%)* |
| **Memory** | 10.9 MB *(beats 93.5%)* |
| **Topics** | `Stack` `Tree` `Depth-First Search` `Binary Tree` |

🔗 [View on LeetCode](https://leetcode.com/problems/binary-tree-postorder-traversal/)

---

## 📋 Problem Description

Given the `root` of a binary tree, return *the postorder traversal of its nodes' values*.

 

**Example 1:**

**Input:** root = [1,null,2,3]

**Output:** [3,2,1]

**Explanation:**

**Example 2:**

**Input:** root = [1,2,3,4,5,null,8,null,null,6,7,9]

**Output:** [4,6,7,5,2,9,8,3,1]

**Explanation:**

**Example 3:**

**Input:** root = []

**Output:** []

**Example 4:**

**Input:** root = [1]

**Output:** [1]

 

**Constraints:**

	- The number of the nodes in the tree is in the range `[0, 100]`.

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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) {
            return {};
        }

        vector<int> ans;
        stack<TreeNode*> st;

        TreeNode* node = root;
        TreeNode* temp;

        while (node || st.size()) {
            if (node) {
                st.push(node);
                node = node->left;
            } else {
                temp = st.top()->right;
                if (temp) {
                    node = temp;
                } else {
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->val);
                    while (st.size() && st.top()->right == temp) {
                        temp = st.top();
                        st.pop();
                        ans.push_back(temp->val);
                    }
                }
            }
        }
        return ans;
    }
};
```
