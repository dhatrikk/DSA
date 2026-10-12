# #1248 — Count Number of Nice Subarrays

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | C++ |
| **Submitted** | 12 October 2026 at 11:24 pm IST |
| **Runtime** | 0 ms *(beats 100.0%)* |
| **Memory** | 75.5 MB *(beats 27.4%)* |
| **Topics** | `Array` `Hash Table` `Math` `Sliding Window` `Prefix Sum` |

🔗 [View on LeetCode](https://leetcode.com/problems/count-number-of-nice-subarrays/)

---

## 📋 Problem Description

Given an array of integers `nums` and an integer `k`. A continuous subarray is called **nice** if there are `k` odd numbers on it.

Return *the number of **nice** sub-arrays*.

 

**Example 1:**

```
**Input:** nums = [1,1,2,1,1], k = 3
**Output:** 2
**Explanation:** The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
```

**Example 2:**

```
**Input:** nums = [2,4,6], k = 1
**Output:** 0
**Explanation:** There are no odd numbers in the array.
```

**Example 3:**

```
**Input:** nums = [2,2,2,1,2,2,1,2,2,2], k = 2
**Output:** 16
```

 

**Constraints:**

	- `1 <= nums.length <= 50000`

	- `1 <= nums[i] <= 10^5`

	- `1 <= k <= nums.length`

---

## ✅ Accepted Solution

```cpp
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int> ind;
        int n=nums.size();
        ind.push_back(-1);
        for(int i=0;i<n;i++){
            if(nums[i]%2){
                ind.push_back(i);
            }
        }
        ind.push_back(n);
        int s=ind.size(), ans=0;
        for(int r=k;r<s-1;r++){
            ans+=((ind[r-k+1]-ind[r-k])*(ind[r+1]-ind[r]));
        }

        return ans;
    }
};
```

---

## 💡 Hints

<details>
<summary>Click to reveal hints</summary>

**Hint 1:** After replacing each even by zero and every odd by one can we use prefix sum to find answer ?

**Hint 2:** Can we use two pointers to count number of sub-arrays ?

**Hint 3:** Can we store the indices of odd numbers and for each k indices count the number of sub-arrays that contains them ?

</details>
