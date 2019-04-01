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
        int profit = -inf;  //当前持有资金的正负值，取无穷小，找最大值
        int sum = 0;        //最大利润
        //动态规划思想
        for(auto p:prices){ //遍历每一个股票价格并视作 “交易点”
            profit = max(profit,sum - p);   //对当前点，有不做交易和做交易两种结果
            sum = max(sum,profit+p);    //不做交易和做交易后的最大利润
        }
        return sum;
    }
};
