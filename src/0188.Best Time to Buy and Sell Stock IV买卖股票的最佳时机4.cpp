class Solution {
private:
    int greedy(vector<int>& prices){
        int n = prices.size();  //天数n
        int sum = 0;
        for(int i = 0;i < n-1;i++){
            if(prices[i] < prices[i+1]){
                sum += prices[i+1] - prices[i];
            }
        }
        return sum;
    }
public:
    const int inf = 0x3f3f3f3f;
    int maxProfit(int k,vector<int>& prices) {
        /* *
         * 最少两天完成一次交易，那么当k >= 天数/2时，相当于不限制次数
         * 这时候用 “II” 的贪心解法效率更高
         * 当k在区间(1,n/2)时，采用 “III” 的动态规划思想来解决,
         * 即对每一次交易，定义其 买入 和 卖出 时最大收益的状态变量，
         * 遍历整个所有价格，更新状态变量，t[i][0]和t[i][1]
         * 得到 t[k-1][1] 即为所求完成k次交易后的最大利益
         * /
        if(k < 1) return 0;
        if(k >= prices.size()/2) return greedy(prices);
        int t[k][2];    // [2] 表示买入和卖出股票时最大利益的状态
        for(int i = 0;i < k;i++){
             t[i][0] = -inf;    //买股票
             t[i][1] = 0;
        }
        for(auto p:prices){
            t[0][0] = max(t[0][0],-p);  //买入股票的最大利润
            t[0][1] = max(t[0][1],t[0][0] + p); //卖出股票
            for(int i = 1;i < k;i++){
                t[i][0] = max(t[i][0],t[i-1][1] - p);
                t[i][1] = max(t[i][1],t[i][0] + p);
            }
        }
        return t[k-1][1];
    }
};
