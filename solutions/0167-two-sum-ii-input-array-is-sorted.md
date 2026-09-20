# #167 — Two Sum II - Input Array Is Sorted

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | C++ |
| **Submitted** | 21 September 2026 at 02:46 am IST |
| **Runtime** | 0 ms *(beats 100.0%)* |
| **Memory** | 25.9 MB *(beats 5.4%)* |
| **Topics** | `Array` `Two Pointers` `Binary Search` |

🔗 [View on LeetCode](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/)

---

## 📋 Problem Description

You are given a **1-indexed** array of integers `numbers` that is already **sorted in non-decreasing order**.

Find **two** numbers such that they add up to a specific `target` number. Let these two numbers be `numbers[index_1]` and `numbers[index_2]` where `1 <= index_1 < index_2 <= numbers.length`.

Return the indices of the two numbers `index_1` and `index_2` as an integer array `[index_1, index_2]` of length 2.

The tests are generated such that there is **exactly one solution**. You **may not** use the same element twice.

Your solution must use only constant extra space.

 

**Example 1:**

```
**Input:** numbers = [2,7,11,15], target = 9
**Output:** [1,2]
**Explanation:** The sum of 2 and 7 is 9. Therefore, index_1 = 1, index_2 = 2. We return [1, 2].
```

**Example 2:**

```
**Input:** numbers = [2,3,4], target = 6
**Output:** [1,3]
**Explanation:** The sum of 2 and 4 is 6. Therefore index_1 = 1, index_2 = 3. We return [1, 3].
```

**Example 3:**

```
**Input:** numbers = [-1,0], target = -1
**Output:** [1,2]
**Explanation:** The sum of -1 and 0 is -1. Therefore index_1 = 1, index_2 = 2. We return [1, 2].
```

 

**Constraints:**

	- `2 <= numbers.length <= 3 * 10^4`

	- `-1000 <= numbers[i] <= 1000`

	- `numbers` is sorted in **non-decreasing order**.

	- `-1000 <= target <= 1000`

	- The tests are generated such that there is **exactly one solution**.

---

## ✅ Accepted Solution

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& num, int target) {
        unordered_map<int,int> mp;
        mp[num[0]]=0;
        int n=num.size();
        int req;
        for(int i=1;i<n;i++){
            req=target-num[i];
            auto it=mp.find(req);
            if(it!=mp.end()){
                return {1+it->second, 1+i};
            }
            mp[num[i]]=i;
        }
        return {-1,-1};
    }
};
```
