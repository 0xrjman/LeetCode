#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        if(m == 0 || n == 0) return 0;
        int f[m][n];    //到i,j所需的最小生命值
        if(dungeon[m-1][n-1] >= 0) f[m-1][n-1] = 0;
        else f[m-1][n-1] = - dungeon[m-1][n-1]; // 初始化终点
        for(int i = m-2;i >= 0;i--){    //初始化第n-1列  （只有一个方向）
            f[i][n-1] = dungeon[i][n-1] >= f[i+1][n-1] ? 0 : f[i+1][n-1] - dungeon[i][n-1];
            //判断当前格到下一格是否需要额外生命值
        }
        for(int j = n-2;j >= 0;j--){    //初始化第m-1行  （只有一个方向）
            f[m-1][j] = dungeon[m-1][j] >= f[m-1][j+1] ? 0 : f[m-1][j+1] - dungeon[m-1][j];
        }
        for(int i = m-2;i >= 0;i--){    
            for(int j = n-2;j >= 0;j--){
                int toRight = dungeon[i][j] >= f[i+1][j] ? 0 : f[i+1][j] - dungeon[i][j];
                int toDown = dungeon[i][j] >= f[i][j+1] ? 0 : f[i][j+1] - dungeon[i][j];
                f[i][j] = min(toRight,toDown);  //选择仅需最小生命值的方向
            }
        }
        return f[0][0] + 1; //最低生命至少为1，加上1
    }
};
//动态规划找全局最优解,如果从起点到终点的过程中，
//只能一步步得到当前的局部最优解，那么要考虑从终点到起点DP的情况
//即分析最后一步

