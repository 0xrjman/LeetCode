class Solution {    //状态转移方程：f[i] = max(f[i-1],f[i-2] + nums[i-1]);
public:             //f[i] 表示前i个房子可以获得的最高金额
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;    //输入为空的情况
        int f[n+1];
        f[0] = 0;   //初始化前0个房子可获得最高0元
        f[1] = nums[0]; //初始化第一个房子最高可获得nums[0]
        int maxn = f[1];    //初始化最大值为f[1](只有一个房子的情况)
        for(int i = 2;i <= n;i++){  //对第二个房子起的每个房子,有偷和不偷两种状态,取最大值
            f[i] = max(f[i-1],f[i-2] + nums[i-1]);            //不偷的情况,偷的情况
            maxn = max(maxn,f[i]);
        }
        return maxn;
    }
};
