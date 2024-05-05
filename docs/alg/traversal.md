<!--
 Copyright 2024 Gavin Gao. All rights reserved.
 Use of this source code is governed by a BSD-style
 license that can be found in the LICENSE file.
-->

# Traversal

---

## DFS (Depth-First Search)

* complement: recursion

### Graph

### Binary Tree

* Preorder Traversal

* Inorder Traversal
    - 二叉搜索树的中序遍历为 递增序列 

* Postorder Traversal
  ```cpp
  vector<int> *res;
  void dfs(TreeNode* node) {
      if(node->left != nullptr) dfs(node->left);
      if(node->right != nullptr) dfs(node->right);
      res->push_back(node->val);
  }
  vector<int> preorderTraversal(TreeNode* root) {
      res = new vector<int>();
      if(root != nullptr) dfs(root);
      return *res;
  }
  ```


## BFS (Breadth-First Search)

* complement: iteration / circulation

### Binary Tree

* Level-order Traversal
  ```cpp
  vector<vector<int>> levelOrder(TreeNode* root) {
      vector<vector<int>> ret;
      if(root == nullptr) return ret;

      queue<TreeNode*> q;
      q.push(root);
      while(!q.empty()) {
          int sz = q.size();
          ret.push_back(vector<int>());
          for(int i=0; i<sz; i++) {
              auto node = q.front(); q.pop();
              ret.back().push_back(node->val);
              if(node->left != nullptr) q.push(node->left);
              if(node->right != nullptr) q.push(node->right);
          }
      }

      return ret;
  }
  ```


## BFS (Best-First Search)

* Dijkstra Algorithm


## LeetCode

* leetcode 200: 岛屿数量
  ```cpp
  int nr = 0;
  int nc = 0;
  const int dx[4] = {0, 0, -1, 1};
  const int dy[4] = {-1, 1, 0, 0};

  void dfs(vector<vector<char>>& grid, int r, int c) {
      grid[r][c] = '0';

      if(r-1>=0 && grid[r-1][c] == '1') dfs(grid, r-1, c);
      if(r+1<nr && grid[r+1][c] == '1') dfs(grid, r+1, c);
      if(c-1>=0 && grid[r][c-1] == '1') dfs(grid, r, c-1);
      if(c+1<nc && grid[r][c+1] == '1') dfs(grid, r, c+1);
  }

  void bfs(vector<vector<char>>& grid, int r, int c) {
      queue<std::pair<int,int>> que;
      que.push({r,c});
      grid[r][c] = '0';

      while(!que.empty()) {
          auto rc = que.front();
          que.pop();
          for(int i=0; i<4; i++) {
              int y = rc.first + dy[i];
              int x = rc.second + dx[i];
              if(x>=0 && x<nc && y>=0 && y<nr && grid[y][x]=='1') {
                  que.push({y, x});
                  grid[y][x] = '0';
              }
          }
      }
  }

  int numIslands(vector<vector<char>>& grid) {
      nr = grid.size();
      if(nr == 0) return nr;
      nc = grid[0].size();

      int num = 0;
      for(int y=0; y<nr; y++) {
          for(int x=0; x<nc; x++) {
              if(grid[y][x] == '1') {
                  num++;
                  bfs(grid, y, x);
              }
          }
      }
      return num;
  }
  ```

