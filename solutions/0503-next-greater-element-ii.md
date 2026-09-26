# #503 — Next Greater Element II

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | C++ |
| **Submitted** | 26 September 2026 at 06:22 am IST |
| **Runtime** | 0 ms *(beats 100.0%)* |
| **Memory** | 28.4 MB *(beats 62.1%)* |
| **Topics** | `Array` `Stack` `Monotonic Stack` |

🔗 [View on LeetCode](https://leetcode.com/problems/next-greater-element-ii/)

---

## 📋 Problem Description

Given a circular integer array `nums` (i.e., the next element of `nums[nums.length - 1]` is `nums[0]`), return *the **next greater number** for every element in* `nums`.

The **next greater number** of a number `x` is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return `-1` for this number.

 

**Example 1:**

```
**Input:** nums = [1,2,1]
**Output:** [2,-1,2]
Explanation: The first 1's next greater number is 2; 
The number 2 can't find next greater number. 
The second 1's next greater number needs to search circularly, which is also 2.
```

**Example 2:**

```
**Input:** nums = [1,2,3,4,3]
**Output:** [2,3,4,-1,4]
```

 

**Constraints:**

	- `1 <= nums.length <= 10^4`

	- `-10^9 <= nums[i] <= 10^9`

---

## ✅ Accepted Solution

```cpp
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n=nums.size();
        vector<int> ans(n);

        for(int i=2*n-1;i>=0;i--){
            while(!st.empty() && nums[i%n]>=st.top()){
                st.pop();
            }
            if(st.size()){
                ans[i%n]=st.top();
            }else{
                ans[i%n]=-1;
            }
            st.push(nums[i%n]);
        }
        
        return ans;
    }
};
```
