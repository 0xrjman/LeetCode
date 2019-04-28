#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
const int N = 101;
const int inf = 0x3f3f3f3f;
int main()
{
    int t;
    cin >> t;
    while(t--){
        int m,n;
        cin >> n >> m;
        vector<int> h(n);
        int maxn = 0;
        for(int i = 0;i < n;i++){
            cin >> h[i];
            maxn = max(maxn,h[i]);  //找到maxn即可得到每座山的高度区间[h[i],maxn]
        }
        int f[N][N];    //f[i][j]表示在第i座山在高度j下的最小花费
        for(int j = h[0];j <= maxn;j++) f[0][j] = (j - h[0]) * (j - h[0]);
        for(int i = 1;i < n;i++){   //第i座山
            for(int j = h[i];j <= maxn;j++){ //在高度h[i]下最小花费
                f[i][j] = inf;
                for(int k = h[i-1];k <= maxn;k++){   //遍历前一座山的所有高度k
                    f[i][j] = min(abs(j-k) * m + f[i-1][k],f[i][j]);
                }
                f[i][j] += (j - h[i]) * (j - h[i]);
            }
        }
        int ret = inf;
        for(int i = h[n-1];i <= maxn;i++) ret = min(ret,f[n-1][i]);
        cout << ret << endl;
    }
    return 0;
}
//思想和染房子问题类似,记录不同高度(颜色)下的状态
//确定状态:
//对最后一座高度为j的山,它的花费 = 累积花费 + 填高/斜坡
//填高和斜坡都基于高度k,可见所需花费取决于前一座山的高度k
//那么只要对前一座山的每一个高度求花费，找出最小的,即为最后一座山高度为j的最小花费
//由此递推得到子问题:第i-1座山的最小花费
//初始状态:f[0][j] = abs(j-h[0]) * 2;    h[0] =< j <= maxn;
//状态转移方程:f[i][j] = min(f[i][j],abs(j-k) * x + f[i-1][k]);
