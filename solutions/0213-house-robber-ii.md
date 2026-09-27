# #213 — House Robber II

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | C++ |
| **Submitted** | 27 September 2026 at 08:18 pm IST |
| **Runtime** | 0 ms *(beats 100.0%)* |
| **Memory** | 10.1 MB *(beats 97.0%)* |
| **Topics** | `Array` `Dynamic Programming` |

🔗 [View on LeetCode](https://leetcode.com/problems/house-robber-ii/)

---

## 📋 Problem Description

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are **arranged in a circle.** That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and **it will automatically contact the police if two adjacent houses were broken into on the same night**.

Given an integer array `nums` representing the amount of money of each house, return *the maximum amount of money you can rob tonight **without alerting the police***.

 

**Example 1:**

```
**Input:** nums = [2,3,2]
**Output:** 3
**Explanation:** You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
```

**Example 2:**

```
**Input:** nums = [1,2,3,1]
**Output:** 4
**Explanation:** Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
```

**Example 3:**

```
**Input:** nums = [1,2,3]
**Output:** 3
```

 

**Constraints:**

	- `1 <= nums.length <= 100`

	- `0 <= nums[i] <= 1000`

---

## ✅ Accepted Solution

```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }else if(n==2){
            return max(nums[0], nums[1]);
        }else if(n==3){
            return max(nums[0], max(nums[1], nums[2]));
        }

        int y1=nums[n-1], x1=max(nums[n-1], nums[n-2]);
        int curr;
        for(int i=n-3;i>0;i--){
            curr=max(nums[i]+y1, x1);
            y1=x1;
            x1=curr;
        }

        int y2=nums[n-2], x2=max(nums[n-3], nums[n-2]);
        for(int i=n-4;i>=0;i--){
            curr=max(nums[i]+y2, x2);
            y2=x2;
            x2=curr;
        }

        return max(x1, x2);
    }
};
```

---

## 💡 Hints

<details>
<summary>Click to reveal hints</summary>

**Hint 1:** Since House[1] and House[n] are adjacent, they cannot be robbed together. Therefore, the problem becomes to rob either House[1]-House[n-1] or House[2]-House[n], depending on which choice offers more money. Now the problem has degenerated to the House Robber, which is already been solved.

</details>
