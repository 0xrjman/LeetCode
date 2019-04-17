class Solution {  //解法类似LIS,f[j] = max(1,f[i]+1 | 信封i的长宽 < 信封j的长宽)
public:
    static bool cmp(const pair<int,int> a,const pair<int,int> b){   //pair排序
        return a.first == b.first?a.second < b.second : a.first < b.first; //优先按长度升序排,然后按宽度
    }
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        int n = envelopes.size();
        if(n == 0) return 0;
        if(n == 1) return 1;
        sort(envelopes.begin(),envelopes.end(),cmp);  //对vector 的pair 进行自定义排序
        int f[n];
        int ret = 0;
        for(int j = 0;j < n;j++){   //f[j] = 前j个元素的最大子序列长度
            f[j] = 1;   //初始化长度为1
            for(int i = 0;i < j;i++){   //寻找前j个元素的区间内是否存在嵌套关系
                if(envelopes[i].first < envelopes[j].first){    //排序后的序列可能出现前后元素长度相等的情况
                    if(envelopes[i].second < envelopes[j].second && f[i] + 1 > f[j]){  //长度和宽度一定要 "大于"
                        f[j] = f[i] + 1;
                    }
                }
            }
            ret = max(ret,f[j]);
        }
        return ret;
    }
};
//时间复杂度O(n^2)，空间复杂度O(n)，时间复杂度还有可优化的方法达到O(nlogn)
//执行用时 : 852 ms, 在Russian Doll Envelopes的C++提交中击败了36.07% 的用户
//内存消耗 : 11.2 MB, 在Russian Doll Envelopes的C++提交中击败了97.30% 的用户
