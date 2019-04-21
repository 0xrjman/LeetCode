//背包问题要把总承重放入状态
class Solution {
public:
    int backPack(int m, vector<int> &A) {
        int n = A.size();
        if(n == 0) return 0;
        bool f[n+1][m+1];
        f[0][0] = true;
        for(int j = 1;j <= m;j++) f[0][j] = false;
        for(int i = 1;i <= n;i++){
            for(int j = 0;j <= m;j++){
                f[i][j] = f[i-1][j];    //初始化为前一个状态
                if(j >= A[i-1]){    //判断是否能拼出更大重量 j 
                    f[i][j] = f[i][j] || f[i-1][j-A[i-1]];
                    //不放，继承前一 为true的状态
                    //放，可更新 当前状态 为前一为true的状态
                    //都是false则表示无法拼出当前重量 j
                }
            }
        }
        for(int i = m;i >= 0;i--) if(f[n][i]) return i;
        //逆序输出最大可容纳的最大重量
        return 0;
    }
};
//背包问题要把总承重放入状态
//01背包
//最后一步,物品A[n-1]，放/不放
//前n个物品能否拼出重量0,1...,M
//子问题:前i-1个物品能不能拼出重量0,1,...,M
//f[i][w] = 能否用前i个物品拼出重量w(true\false)
//f[i][w] = f[i-1][w] OR f[i-1][w-A[i-1]]
//初始状态:f[0][0] = True;f[0][1...M] = false;

//误区:设f[i] 表示前i个物品能拼出的最大重量
//反例:A = [3,9,5,2],Target = 10
//对最优策略,前n-1个物品拼出的不一定是不超过Target的最大重量
//如对最后一步,(9+2>10) == 9 < (3+5+2) == 10
//背包问题要把总承重放入状态
//重要的事情说三遍
