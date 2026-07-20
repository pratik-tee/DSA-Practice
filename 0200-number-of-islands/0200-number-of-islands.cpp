class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size(), count = 0;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        queue<pair<int,int>> q;
          int nr[] = {-1, 0, 1, 0};
        int nc[] = {0, 1, 0, -1};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]=='1' && !visited[i][j]) {
                    q.push({i,j});
                    visited[i][j] = 1;
                    while (!q.empty()) {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                            for (int k = 0; k < 4; k++) {
                                int nx = x + nr[k];
                                int ny = y + nc[k];
                                if (nx >= 0 && nx < grid.size() && ny >= 0 &&
                                    ny < grid[0].size() && grid[nx][ny] == '1' &&
                                    !visited[nx][ny]) {
                                    visited[nx][ny] = 1;
                                    q.push({nx,ny});
                                }
                            }
                    }
                    count++;
                }
            }
        }
        return count;
    }
};