#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int N = 100010;
const int M = 20;
static int n,m;
static int dp_min[N][M],dp_max[N][M];

void RMQ_inital(){  //动态规划预处理---> O(nlogn)
    for(int j = 1;j < M;j++){
        for(int i = 1;i + (1 << j) -1 <= n;i++){
            //以下都是j-1，因为要分两段
            dp_max[i][j] = max(dp_max[i][j-1],dp_max[i + (1 << (j-1))][j-1]);
            dp_min[i][j] = min(dp_min[i][j-1],dp_min[i + (1 << (j-1))][j-1]);
        }
    }
}
int RMQ_Query(int a,int b){ //ST查询---->O(1)
    int k = static_cast<int>(log(b - a + 1.0)/log(2.0));    //找出最小幂
    int maxn = max(dp_max[a][k],dp_max[b - (1 << k) +1][k]);    //区间最大值
    int minn = min(dp_min[a][k],dp_min[b - (1 << k) +1][k]);    //区间最小值
    //printf("%d,%d\n",maxn,minn);
    return maxn - minn;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i++){
        scanf("%d",&dp_max[i][0]);
        dp_min[i][0] = dp_max[i][0];    //DP初始状态
    }
    RMQ_inital();
//  可以拷贝验证initial();
//  for(int j = 1;(1 << j) <= M;j++){
//      for(int i = 1;i + (1 << j) -1 <= n;i++){
//          cout << "dp_max---i= " << i << " ,j= " << j << "::";
//          cout << dp_max[i][j] << endl;
//          cout << "dp_min---i= " << i << " ,j= " << j << "::";
//          cout << dp_min[i][j] << endl;
//      }
//  }
    while(m--){
        int i , j;
        scanf("%d%d",&i,&j);
        printf("%d\n",RMQ_Query(i,j));
    }
    return 0;
}
