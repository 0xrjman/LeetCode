class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        //等价于判断有向图中是否存在环
        vector<int> inDegree(numCourses,0);
        for(auto i:prerequisites){
            inDegree[i.first]++;
        }   //统计入度情况(前置课程)
        queue<int> q;   //安全课程,不在环内
        for(int i = 0;i < numCourses;i++){
            if(inDegree[i] == 0) q.push(i); //以安全课程为起点开始搜索
        }
        int cnt = 0;
        while(!q.empty()){
            int one = q.front();
            q.pop();
            cnt++;
            for(auto i:prerequisites){
                if(i.second == one){    //被安全课程指向
                    inDegree[i.first]--;    //除去安全课程后,入度为0
                    if(!inDegree[i.first]) q.push(i.first); //同样视作安全课程
                }
            }
        }
        return cnt == numCourses?true:false;
    }
};
