//参照士兵杀敌问题
#include <iostream>
#include <vector>
using namespace std;
class NumArray {
public:
    int n;
    vector<int> bit;
    vector<int> origins;
    int lowbit(int x){
        return x&(-x);
    }
    NumArray(vector<int>& nums) {
        n = nums.size();
        for (int i = 0; i < n+1; i++) {
            bit.push_back(0);
            origins.push_back(0);
        }
        for(int i = 0; i < n; i++) update(i,nums[i]);
    }
    void update(int i, int val){
        i += 1;
        //将i的值修改为j,需要自叶子结点向上更新
        //因此不能直接修改,需要找到结点值的增量(+/-),此处采用origins保存原数值
        int dif = val - origins[i];    //dif较原值的变化量(+/-)
        origins[i] = val;   //保存原值
        while(i <= n){
            bit[i] += dif; //更新结点
            i += lowbit(i);
        }
    }
    int getSum(int i){
        i += 1;
        int ret = 0;
        while(i > 0){
            ret += bit[i];
            i -= lowbit(i);
        }
        return ret;
    }
    int sumRange(int i, int j) {
        return getSum(j) - getSum(i-1);
    }
};
