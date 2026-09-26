# #230 — Kth Smallest Element in a BST

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | C++ |
| **Submitted** | 27 September 2026 at 02:06 am IST |
| **Runtime** | 0 ms *(beats 100.0%)* |
| **Memory** | 24.4 MB *(beats 70.8%)* |
| **Topics** | `Tree` `Depth-First Search` `Binary Search Tree` `Binary Tree` |

🔗 [View on LeetCode](https://leetcode.com/problems/kth-smallest-element-in-a-bst/)

---

## 📋 Problem Description

Given the `root` of a binary search tree, and an integer `k`, return *the* `k^th` *smallest value (**1-indexed**) of all the values of the nodes in the tree*.

 

**Example 1:**

```
**Input:** root = [3,1,4,null,2], k = 1
**Output:** 1
```

**Example 2:**

```
**Input:** root = [5,3,6,2,4,null,null,1], k = 3
**Output:** 3
```

 

**Constraints:**

	- The number of nodes in the tree is `n`.

	- `1 <= k <= n <= 10^4`

	- `0 <= Node.val <= 10^4`

 

**Follow up:** If the BST is modified often (i.e., we can do insert and delete operations) and you need to find the kth smallest frequently, how would you optimize?

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
    int f(TreeNode* node, int& cnt, int k){
        if(!node){
            return -1;
        }
        int left = f(node->left, cnt, k);
        if(left!=-1){
            return left;
        }
        cnt++;
        if(cnt==k) return node->val; 

        return f(node->right, cnt, k);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        int cnt=0;
        return f(root, cnt, k);
    }
};
```

---

## 💡 Hints

<details>
<summary>Click to reveal hints</summary>

**Hint 1:** Try to utilize the property of a BST.

**Hint 2:** Try in-order traversal. (Credits to @chan13)

**Hint 3:** What if you could modify the BST node's structure?

**Hint 4:** The optimal runtime complexity is O(height of BST).

</details>
