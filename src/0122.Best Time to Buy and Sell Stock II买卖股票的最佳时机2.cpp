class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();  //天数n
        int max = 0;  
        for (int i = 0; i < n - 1; i++) //遍历所有天数
            if (prices[i] < prices[i + 1])  //对于每两天，若出现可赚取利润
                max += prices[i+1] - prices[i];   //则累加
        return max;
    }
};
