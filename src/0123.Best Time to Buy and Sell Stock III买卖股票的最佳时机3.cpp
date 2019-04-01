class Solution {
public:
    const int inf = 0x3f3f3f3f;
    int maxProfit(vector<int>& prices) {
        int fstBuy = -inf,fstSell = 0;
        int secBuy = -inf,secSell = 0;
        for(auto p:prices){
            fstBuy = max(fstBuy,-p);
            fstSell = max(fstSell,fstBuy + p);  
            secBuy = max(secBuy,fstSell-p);
            secSell = max(secSell,secBuy+p);
        }
        return secSell;
    }
};
/**
对于任意一天考虑四个变量:
fstBuy: 在该天第一次买入股票可获得的最大收益
fstSell: 在该天第一次卖出股票可获得的最大收益
secBuy: 在该天第二次买入股票可获得的最大收益
secSell: 在该天第二次卖出股票可获得的最大收益
分别对四个变量进行相应的更新, 最后secSell就是最大利益
收益值(secSell >= fstSell)
**/
