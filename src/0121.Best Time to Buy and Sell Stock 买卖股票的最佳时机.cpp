class Solution {
public:
    const int inf = 0x3f3f3f3f;
    int maxProfit(vector<int>& prices) {
        int minn = inf;
        int sum = 0;
        for(auto p:prices){
            minn = min(minn,p); //找出前i-1天最小的股票价格
            sum = max(sum,p-minn);  //比较卖出股票是否能获得更大利润
        }
        return sum;
    }
};
//确定状态
//最后一步：通过一次交易，前第i天能获得的最大利益
//子问题：通过一次交易，前第i-1天能获得的最大利益
//状态转移方程
//f[x] = max(f[x-1],prices[i]-minn)
//前i天的最大收益 = max{前i-1天的最大收益，第i天的价格-前i-1天中的最小价格}
