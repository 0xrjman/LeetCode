class Solution {
public:
        vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int> > graph(numCourses,vector<int> (0)); //邻接表存储
        vector<int> inDegree(numCourses,0);
        for(auto i:prerequisites){
            graph[i.second].push_back(i.first); //保存至邻接表
            inDegree[i.first]++;
        }   //统计入度情况(前置课程)
        queue<int> q;   //安全课程,不在环内
        vector<int> ret; //保存搜索结果
        for(int i = 0;i < numCourses;i++){
            if(!inDegree[i]){
                q.push(i);
                ret.push_back(i);
            }   //以安全课程为起点开始搜索,该课程为首要前置课程,入队ret
        }
        while(!q.empty()){
            int t = q.front();
            q.pop();
            for(auto i:graph[t]){   //对安全节点,它指向的邻接节点入度--
                --inDegree[i];
                if(!inDegree[i]){
                    q.push(i); //同样视作安全课程
                    ret.push_back(i);
                }
            }
        }
        for(int i = 0;i < numCourses;i++) if(inDegree[i]) return {};  //存在环的情况
        return ret;
    }
};
