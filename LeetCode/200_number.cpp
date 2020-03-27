class Solution {
public:
    const int GRID_DIR_4[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> lands;
        int row = grid.size();
        if(row == 0) return 0; 
        int col = grid[0].size();
        
        for(int i = 0; i < row; i++) {
            for(int j = 0; j <  col; j++) {
                //printf("%c", grid[i][j]);
                if(grid[i][j] == '1') {
                    vector<int> cell;
                    cell.push_back(i);
                    cell.push_back(j);
                    
                    lands.push_back(cell);
                }
            }
        }
        
        int l = lands.size();
        int count = 0;
        for(int i = 0; i < l; i++) {
            //printf("%d, %d", lands[i][0], lands[i][1]);
            if(grid[lands[i][0]][lands[i][1]] == 'v') continue;
            count++;
            dfs(grid, lands[i], row, col);
        }
        
        return count;
    }
    
    void dfs(vector<vector<char>>& grid, vector<int>& src, int row, int col) {
        if(!withinGrid(src, row, col) || grid[src[0]][src[1]] == '0' || grid[src[0]][src[1]] == 'v') return;
        
        grid[src[0]][src[1]] = 'v';
        
        for(int i = 0; i < 4; i++) {
            vector<int> a;
            a.push_back(src[0] + GRID_DIR_4[i][0]);
            a.push_back(src[1] + GRID_DIR_4[i][1]);
            
            dfs(grid, a, row, col);
        }
    }
    
    bool withinGrid(vector<int>& cell, int row, int col) {
        if(cell[0] >= 0 && cell[1] >= 0 && cell[0] < row && cell[1] < col) return true;
        return false;
    }
};