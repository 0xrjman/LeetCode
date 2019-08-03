class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return;
        int k = 0;
        for(int i = 0;i < n;i++)
          if(nums[i]) nums[k++] = nums[i];  //非零元素前置添加
        while(k < n) nums[k++] = 0;         //后置补零元素
    }
};
