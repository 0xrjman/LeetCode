class Solution {      
public:
    int ret = 0;    
    void calc(vector<int>& nums,int n){ 
        int f[n];
        for(int i = 0;i < n;i++){
            f[i] = 1;   
            if(i > 0 && nums[i-1] < nums[i])    
                f[i] = max(1,f[i-1] + 1);
            if(f[i] > ret) ret = f[i];
        }
    }
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        calc(nums,n);   
        return ret;
    }
};

/****最长连续单调子序列(递增和递减)****/
class Solution {      //不取消注释提交，则为最长连续递增子序列
public:
    int ret = 0;    //全局定义
    void calc(vector<int>& nums,int n){ //找出最长子序列长度 ret;
        int f[n];
        for(int i = 0;i < n;i++){
            f[i] = 1;   //第一种情况
            if(i > 0 && nums[i-1] < nums[i])    //第二种情况
                f[i] = max(1,f[i-1] + 1);
            if(f[i] > ret) ret = f[i];
        }
    }
    /*
    void calc(vector<int>& nums,int n){ //滚动数组思想
        int f[2];
        int old,now = 0;    //记录下标
        for(int i = 0;i < n;i++){
            old = now;      
            now = 1 -old;   
            f[now] = 1;
            if(i > 0 && nums[i-1] < nums[i])    
                f[now] = f[old] + 1;
            if(f[now] > ret) ret = f[now];
        }
    }
    */
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        calc(nums,n);   //寻找最长连续上升子序列
        /*
        //反转序列,找最长连续上升序列 即 为找最长连续递减子序列
        int i = 0,j = n-1,t;
        while(i < j){
            t = nums[i];
            nums[i] = nums[j];
            nums[j] = t;
            i++;
            j--;
        }
        calc(nums,n);   //寻找 反转后的 最长连续上升子序列
        */
        return ret; //两次查找后的结果即为最长连续 单调 子序列(递增和递减)的长度
    }
};
//对最长连续上升子序列而言,
//确定状态，对于最优策略，一定有最后一个元素
//先找简单情况
//第一种情况，最后一个元素为a[j]，最长的连续上升子序列为{a[j]},答案是1
//第二种情况,长度大于1,那么肯定存在a[j]的前一个元素a[j-1],得到a[j-1] < a[j]
//对于最优策略,以a[j-1]为结尾的子序列也一定是最长的
//即化为了上述的子问题：求以a[j-1]结尾的最长连续上升子序列
//得到状态：f[i] = 以a[j]结尾的最长连续上升子序列长度
//状态转移方程为f[i] = max(1,f[i-1]+1 |i>0 and a[i-1] < a[i])
//计算f[0],f[1]...f[n-1]
//答案 = max (f[0],f[1]...f[n-1]);
