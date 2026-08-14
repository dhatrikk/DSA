# #38 — Count and Say

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | C++ |
| **Submitted** | 15 August 2026 at 04:32 am IST |
| **Runtime** | 6 ms *(beats 22.1%)* |
| **Memory** | 10.1 MB *(beats 34.2%)* |
| **Topics** | `String` |

🔗 [View on LeetCode](https://leetcode.com/problems/count-and-say/)

---

## 📋 Problem Description

The **count-and-say** sequence is a sequence of digit strings defined by the recursive formula:

	- `countAndSay(1) = "1"`

	- `countAndSay(n)` is the run-length encoding of `countAndSay(n - 1)`.

Run-length encoding (RLE) is a string compression method that works by replacing each maximal group of consecutive identical characters with the concatenation of the length of the group followed by the character itself. For example, to compress the string `"3322251"` we replace `"33"` with `"23"`, replace `"222"` with `"32"`, replace `"5"` with `"15"`, and replace `"1"` with `"11"`. Thus the compressed string becomes `"23321511"`.

Given a positive integer `n`, return *the *`n^th`* element of the **count-and-say** sequence*.

 

**Example 1:**

**Input:** n = 4

**Output:** "1211"

**Explanation:**

```
countAndSay(1) = "1"
countAndSay(2) = RLE of "1" = "11"
countAndSay(3) = RLE of "11" = "21"
countAndSay(4) = RLE of "21" = "1211"
```

**Example 2:**

**Input:** n = 1

**Output:** "1"

**Explanation:**

This is the base case.

 

**Constraints:**

	- `1 <= n <= 30`

 

**Follow up:** Could you solve it iteratively?

---

## ✅ Accepted Solution

```cpp
class Solution {
public:
    string countAndSay(int n) {
        if(n==1){
            return "1";
        }
        string s=countAndSay(n-1);

        int cnt=0;
        char ch=s[0];
        string ans="";

        for(char c:s){
            if(c==ch){
                cnt++;
            }else{
                ans+=to_string(cnt)+ch;
                ch=c;
                cnt=1;
            }
        }
        ans+=to_string(cnt)+ch;
        return ans;
    }
};



// class Solution {
//     void f(string& s){
//         string ss="";
//         int cnt=0;
//         char ch=s[0];
//         for(char c:s){
//             if(c==ch){
//                 cnt++;
//             }else{
//                 ss+=to_string(cnt)+ch;
//                 cnt=1;
//                 ch=c;
//             }
//         }
//         ss+=to_string(cnt)+ch;
//         s=ss;
//         return;
//     }
// public:
//     string countAndSay(int n) {
//         string s="1";
//         for(int i=0;i<n-1;i++){
//             f(s);
//         }
//         return s;
//     }
// };
```

---

## 💡 Hints

<details>
<summary>Click to reveal hints</summary>

**Hint 1:** Create a helper function that maps an integer to pairs of its digits and their frequencies. For example, if you call this function with "223314444411", then it maps it to an array of pairs [[2,2], [3,2], [1,1], [4,5], [1, 2]].

**Hint 2:** Create another helper function that takes the array of pairs and creates a new integer. For example, if you call this function with [[2,2], [3,2], [1,1], [4,5], [1, 2]], it should create "22"+"23"+"11"+"54"+"21" = "2223115421".

**Hint 3:** Now, with the two helper functions, you can start with "1" and call the two functions alternatively n-1 times. The answer is the last integer you will obtain.

</details>
