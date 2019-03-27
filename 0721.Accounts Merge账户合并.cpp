class Solution {    //账户合并---并查集+STL
private:

public:
    vector<int> bb; //并查集bb
    vector<int> rank;   //并查集优先级，根据节点数数量
    //并查集寻根
    int getroot(int x){
        //if(t != bb[t]) bb[t] = getroot(bb[t]);
        while(x != bb[x]) x = bb[x];
        return x;
    }
    //合并操作

    void mergeAccount(int x,int y){
        x = getroot(x);
        y = getroot(y);
        if(x == y) return ;
        if(rank[x] == rank[y]) rank[x]++;  //如果优先级相同,取x为高
        //合并
        if(rank[x] > rank[y]) bb[y] = x;   //如果x的优先级高
        else bb[x] = y;                     //如果y的优先级高
    }
    //账户合并
    vector<vector<string> > accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string> > reaccounts;  //返回合并后的账户集
        //vector<vector<string> >::iterator it = accounts.begin();
        int n = accounts.size();
        //初始化并查集和优先集
        for (int i = 0; i < n; i++){
            bb.push_back(i);//初始化每组的父亲为行号
            rank.push_back(1);
        }
        map<string,int> m;  //邮箱和行号的映射
        if (!n) return reaccounts;
        for (int i = 1; i < accounts[0].size(); i++){   //添加第一行邮箱
            m[accounts[0][i]] = 0;  //初始化第一行邮箱的父亲行号为0
        }
        //先初始化第一行，然后从第二行开始，判断是否有重复，逐行将邮箱往m中添加
        for(int i = 1;i < n;i++){
            for(int j = 1;j < accounts[i].size();j++){
                if(m.find(accounts[i][j]) != m.end()){
                    mergeAccount(m[accounts[i][j]],i);  //重复则合并值为父亲行号
                }else{
                    m[accounts[i][j]] = i;//如果不重复，插入,设值为该行号
                }
            }
        }//至此找出了邮箱和对应行号的关系，确保了唯一性，接着找出邮箱和人的确定集合
        //map<string,int>::iterator it;
        map<int, vector<string> > man;   //姓名+邮箱的 账户集合
        for (auto &it:m){    //遍历邮箱和行号的 映射集合
            int k = getroot(it.second);
            if (man.find(k) == man.end()){   //没有该账户时才新增账户
                man[k].push_back(accounts[k][0]);
            }
            man[k].push_back(it.first); //添加邮箱到集合
        }
        for(auto it:man) reaccounts.push_back(it.second);    //添加每个账户
        return reaccounts;
    }
};
