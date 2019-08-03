// 01背包+方案数+一维优化
//状态转移方程:f[i][j] = f[i-1][j] + f[i-1][j-bp[i-1]]
//滚动数组优化:f[now][j] = f[old][j] + f[old][j-bp[old]]
//一维数组优化:f[j] = f[j] + f[j-bp[i-1]]
#include <iostream>
#include <vector>
using namespace std;
int buyTheGoods(vector<int> &bp,int m){
    int n = bp.size();
    if(!n || !m) return 0;
    int f[m+1];
    f[0] = 1;
    for(int i = 1;i <= m;i++) f[i] = 0;
    for(int i = 1;i <= n;i++){
        for(int j = m;j >= 0;j--){
            if(j >= bp[i-1]){
                f[j] += f[j - bp[i-1]];
            }
        }
    }
    return f[m];
}

int main()
{
    ios::sync_with_stdio(0);
    int n,m,t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        vector<int> bp;
        for(int i = 0;i < n;i++){
            int temp;
            cin >> temp;
            bp.push_back(temp);
        }
        int ret = buyTheGoods(bp,m);
        cout << ret << endl;
    }
    return 0;
}
