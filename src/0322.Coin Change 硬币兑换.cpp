class Solution {
public:
    const int inf = 0x3f3f3f3f;
    int coinChange(vector<int>& coins, int amount) {
        //状态转移方程 f[i] = max(f[i-a]+1,f[i-b]+1,f[i-c]+1,......)  //取决于硬币数量
        int n = coins.size();
        int f[amount + 1];
        f[0] = 0;
        for(int i = 1;i <= amount;i++){
            f[i] = inf; //初始化为无穷大
            for(int j = 0;j < n;j++){   //遍历所有币值
                //剩余面值 >= 币值 并且 找出最小换取量的币值
                if(i >= coins[j] && f[i-coins[j]] + 1 < f[i]){
                    f[i] = f[i-coins[j]] + 1;
                }
            }
        }
        if(f[amount] == inf) return -1;
        else return f[amount];
    }
};
