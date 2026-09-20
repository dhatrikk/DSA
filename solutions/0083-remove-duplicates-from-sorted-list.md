# #83 — Remove Duplicates from Sorted List

| Field | Details |
|---|---|
| **Difficulty** | 🟢 Easy |
| **Language** | C++ |
| **Submitted** | 21 September 2026 at 02:36 am IST |
| **Runtime** | 0 ms *(beats 100.0%)* |
| **Memory** | 16.3 MB *(beats 9.9%)* |
| **Topics** | `Linked List` |

🔗 [View on LeetCode](https://leetcode.com/problems/remove-duplicates-from-sorted-list/)

---

## 📋 Problem Description

Given the `head` of a sorted linked list, *delete all duplicates such that each element appears only once*. Return *the linked list **sorted** as well*.

 

**Example 1:**

```
**Input:** head = [1,1,2]
**Output:** [1,2]
```

**Example 2:**

```
**Input:** head = [1,1,2,3,3]
**Output:** [1,2,3]
```

 

**Constraints:**

	- The number of nodes in the list is in the range `[0, 300]`.

	- `-100 <= Node.val <= 100`

	- The list is guaranteed to be **sorted** in ascending order.

---

## ✅ Accepted Solution

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        ListNode* curr=head;
        ListNode* runn=head;
        while(runn->next){
            runn=runn->next;
            if(runn->val!=curr->val){
                curr->next=runn;
                curr=curr->next;
            }
        }
        curr->next=nullptr;
        return head;
    }
};
```
