
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();    //行数
        int n = obstacleGrid[0].size(); //列数
        if(m==0 || n == 0) return 0;
        long long f[m][n];  //测试数据刁钻，开long long
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(obstacleGrid[i][j] == 1) f[i][j] = 0;    //如果0行、0列上有为1的单元格，那么其后都为0
                else{   
                    if(i == 0 && j == 0) f[i][j] = 1;   //初始状态,第一行、第一列的情况
                    else{
                        f[i][j] = 0;    //初始化为0
                        if(i >= 1) f[i][j] += f[i-1][j];    //如果左边有路，那么+=
                        if(j >= 1) f[i][j] += f[i][j-1];    //如果上边有路，那么+=
                    }
                }
            }
        }
        return f[m-1][n-1];
    }
};
