class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j, int& n, int& m) {
        grid[i][j] = '2';
        if (i + 1 < n && grid[i + 1][j] == '1')  dfs(grid, i + 1, j, n, m);
        if (j + 1 < m && grid[i][j + 1] == '1')  dfs(grid, i, j + 1, n, m);
        if (i - 1 >= 0 && grid[i - 1][j] == '1') dfs(grid, i - 1, j, n, m);
        if (j - 1 >= 0 && grid[i][j - 1] == '1') dfs(grid, i, j - 1, n, m);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size(), island = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j, n, m);
                    island++;
                }
            }
        }
        return island;
    }
};