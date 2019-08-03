class Solution {
//注意本题条件:所有人都相信法官而法官不相信其他人,即入度为N-1、出度为0的就是法官
//定义map<int,pair<int,int> > m;
//也可以数组记录,入度in[N+1],出度out[N+1];
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        int n = trust.size();
        if(n < N-1) return -1;  //所给条件无法满足每个人都相信法官
        int in[N+1] = {0},out[N+1] = {0};
        int ret = -1;
        for(auto i:trust){
            out[i[0]]++;    //出度++
            in[i[1]]++;     //入度++
        }
        for(int i = 1;i <= N;i++){
            if(in[i] == N-1 && !out[i]) ret = i;
        }
        return ret;
    }
};
