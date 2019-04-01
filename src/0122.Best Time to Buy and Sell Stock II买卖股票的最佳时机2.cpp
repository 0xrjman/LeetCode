class Solution {    //贪心思想
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();  //天数n
        int sum = 0;
        for (int i = 0; i < n - 1; i++) //遍历所有天数
            if (prices[i] < prices[i + 1])  //对于每两天，若出现可赚取利润
                sum += prices[i+1] - prices[i];   //则累加
        return sum;
    }
};

class Solution {    //动态规划
public:
    const int inf = 0x3f3f3f3f; //无穷大
    int maxProfit(vector<int>& prices) {
        int buy = -inf;  //当前持有资金的正负值，取无穷小，找最大值
        int sell = 0;        //最大利润
        for(auto p:prices){
            //遍历每一天，并将每一个股票价格视作 “交易点”
            //对"每一次交易"，更新 买入和卖出 的状态变量
            buy  = max(buy,sell - p);   //更新买入股票的最大利益
            sell = max(sell,buy + p);   //更新卖出股票的最大利益
        }
        return sell;
    }
};
