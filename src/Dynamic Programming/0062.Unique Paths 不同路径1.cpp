class Solution {
public:
    int uniquePaths(int m, int n) {
        //行走方向只有右和下，则单元格的路径数即为两个方向的合
        //状态转移方程:f[i-1][j-1] = f[i-2][j-1] + f[i-1][j-2];
        int f[m][n];
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(i == 0 || j == 0) f[i][j] = 1;   //初始条件
                else f[i][j] = f[i-1][j] + f[i][j-1];
            }
        }
        return f[m-1][n-1];
    }
};
