class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0],nums[1]);
        int f[n+1];
        //偷第一个，最后一个不偷
        f[0] = 0;
        f[1] = nums[0];
        int maxn = f[1];
        for(int i = 2;i <= n-1;i++){    
            f[i] = max(f[i-1],f[i-2] + nums[i-1]);
            maxn = max(maxn,f[i]);
        }
        //偷最后一个，第一个不偷
        f[1] = 0;  
        f[2] = nums[1];
        for(int i = 3;i <= n;i++){
            f[i] = max(f[i-1],f[i-2] + nums[i-1]);
            maxn = max(maxn,f[i]);
        }   
        return maxn;
    }
};
