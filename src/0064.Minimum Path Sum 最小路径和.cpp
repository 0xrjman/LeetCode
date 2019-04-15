class Solution {    //最小路径和
public:
    const int inf = 0x3f3f3f3f;
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(m == 0 || n == 0) return 0;  //根据题意是否为空
        int f[2][n];        //滚动数组
        int old,now = 0;    //old 是行i-1 ,now 是行i
        for(int i = 0;i < m;i++){   
            old = now;      //滚动实现语句
            now = 1 - now;  
            for(int j = 0;j < n;j++){
                int t1,t2;
                if(i == 0 && j == 0){
                    f[now][j] = grid[i][j];
                    continue;
                }
                f[now][j] = grid[i][j];    //保存当前网格值
                t1 = i > 0 ? f[old][j]:inf;     //如果有上边的路
                t2 = j > 0 ? f[now][j-1]:inf;   //如果有左边的路
                f[now][j] += min(t1,t2);    //加上上一个单元格的 状态值
            }
        }
        return f[now][n-1];
    }
};

/*******刚入门DP时的错误思考,做个记录*******/
//曼哈顿距离
//最后一步,f[m+n] = f[m+n-1]+min(nums[m-1][j],nums[m][n-1]);
//错误的状态转移方程，最后一步不唯一，对应方程上述两个可能
