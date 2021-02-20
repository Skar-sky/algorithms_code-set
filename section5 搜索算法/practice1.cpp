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

// 方法二：我们利用深度优先搜索和栈来进行问题的解决
int maxAreaOfIsland(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size(), area = 0, max_area = 0, next_i = 0, next_j = 0;
    vector<int>di{0,0,1,-1};
    vector<int>dj{1,-1,0,0};
    for(int i = 0;i < m;i++){
        for(int j = 0;j < n;j++){
            if(grid[i][j]){
                grid[i][j] = 0;
                area = 1;
                stack<pair<int,int>>island;    //创建一个栈，用以存放相应的位置
                island.push({i,j});            //将当前节点压入栈中
                while(!island.empty()){
                    auto [r,c] = island.top();      //取出为1的节点位置
                    island.pop();
                    for(int k = 0;k < 4;k++){
                        next_i = r + di[k];
                        next_j = c + dj[k];
                        if(next_i>=0 && next_j>=0 && next_i<m && next_j<n && grid[next_i][next_j] == 1){   //条件判断
                            area++;
                            grid[next_i][next_j] = 0;
                            island.push({next_i,next_j});  //切记要将后续的位置压入栈中，便于下一次搜索
                        }
                    } 
                }
                max_area = max(max_area, area);
            }
        }
    }
    return max_area;
}



// 2.(leet-code题号：547)省份数量
// 此题与前题不同之处在于我们这里每个节点可与n个点相连，我们仍旧采取深度优先搜索的方法进行搜索，仍旧是递归的思想
int findCircleNum(vector<vector<int>>& isConnected) {
    vector<bool>visited(isConnected.size(), false);
    int count = 0;
    for(int i = 0;i < isConnected.size();i++){
        if(!visited[i]){
            dfs(isConnected, i, visited);
            count++;
        }
    }
    return count;
}
void dfs(vector<vector<int>>& isConnected, int i, vector<bool>& visited){
    visited[i] = true;
    for(int j = 0;j < isConnected.size();j++){
        if(isConnected[i][j] == 1 && !visited[j]){
            dfs(isConnected, j, visited);
        }
    }
}



// 3.(leet-code题号：417)太平洋大西洋水流问题
// 该题同样也是考察深度优先搜索，我们采取与上述方法一致的算法解决问题
vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
    if(matrix.empty() || matrix[0].empty()){
        return {};
    }
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>>res;
    vector<vector<bool>>reach_p(m, vector<bool>(n, false));
    vector<vector<bool>>reach_a(m, vector<bool>(n, false));
    for(int i = 0;i < m;i++){
        dfs(matrix, reach_p, i, 0); //对能否到达太平洋进行判断，0即是表示左边界是可流入太平洋的
        dfs(matrix, reach_a, i, n-1); //对能否到达大西洋进行判断，n-1表示右边界是可流入大西洋的
    }
    for(int i = 0;i < n;i++){
        dfs(matrix, reach_p, 0, i); //对能否到达太平洋进行判断，0即是表示上边界是可流入太平洋的
        dfs(matrix, reach_a, m-1, i); //对能否到达大西洋进行判断，m-1表示下边界是可流入大西洋的
    }
    for(int i = 0;i < m;i++){
        for(int j = 0;j < n;j++){
            if(reach_a[i][j] && reach_p[i][j]){
                res.push_back({i,j});
            }
        }
    }
    return res;
}
void dfs(vector<vector<int>>& matrix, vector<vector<bool>>&reach, int r, int c){
    if(reach[r][c]){
        return;
    }
    int m = matrix.size(), n = matrix[0].size();
    reach[r][c] = true;
    int next_i = 0, next_j = 0;
    vector<int>di{0,0,1,-1};
    vector<int>dj{1,-1,0,0};
    for(int i = 0;i < 4;i++){
        next_i = r + di[i];
        next_j = c + dj[i];
        if(next_i>=0 && next_j>=0 && next_i<m && next_j<n && matrix[next_i][next_j]>=matrix[r][c]){
            dfs(matrix, reach, next_i, next_j);
        }
    }
}