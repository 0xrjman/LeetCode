class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        # 状态转移方程：f[i] = max(f[i-a]+1,f[i-b]+1,f[i-c]+1,...)
        f = [float("inf")] * (amount+1)
        f[0] = 0
        for i in range(1,amount+1):
            for coin in coins:
                if(i >= coin):  # 兑换面值 >= 币值
                    f[i] = min(f[i],f[i-coin]+1)   # 对不同币值，找出最小换取量
        if(f[amount] == float("inf")):
            return -1
        else:
            return f[amount]
