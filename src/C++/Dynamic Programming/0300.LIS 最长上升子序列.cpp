class Solution {  //状态转移方程：f[j] = max(1,f[i]+1 | i < j and a[i] < a[j])
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return 1;
        int f[n],ret = 0;
        for(int j = 0;j < n;j++){
            f[j] = 1;   //初始化以nums[j]结尾的最长子序列长度
            for(int i = 0;i < j;i++){   //前j个元素的区间内如果有递增关系
                if(nums[i] < nums[j] && f[i] + 1 > f[j]){
                    f[j] = f[i] + 1;    //更新长度
                }
            }
            ret = max(ret,f[j]);    //找出最大值
        }
        return ret;
    }
};
//两种情况，一种长度1，另一种长度 > 1
//确定状态
//最后一步f[j] = 以a[j]结尾的最长子序列的长度
//对于最优策略，一定存在a[j]的前一个元素a[i]
//其中 i < j && a[i]<a[j]
//f[j] = max(1,f[i]+1|i < j and a[i] < a[j])
