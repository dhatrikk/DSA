# #130 — Surrounded Regions

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | C++ |
| **Submitted** | 22 September 2026 at 01:10 am IST |
| **Runtime** | 0 ms *(beats 100.0%)* |
| **Memory** | 15.2 MB *(beats 18.9%)* |
| **Topics** | `Array` `Depth-First Search` `Breadth-First Search` `Union-Find` `Matrix` |

🔗 [View on LeetCode](https://leetcode.com/problems/surrounded-regions/)

---

## 📋 Problem Description

You are given an `m x n` matrix `board` containing **letters** `'X'` and `'O'`, **capture regions** that are **surrounded**:

	- **Connect**: A cell is connected to adjacent cells horizontally or vertically.

	- **Region**: To form a region **connect every** `'O'` cell.

	- **Surround**: A region is surrounded if none of the `'O'` cells in that region are on the edge of the board. Such regions are **completely enclosed **by `'X'` cells.

To capture a **surrounded region**, replace all `'O'`s with `'X'`s **in-place** within the original board. You do not need to return anything.

 

**Example 1:**

**Input:** board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]

**Output:** [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]

**Explanation:**

In the above diagram, the bottom region is not captured because it is on the edge of the board and cannot be surrounded.

**Example 2:**

**Input:** board = [["X"]]

**Output:** [["X"]]

 

**Constraints:**

	- `m == board.length`

	- `n == board[i].length`

	- `1 <= m, n <= 200`

	- `board[i][j]` is `'X'` or `'O'`.

---

## ✅ Accepted Solution

```cpp
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int r=board.size(), c=board[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(r, vector<int> (c,0));

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if((i==0 || i==r-1 || j==0 || j==c-1) && board[i][j]=='O'){
                    q.push({i,j});
                    vis[i][j]=1;
                } 
            }
        }
        int x,y,xx,yy;
        int dx[]= {1,-1,0,0};

        while(!q.empty()){
            x=q.front().first;
            y=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                xx=x+dx[i];
                yy=y+dx[3-i];
                if(xx>=0 && yy>=0 && xx<r && yy<c && board[xx][yy]=='O' && vis[xx][yy]==0){
                    vis[xx][yy]=1;
                    q.push({xx,yy});
                }
            }
        }

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(vis[i][j]==0 && board[i][j]=='O'){
                    board[i][j]='X';
                } 
            }
        }
    }
};
```
