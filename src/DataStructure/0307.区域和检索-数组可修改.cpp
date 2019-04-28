/*********以下为线段树************/
class NumArray {
public:
    vector<int> value;
    int pos;
    NumArray(vector<int>& nums) {
        if(nums.empty()) return ;
        int n = nums.size() * 4;
        for(int i = 0;i < n;i++) value.push_back(0);
        build_segment_tree(value, nums, 0, 0, nums.size()-1);
        pos = nums.size()-1;
    }
    void update(int i, int val) {
        update_segment_tree(value, 0, 0, pos, i, val);
    }
    
    int sumRange(int i, int j) {
        return sum_range_segment_tree(value, 0, 0, pos, i, j);
    }
    void build_segment_tree(vector<int>&value,  
        vector<int>&nums, int pos, int left, int right) {
        if (left == right) {
            value[pos] = nums[left];
            return;
        }
        int mid = (left + right) / 2;
        build_segment_tree(value, nums, pos * 2 + 1, left, mid);
        build_segment_tree(value, nums, pos * 2 + 2, mid + 1, right);
        value[pos] = value[pos * 2 + 1] + value[pos * 2 + 2];
    }
    //线段树区间求和
    int sum_range_segment_tree(vector<int>&value,
        int pos, int left, int right, int qleft, int qright) {
        if (qleft > right || qright < left) return 0;
        if (qleft <= left && qright >= right) return value[pos];
        int mid = (left + right) / 2;
        return sum_range_segment_tree(value, pos * 2 + 1,
            left, mid, qleft, qright)
            + sum_range_segment_tree(value, pos * 2 + 2,
                mid + 1, right, qleft, qright);
    }
    //更新线段树
    void update_segment_tree(vector<int>&value,
        int pos, int left, int right, int index, int new_value) {
        if (left == right && left == index) {
            value[pos] = new_value;
            return;
        }
        int mid = (left + right) / 2;
        if (index <= mid) {
            update_segment_tree(value, pos * 2 + 1, left, mid, index, new_value);
        }
        else {
            update_segment_tree(value, pos * 2 + 2, mid + 1, right, index, new_value);
        }
        value[pos] = value[pos * 2 + 1] + value[pos * 2 + 2];
    }
};

//参照士兵杀敌问题,以下为树状数组实现
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
