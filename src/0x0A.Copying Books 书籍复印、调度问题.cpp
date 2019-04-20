书籍复印、最佳调度问题---DP+划分--二维状态
#include <iostream>
#include <vector>
using namespace std;
//
class Solution {
public:
    const int inf = 0x3f3f3f3f;
    int copyBooks(vector<int> &pages, int k) {
        int n = pages.size();
        if(n == 0) return 0;
        if(k > n) k = n;
        int f[k+1][n+1];
        //initial
        f[0][0] = 0;
        for(int i = 1;i <= n;i++) f[0][i] = inf;
        for(int m = 1;m <= k;m++){  //m个机器
            f[m][0] = 0;
            for(int i = 1;i <= n;i++){
                f[m][i] = inf;
                int sum = 0;
                for(int j = i;j >= 0;j--){
                    f[m][i] = min(f[m][i],max(f[m-1][j],sum));
                    if(j > 0) sum += pages[j - 1];
                }
            }
        }
        return f[k][n];
    }
};

//理解划分型DP：
//对一段区间进行划分,取最小值或最大值
//根据最后一步j的划分得到子状态f[j]
//初始状态：f[i][0] = 0,f[0][1]=f[0][2]=...f[0][n] = 负无穷
//f[k][i] = min(f[k-1][j],A[j]+...+A[i-1] | 0 =< j <= i-1)
//f[k][i] = 前k个机器最少需要多少时间完成前i项任务
//划分后f[k-1][j] = 前k-1个机器最少需要多少时间完成前j项任务
//A[j]+...+A[i-1]表示第k-1个机器完成前i-j项任务所需的时间
//取划分后两者的最大值为一次划分的结果
//取所有划分结果的最小值为所需最少时间
