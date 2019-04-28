//两种思考方案，都依赖数组保存、记忆
class Solution {    //状态转移方程：f[i] = f[i>>1] + (i % 2);
public:
    vector<int> countBits(int num) {
        vector<int> f(num+1,0);
        for(int i = 1;i <= num;i++){
            f[i] = f[i >> 1] + (i % 2); 
            //f[i] = f[i&(i-1)] + 1; 偶数的二进制只有一位1,奇数二进制尾数为1
        }
        return f;
    }
};
