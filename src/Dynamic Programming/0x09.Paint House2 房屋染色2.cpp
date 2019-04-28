class Solution {    //n栋房子染k种颜色
public:
    const int inf = 0x3f3f3f3f;
    int minCostII(vector<vector<int>> &costs) {
        int n = costs.size();    //房子数量
        int k = costs[0].size();    //颜色数---由于该语句,在LintCode无法通过，估计是平台bug
        if(costs.empty() || n == 0 || k == 0) return 0;
        int f[n+1][k];
        int min1,min2;  //最小值和次小值
        int j1 = 0,j2 = 0; //最小值和次小值下标(颜色)
        for(int i = 0;i < k;i++) f[0][i] = 0;   //初始化前0栋房子的最小花费
        for(int i = 1;i <= n;i++){   //遍历所有房子
            min1 = inf,min2 = inf; 
            for(int j = 0;j < k;j++){
                if(f[i-1][j] < min1){   //比min1还小
                    min2 = min1;    //更新最小和次小值
                    j2 = j1;
                    min1 = f[i-1][j];
                    j1 = j;
                }else if(f[i-1][j] < min2){ //比min2小
                   min2 = f[i-1][j];
                    j2 = j; 
                }
            }
            for(int j = 0;j < k;j++){   //当前房子 不同颜色的状态f[i][j]
                if(j != j1){    //将要染的颜色不是花费最少的,以最少的计
                    f[i][j] = f[i-1][j1] + costs[i-1][j];
                }else{  //如果是最少的,以次少的计
                    f[i][j] = f[i-1][j2] + costs[i-1][j];
                }
                //以下为未采用次小值进行优化的写法
                //for(int t = 0;t < k;t++){   //将要染的颜色
                //    if(t != j){ //相邻不能相同
                //        //f[i][j] = min(f[i][j],f[i-1][t] + costs[i-1][t]);
                //       //错误,所有元素的最小值啊
                //    }
                //}
            }
        }
        int minn = inf;
        for(int i = 0;i < k;i++){
            minn = min(minn,f[n][i]);
        }
        return n;
    }
};
