class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> book(n,0);  //长度为n,记录是否能到达房间i
        queue<int> q;
        q.push(0);
        book[0] = 1;
        while(!q.empty()){
            int i = q.front();
            q.pop();
            for(auto j:rooms[i]){   //遍历当前房间内的钥匙
                if(!book[j]){   //如果存在未访问过的的房间的钥匙
                    book[j] = true; //标记访问
                    q.push(j);      //添入计划(队列)
                }
            }
        }
        for(auto i:book) if(!i) return false;   //查找是否有没访问过的房间
        return true;
    }
};
