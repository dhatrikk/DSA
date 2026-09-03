# #686 — Repeated String Match

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | C++ |
| **Submitted** | 4 September 2026 at 03:08 am IST |
| **Runtime** | 0 ms *(beats 100.0%)* |
| **Memory** | 10.3 MB *(beats 26.2%)* |
| **Topics** | `String` `String Matching` `Z Algorithm` `Knuth–Morris–Pratt Algorithm` `Boyer–Moore String-Search Algorithm` |

🔗 [View on LeetCode](https://leetcode.com/problems/repeated-string-match/)

---

## 📋 Problem Description

Given two strings `a` and `b`, return *the minimum number of times you should repeat string *`a`* so that string* `b` *is a substring of it*. If it is impossible for `b`​​​​​​ to be a substring of `a` after repeating it, return `-1`.

**Notice:** string `"abc"` repeated 0 times is `""`, repeated 1 time is `"abc"` and repeated 2 times is `"abcabc"`.

 

**Example 1:**

```
**Input:** a = "abcd", b = "cdabcdab"
**Output:** 3
**Explanation:** We return 3 because by repeating a three times "ab**cdabcdab**cd", b is a substring of it.
```

**Example 2:**

```
**Input:** a = "a", b = "aa"
**Output:** 2
```

 

**Constraints:**

	- `1 <= a.length, b.length <= 10^4`

	- `a` and `b` consist of lowercase English letters.

---

## ✅ Accepted Solution

```cpp
class Solution {
    int mod = 1e9 + 7;

    long long int pw(int x, int n){
        if(n==1){
            return x;
        }
        if(n==0){
            return 1;
        }
        long long int k=pw(x,n/2);
        if(n%2){
            return (((k*k)%mod)*x)%mod;
        }
        return (k*k)%mod;
    }
    

    bool ch(string a, string b, int& n, long long int& hash, int& base){
        long long int power= pw(base,n-1);
        long long int chash=0;
        for(int i=0;i<n;i++){
            chash*=base;
            chash+=(b[i]-'a'+1);
            chash%=mod;
        }

        for(int i=n;i<b.size();i++){
            if(chash==hash){
                if(a==b.substr(i-n,n)){
                    return true;
                }
            }
            chash= (chash - (b[i-n]-'a'+1)*power%mod +mod)%mod;
            chash= (chash * base)%mod;
            chash= (chash + (b[i]-'a'+1))%mod;
        }
        if(chash==hash){
                if(a==b.substr(b.size()-n,n)){
                    return true;
                }
            }
        return false;
    }
public:
    int repeatedStringMatch(string a, string b) {

        long long int hash=0;
        int base=31;

        for(char c:b){
            hash= (hash * base)%mod;
            hash= (hash + (c-'a'+1))%mod;
        }

        string ans="";
        int cnt=0;
        int n=b.size();
        while(ans.size()<b.size()){
            ans+=a;
            cnt++;
        }
        if(ch(b, ans, n, hash, base)){
            return cnt;
        }
        ans+=a;
        if(ch(b, ans, n, hash, base)){
            return cnt+1;
        }
        return -1;
    }
};
```
