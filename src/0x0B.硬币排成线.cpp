//取石子(每次取1、2颗,先手没石子败)
//滚动数组优化:
class Solution {
public:
    bool firstWillWin(int n) {
        if(!n) return false;
        if(n == 1 || n == 2) return true;
        bool f[2];  //仅需记忆前两步状态即可
        int old,now = 0;
        f[0] = false;
        f[1] = true;
        for(int i = 2;i <= n;i++){
            old = now;  
            now = 1-now;
            f[old] = (f[old] == false) || (f[now] == false);    //更新状态    
        }
        return f[old];
    }
};
//通过DP找出规律(简单博弈)
class Solution {
public:
    bool firstWillWin(int n) {
        return n%3;
    }
};
//正常开数组
class Solution {
public:
    bool firstWillWin(int n) {
        if(!n) return false;
        if(n == 1 || n == 2) return true;
        bool f[n + 1];
        f[0] = false;
        f[1] = f[2] = true;
        for(int i = 3;i <= n;i++){
            f[i] = (f[i-1] == false) || (f[i-2] == false);    
        }
        return f[n];
    }
};
//若上一先手有选择必败
//则当前先手采取最优策略，必胜

//博弈动态规划通常从 第一步 开始分析,因为局面越简单，石子数量越少
//必胜：一步操作后能够让剩下的局面先手必败，则当前先手必胜
//必败：不管怎么走，剩下的局面都是当前先手必胜，则当前先手必败
