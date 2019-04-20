//分割回文串2---DP+划分
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    const int inf = 0x3f3f3f3f;
    int minCut(string s) {
        int n = s.size();
        if(!n) return 0;
        bool isPalinDrome[n][n];//[i,j]是否为回文串
        int i,j,k;
        //initial
        for(i = 0;i < n;i++){
            for(j = 0;j < n;j++){
                isPalinDrome[i][j] = false;
            }
        }
        //generate palindrome
        for(k = 0;k < n;k++){   //以连接处为起始点生成
            //odd-length 奇数长度
            i = j = k;  //以中轴元素开始生成回文串
            while(i >= 0 && j< n && s[i] == s[j]){
                isPalinDrome[i][j] = true;
                --i;
                ++j;
            }
            //even-length 偶数长度
            i = k;
            j = k + 1;  //以中心两元素开始生成
            while(i >= 0 && j < n&& s[i] == s[j]){
                isPalinDrome[i][j] = true;
                --i;
                ++j;
            }
        }
        int f[n+1];
        f[0] = 0;
        for(int i = 1;i <= n;i++){  //前i个字符最少能划分几个回文串
            f[i] = inf;
            for(int j = 0;j < i;j++){   //
                if(isPalinDrome[j][i-1])    //[j,i-1]为回文串
                    f[i] = min(f[i],f[j] + 1);  
            }
        }
        return f[n] - 1;
    }
};
//确定状态
//最后一步,对字符串S[0,n-1],划分为 [0,j-1] 和 [j,n-1]两段
//f[i] = S前i个字符最少可以划分为几个回文串
//子状态 f[j] = S前j个字符最少可以划分为几个回文串
//初始条件 f[0] = 0 ,前0个字符可以分为0个回文串
//若最后一步的[j,n-1]为回文串,则
//状态转移方程 f[i] = min(f[j]+1 | 0 <= j <= i-1)
//怎么判断回文串？思路:生成回文串
//对奇数长度,自中轴元素，往外展开
//对偶数长度,自空（两个元素）开始，往外展开
//状态转移方程:f[i] = min(f[j]+1|isPalin[j][i-1] = True
//                                  and  0 <= j <= i-1)
