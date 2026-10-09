# #493 — Reverse Pairs

| Field | Details |
|---|---|
| **Difficulty** | 🔴 Hard |
| **Language** | C++ |
| **Submitted** | 9 October 2026 at 02:20 pm IST |
| **Runtime** | 544 ms *(beats 28.0%)* |
| **Memory** | 240.1 MB *(beats 70.4%)* |
| **Topics** | `Array` `Binary Search` `Divide and Conquer` `Binary Indexed Tree` `Segment Tree` `Merge Sort` `Ordered Set` `Treap` |

🔗 [View on LeetCode](https://leetcode.com/problems/reverse-pairs/)

---

## 📋 Problem Description

Given an integer array `nums`, return *the number of **reverse pairs** in the array*.

A **reverse pair** is a pair `(i, j)` where:

	- `0  2 * nums[j]`.

 

**Example 1:**

```
**Input:** nums = [1,3,2,3,1]
**Output:** 2
**Explanation:** The reverse pairs are:
(1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1
```

**Example 2:**

```
**Input:** nums = [2,4,3,5,1]
**Output:** 3
**Explanation:** The reverse pairs are:
(1, 4) --> nums[1] = 4, nums[4] = 1, 4 > 2 * 1
(2, 4) --> nums[2] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 5, nums[4] = 1, 5 > 2 * 1
```

 

**Constraints:**

	- `1 <= nums.length <= 5 * 10^4`

	- `-2^31 <= nums[i] <= 2^31 - 1`

---

## ✅ Accepted Solution

```cpp
class Solution {
public:
    void mrg(vector<int>& nums, int l1, int r1, int r2, int& cnt) {
        int l2 = r1 + 1, i = l1, l = l1;
        for (int j = l2; j <= r2; j++) {
            while (i < r1 && nums[i] / 2.0 <= nums[j]) {
                i++;
            }
            if (nums[i] / 2.0 > nums[j]) {
                cnt += (l2 - i);
            }
        }
        vector<int> tmp;
        while (l1 <= r1 && l2 <= r2) {
            if (nums[l1] < nums[l2]) {
                tmp.push_back(nums[l1]);
                l1++;
            } else {
                tmp.push_back(nums[l2]);
                l2++;
            }
        }
        while (l1 <= r1) {
            tmp.push_back(nums[l1]);
            l1++;
        }
        while (l2 <= r2) {
            tmp.push_back(nums[l2]);
            l2++;
        }

        for (int i = l; i <= r2; i++) {
            nums[i] = tmp[i - l];
        }
    }

    void f(vector<int>& nums, int l, int r, int& cnt) {
        if (l >= r) {
            return;
        }
        int mid = l + (r - l) / 2;
        f(nums, l, mid, cnt);
        f(nums, mid + 1, r, cnt);
        mrg(nums, l, mid, r, cnt);
    }

    int reversePairs(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        int cnt = 0;
        f(nums, l, r, cnt);
        return cnt;
    }
};
```

---

## 💡 Hints

<details>
<summary>Click to reveal hints</summary>

**Hint 1:** Use the merge-sort technique.

**Hint 2:** Divide the array into two parts and sort them.

**Hint 3:** For each integer in the first part, count the number of integers that satisfy the condition from the second part. Use the pointer to help you in the counting process.

</details>
