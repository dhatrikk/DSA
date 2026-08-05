# #493 — Reverse Pairs

| Field | Details |
|---|---|
| **Difficulty** | 🔴 Hard |
| **Language** | C++ |
| **Submitted** | 5 August 2026 at 12:25 pm IST |
| **Runtime** | 516 ms *(beats 49.8%)* |
| **Memory** | 245.4 MB *(beats 17.0%)* |
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
    void mrg(vector<int>& nums, int i, int mid, int j) {
        int l = i, r = mid + 1;
        vector<int> tmp;
        while (l <= mid && r <= j) {
            if (nums[l] <= nums[r]) {
                tmp.push_back(nums[l]);
                l++;
            } else {
                tmp.push_back(nums[r]);
                r++;
            }
        }
        while (l <= mid) {
            tmp.push_back(nums[l]);
            l++;
        }
        while (r <= j) {
            tmp.push_back(nums[r]);
            r++;
        }
        for (int x = i; x <= j; x++) {
            nums[x] = tmp[x - i];
        }
    }
    void f(vector<int>& nums, int i, int j, int& cnt) {
        if (i >= j) {
            return;
        }
        int mid = (i + j) / 2;
        f(nums, i, mid, cnt);
        f(nums, mid + 1, j, cnt);

        int l = i;
        for (int r = mid + 1; r <= j; r++) {
            while (l <= mid && nums[l] <= 2LL * nums[r]) {
                l++;
            }
            if (l > mid) {
                break;
            }
            cnt += (mid - l + 1);
        }

        mrg(nums, i, mid, j);
        return;
    }

public:
    int reversePairs(vector<int> nums) {
        int cnt = 0;
        f(nums, 0, nums.size() - 1, cnt);
        return cnt;
    }
};

// class Solution {
// public:
//     int reversePairs(vector<int>& nums) {
//         int ans=0;
//         int n=nums.size();

//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<n;j++){
//                 if(nums[i]/2.0>nums[j]){
//                     ans++;
//                 }
//             }
//         }
//         return ans;
//     }
// };
```

---

## 💡 Hints

<details>
<summary>Click to reveal hints</summary>

**Hint 1:** Use the merge-sort technique.

**Hint 2:** Divide the array into two parts and sort them.

**Hint 3:** For each integer in the first part, count the number of integers that satisfy the condition from the second part. Use the pointer to help you in the counting process.

</details>
