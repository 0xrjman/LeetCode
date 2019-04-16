class Solution{ //n栋房子染3种颜色
public:
    const int inf = 0x3f3f3f3f;
    int PaintHouse(vector<vector<int> > &costs){
        //前i栋房子且第i-1栋是红色的花费
        //状态转移方程 f[i][0]=min(f[i-1][1]+costs[i-1][0],f[i-1][2]+costs[i-1][0])
        //则最小花费为 min(f[i][0],f[i][1],f[i][2])
        int n = costs.size();   //房子数量
        if(n == 0) return 0;
        int f[n+1][3];    //保存房子和染色费用
        f[0][0]=f[0][1]=f[0][2]=0;  //初始状态
        for(int i = 1;i <= n;i++){  //前 i 栋房子
            for(int k = 0;k < 3;k++){   //染第 i 种颜色
                f[i][k]= inf;  //初始化为无穷大，找最小花费
                for(int j = 0;j < 3;j++){   //前一栋房子的另两种颜色
                    if(j != k && f[i-1][j]+costs[i-1][k] < f[i][k]){
                        f[i][k]=f[i-1][j]+costs[i-1][k];
                    }
                }
            }
        }
        int res=f[n][0];
        if(f[n][1] < res) res = f[n][1];
        return f[n][2] < res?f[n][2]:res;
    }
};
