// 1.(leet-code题号：695)岛屿的最大面积
// 方法一：利用最初始的递归的思想来进行计算
int dfs(vector<vector<int>>&grid, int sea_i, int sea_j){
    if(sea_i<0 || sea_i==grid.size() || sea_j<0 || sea_j==grid[0].size() || grid[sea_i][sea_j]!=1){
        return 0;
    }
    grid[sea_i][sea_j] = 0;
    int res = 1;
    vector<int>di{0,0,1,-1};
    vector<int>dj{1,-1,0,0};
    for(int index = 0;index != 4; index++){
        int next_i = sea_i + di[index];
        int next_j = sea_j + dj[index];
        res += dfs(grid, next_i,next_j);
    }
    return res;
}
int maxAreaOfIsland(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size(), max_area = 0;
    for(int i = 0;i < m;i++){
        for(int j = 0;j < n;j++){
            max_area = max(max_area, dfs(grid, i,j));
        }
    }
    return max_area;
}
