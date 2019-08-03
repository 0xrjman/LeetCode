class Solution {
private:
    void dfs(vector<vector<int> >&g,int i,int j){
        if(i >= 0 && j>= 0 && i < g.size() && j < g.size() && g[i][j] == 0){
            //边界条件
            g[i][j] = 1;
            dfs(g,i - 1, j);
            dfs(g,i + 1, j);
            dfs(g,i, j - 1);
            dfs(g,i, j + 1);
        }
    }
public:
    int regionsBySlashes(vector<string>& grid) {
        int regions = 0;    //初始区域数 = 0
        auto n = grid.size();
        vector<vector<int> > g(n*3,vector<int>(n*3,0));
        for(auto i = 0; i < n;i++){ //遍历数组
            for(auto j = 0;j < n;j++){
                if(grid[i][j] == '/'){
                    g[i*3][j*3+2] = g[i*3+1][j*3+1] = g[i*3+2][j*3] = 1;
                    //. . .   ---> . . *    //单元格的像素表示示意图
                    //. . .   ---> . * .
                    //. . .   ---> * . .
                }
                if(grid[i][j] == '\\'){
                    g[i*3][j*3] = g[i*3+1][j*3+1] = g[i*3+2][j*3+2] = 1;
                    //. . .   ---> . . *    //单元格的像素表示示意图
                    //. . .   ---> . * .
                    //. . .   ---> * . .
                }
            }
        }
        //构造每个单元格为3*3的像素网格 vector<int> (n,0) ---> n个值为0的元素
        for(auto i = 0;i < g.size();i++){
            for(auto j = 0;j < g.size();j++){
                if(g[i][j] == 0){
                    dfs(g,i,j);
                    regions++;
                }
            }
        }
        return regions;
    }
};
