# #5 — Longest Palindromic Substring

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | C++ |
| **Submitted** | 7 August 2026 at 10:49 pm IST |
| **Runtime** | 75 ms *(beats 37.1%)* |
| **Memory** | 9.2 MB *(beats 92.0%)* |
| **Topics** | `Two Pointers` `String` `Dynamic Programming` `Manacher` |

🔗 [View on LeetCode](https://leetcode.com/problems/longest-palindromic-substring/)

---

## 📋 Problem Description

Given a string `s`, return *the longest* *palindromic* *substring* in `s`.

 

**Example 1:**

```
**Input:** s = "babad"
**Output:** "bab"
**Explanation:** "aba" is also a valid answer.
```

**Example 2:**

```
**Input:** s = "cbbd"
**Output:** "bb"
```

 

**Constraints:**

	- `1 <= s.length <= 1000`

	- `s` consist of only digits and English letters.

---

## ✅ Accepted Solution

```cpp
class Solution {
    bool f(string& s, int l, int r){
        while(l<r){
            if(s[l]!=s[r]){
                return 0;
            }
            l++;
            r--;
        }
        return 1;
    }
public:
    string longestPalindrome(string s) {
        int st=0, l=1;
        int n=s.size();

        for(int i=0;i<n;i++){
            for(int j=n-1;j>i+l-1;j--){
                if(f(s, i, j)){
                    st=i;
                    l=j-i+1;
                    break;
                }
            }
        }

        return s.substr(st,l);
    }
};

// class Solution {
//     bool isp(string& s, int x, int y){
//         for(int i=0;i<=(y-x)/2;i++){
//             if(s[x+i]!=s[y-i]){
//                 return false;
//             }
//         }
//         return true;
//     }
//     void f(string& s, int i, int j, int& a, int& b){
//         if(i>=j){
//             return;
//         }
//         if(isp(s, i, j)){
//             if(b-a<j-i){
//                 a=i;
//                 b=j;
//             }
//         }else{
//             f(s, i+1, j, a, b);
//             f(s, i, j-1, a, b);
//         }   
//     }
// public:
//     string longestPalindrome(string s) {
//         int a=0, b=0;
//         f(s, 0, s.size()-1, a, b);

//         string ans="";
//         for(int i=a; i<=b; i++){
//             ans+=s[i];
//         }
//         return ans;
//     }
// };
```

---

## 💡 Hints

<details>
<summary>Click to reveal hints</summary>

**Hint 1:** How can we reuse a previously computed palindrome to compute a larger palindrome?

**Hint 2:** If “aba” is a palindrome, is “xabax” a palindrome? Similarly is “xabay” a palindrome?

**Hint 3:** Complexity based hint:
If we use brute-force and check whether for every start and end position a substring is a palindrome we have O(n^2) start - end pairs and O(n) palindromic checks. Can we reduce the time for palindromic checks to O(1) by reusing some previous computation.

</details>
