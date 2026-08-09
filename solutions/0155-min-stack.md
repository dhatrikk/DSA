# #155 — Min Stack

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | C++ |
| **Submitted** | 9 August 2026 at 04:16 pm IST |
| **Runtime** | 55 ms *(beats 67.6%)* |
| **Memory** | 151.1 MB *(beats 78.8%)* |
| **Topics** | `Stack` `Design` |

🔗 [View on LeetCode](https://leetcode.com/problems/min-stack/)

---

## 📋 Problem Description

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the `MinStack` class:

	- `MinStack()` initializes the stack object.

	- `void push(int value)` pushes the element `value` onto the stack.

	- `void pop()` removes the element on the top of the stack.

	- `int top()` gets the top element of the stack.

	- `int getMin()` retrieves the minimum element in the stack.

You must implement a solution with `O(1)` time complexity for each function.

 

**Example 1:**

```
**Input**
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

**Output**
[null,null,null,null,-3,null,0,-2]

**Explanation**
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
```

 

**Constraints:**

	- `-2^31 <= val <= 2^31 - 1`

	- Methods `pop`, `top` and `getMin` operations will always be called on **non-empty** stacks.

	- At most `3 * 10^4` calls will be made to `push`, `pop`, `top`, and `getMin`.

---

## ✅ Accepted Solution

```cpp
class MinStack {
    long long mn=INT_MAX;
    stack<long long> st;
public:
    MinStack() {
        
    }
    
    void push(int value) {
        if(st.empty()){
            st.push(value);
            mn=value;
        }else{
            if(value<mn){
                st.push(2ll*value-mn);
                mn=value;
            }else{
                st.push(value);
            }
        }
    }
    
    void pop() {
        if(!st.empty()){
            long long x=st.top();
            st.pop();
            if(x>mn){
                return;
            }else{
                mn=2*mn-x;
            }
        }
    }
    
    int top() {
        if(!st.empty()){
            long long x=st.top();
            if(x>mn){
                return x;
            }
            return mn;
        }
        return 0;
    }
    
    int getMin() {
        return mn;
    }
};






// class MinStack {
//      stack<pair<int, int>> st;
// public:
//     MinStack() {}

//     void push(int value) {
//         int m = value;
//         if (!st.empty()) {
//             m = min(value, st.top().second);
//         }
//         st.push({value, m});
//     }

//     void pop() { st.pop(); }

//     int top() { return st.top().first; }

//     int getMin() { return st.top().second; }
// };







/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
```

---

## 💡 Hints

<details>
<summary>Click to reveal hints</summary>

**Hint 1:** Consider each node in the stack having a minimum value. (Credits to @aakarshmadhavan)

</details>
