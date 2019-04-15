#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    //最后一步
    //要么2个数字合成一个，要么一个
    //那么方法数f[i] = f[i-1]一个字母 + f[i-2]两个字母
    int numDecodings(string s) {
        int n = s.size();
        int f[n + 1];
        f[0] = 1;   //初始状态
        for(int i = 1;i <= n;i++){
            f[i] = 0;   //初始化为0种方案
            //last digit
            int t = s[i-1] - '0';
            if(t >= 1 && t <= 9) f[i] += f[i-1];
            //如果存在两个数字组成的情况,须i >= 2
            if(i >= 2){
                //last two digits
                t = (s[i-2] - '0') * 10 + (s[i-1]-'0');
                if(t >= 10 && t <= 26) f[i] += f[i-2];
            }
        }
        return f[n];
    }
};
