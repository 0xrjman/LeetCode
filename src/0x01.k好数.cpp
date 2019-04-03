#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define mod 1000000007
static int dp[105][105];

int main()
{
    int k,l,i,j,x;
    while(~scanf("%d%d",&l,&k)){
        //初始状态
        for(i = 0; i<k; i++) dp[1][i] = 1;
        //dp[i][j] i表示长度，j表示以j开头的 好数 数量
        for(i = 2; i<=l; i++){
            for(j = 0; j<k; j++){
                //状态转移方程d[i][j] = d[i][j] + d[i-1][x];
                //i长度j开头的j好数 +=  (i-1)长度和j不相邻的x开头的 好数 数量
                for(x = 0; x<k; x++){//x表示当前数值
                    if(x != j-1&&x != j+1){  //与j不相邻
                        dp[i][j] += dp[i-1][x];   //以j开头的 好数 += 上一长度的不相邻 好数数量
                        dp[i][j]%=mod;  //取模
                    }
                }
            }
        }
        int sum = 0;
        for(i = 1; i<k; i++){   //k好数数量 = (1～k-1)好数 数量之和
            sum += dp[l][i];
            sum %= mod;
        }
        printf("%d\n",sum%mod);
    }
    return 0;
}
/*  L=2，K=4时的dp[i][j]
 *  i\j    0          1           2       3
 *   1     0          1           2       3
 *   2  00,02,03    11,13       20,22  30,31,33
 */

