class Solution {  //f[i] = min(f[i-j^2] + 1 | 1 <= j^2 <= i);
public:
    const int inf = 0x3f3f3f3f;
    int numSquares(int n) {
        int f[n+1];
        f[0] = 0;   //初始化
        for(int i = 1;i <= n;i++){
            f[i] = inf;
            for(int j = 1;j * j <= i;j++){
                if(f[i - j * j] + 1 < f[i]){
                    f[i] = f[i-j * j] + 1;
                }
            }
        }
        return f[n];
    }
};
//n 最少被划分成几个完全平方数之和
//最后一步: 加上最后一个元素j^2得到n
//子问题：n-j^2 最少被划分成几个完全平方数之和
//f[i] = i最少表示几个完全平方数之和
//f[i] = min(f[i-j^2] + 1 | 1 <= j^2 <= i);
