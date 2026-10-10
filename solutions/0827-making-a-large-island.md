# #827 — Making A Large Island

| Field | Details |
|---|---|
| **Difficulty** | 🔴 Hard |
| **Language** | C++ |
| **Submitted** | 10 October 2026 at 04:04 pm IST |
| **Runtime** | 431 ms *(beats 12.1%)* |
| **Memory** | 176.4 MB *(beats 15.3%)* |
| **Topics** | `Array` `Depth-First Search` `Breadth-First Search` `Union-Find` `Matrix` |

🔗 [View on LeetCode](https://leetcode.com/problems/making-a-large-island/)

---

## 📋 Problem Description

You are given an `n x n` binary matrix `grid`. You are allowed to change **at most one** `0` to be `1`.

Return *the size of the largest **island** in* `grid` *after applying this operation*.

An **island** is a 4-directionally connected group of `1`s.

 

**Example 1:**

```
**Input:** grid = [[1,0],[0,1]]
**Output:** 3
**Explanation:** Change one 0 to 1 and connect two 1s, then we get an island with area = 3.
```

**Example 2:**

```
**Input:** grid = [[1,1],[1,0]]
**Output:** 4
**Explanation: **Change the 0 to 1 and make the island bigger, only one island with area = 4.
```

**Example 3:**

```
**Input:** grid = [[1,1],[1,1]]
**Output:** 4
**Explanation:** Can't change any 0 to 1, only one island with area = 4.
```

 

**Constraints:**

	- `n == grid.length`

	- `n == grid[i].length`

	- `1 <= n <= 500`

	- `grid[i][j]` is either `0` or `1`.

---

## ✅ Accepted Solution

```cpp
class Solution {
    pair<int,int> ult(int x, int y, vector<vector<pair<int,int>>>& rep){
        if(rep[x][y]==make_pair(x,y)){
            return {x,y};
        }
        return rep[x][y]= ult(rep[x][y].first, rep[x][y].second, rep);
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int r=grid.size(), c=grid[0].size();
        vector<vector<int>> sz(r, vector<int> (c,1));
        vector<vector<pair<int,int>>> rep(r, vector<pair<int,int>> (c));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                rep[i][j]={i,j};
            }
        }

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]){
                    int xx, yy;
                    vector<int> dx={1, -1, 0, 0};
                    for(int k=0;k<4;k++){
                        xx=i+dx[k];
                        yy=j+dx[3-k];
                        if(xx>=0 && yy>=0 && xx<r && yy<c && grid[xx][yy]){
                            auto pu = ult(xx, yy, rep);
                            auto pv = ult(i, j, rep);
                            if(pu==pv){
                                continue;
                            }
                            if(sz[pu.first][pu.second]>=sz[pv.first][pv.second]){
                                rep[pv.first][pv.second]=pu;
                                sz[pu.first][pu.second]+=sz[pv.first][pv.second];
                            }else{
                                rep[pu.first][pu.second]=pv;
                                sz[pv.first][pv.second]+=sz[pu.first][pu.second];
                            }
                        }
                    }
                }
            }
        }

        int ans=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==0){
                    int ngh=0;
                    vector<int> dx={1, -1, 0, 0};
                    set<pair<int,int>> st;
                    for(int k=0;k<4;k++){
                        int xx=i+dx[k];
                        int yy=j+dx[3-k];
                        if(xx>=0 && yy>=0 && xx<r && yy<c && grid[xx][yy]){
                            auto pu= ult(xx, yy, rep);
                            st.insert({pu.first, pu.second});
                        }
                    }
                    for(auto it=st.begin(); it!=st.end();it++){
                        ngh+=sz[it->first][it->second];
                    }
                    ans=max(ans, ngh+1);
                }else{
                    if(rep[i][j]==make_pair(i,j)){
                        ans=max(ans,sz[i][j]);
                    }
                }
            }
        }

        return ans;
    }
};
```
