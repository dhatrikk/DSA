# #1 — Two Sum

| Field | Details |
|---|---|
| **Difficulty** | 🟢 Easy |
| **Language** | C++ |
| **Submitted** | 6 July 2026 at 03:48 pm IST |
| **Runtime** | 0 ms *(beats 100.0%)* |
| **Memory** | 14.7 MB *(beats 54.9%)* |
| **Topics** | `Array` `Hash Table` |

🔗 [View on LeetCode](https://leetcode.com/problems/two-sum/)

---

## 📋 Problem Description

Given an array of integers `nums` and an integer `target`, return *indices of the two numbers such that they add up to `target`*.

You may assume that each input would have ***exactly* one solution**, and you may not use the *same* element twice.

You can return the answer in any order.

 

**Example 1:**

```
**Input:** nums = [2,7,11,15], target = 9
**Output:** [0,1]
**Explanation:** Because nums[0] + nums[1] == 9, we return [0, 1].
```

**Example 2:**

```
**Input:** nums = [3,2,4], target = 6
**Output:** [1,2]
```

**Example 3:**

```
**Input:** nums = [3,3], target = 6
**Output:** [0,1]
```

 

**Constraints:**

	- `2  time complexity?

---

## ✅ Accepted Solution

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        int n = nums.size();

        for(int i=0;i<n;i++){
            if(mp.size()){
                auto it=mp.find(target-nums[i]);
            if(it!=mp.end()){
                return {i,it->second};
            }
            }
            mp[nums[i]]=i;
        }
        
        return {-1,-1};
    }
};
```

---

## 💡 Hints

<details>
<summary>Click to reveal hints</summary>

**Hint 1:** A really brute force way would be to search for all possible pairs of numbers but that would be too slow. Again, it's best to try out brute force solutions just for completeness. It is from these brute force solutions that you can come up with optimizations.

**Hint 2:** So, if we fix one of the numbers, say `x`, we have to scan the entire array to find the next number `y` which is `value - x` where value is the input parameter. Can we change our array somehow so that this search becomes faster?

**Hint 3:** The second train of thought is, without changing the array, can we use additional space somehow? Like maybe a hash map to speed up the search?

</details>
