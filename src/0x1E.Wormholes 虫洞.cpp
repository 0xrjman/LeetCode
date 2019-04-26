#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct st{
    int y,w;    //节点st的当前编号y 和 可到达当前节点的距离w
    st(int y,int w):y(y),w(w) {}
};
const int N = 505;
const int inf = 0x3f3f3f3f;
vector<st> g[N];    //邻接表
int dis[N];     //最短路径dis

bool spfa(int s){    //判断是否存在负权环
    dis[s] = 1;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        s = q.front();
        q.pop();
        int len = g[s].size();
        for(int i = 0; i < len;i++){
            st one = g[s][i];   //one 为 s 的邻接节点
            if(dis[s] + one.w < dis[one.y]){    //如果通过 s 到 one 有更短距离  --->初始化 dis 为 inf
                dis[one.y] = dis[s] + one.w;    //更新dis
                q.push(one.y);  //将邻接的节点 one放入队列
            }
        }
        if(dis[1] < 0) return true;    //在过程中 判断起点时间是否为负
    }
    return false;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m,w;
        scanf("%d%d%d",&n,&m,&w);   //顶点数n,正权边数m,负权边数w
        for(int i=1; i<=n; i++){    //初始化 访问数组 和 节点的邻接表
            dis[i]=inf;
            g[i].clear();
        }
        dis[1]=0;
        for(int i=0; i<m; i++){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            g[a].push_back(st(b,c));    //正权,添入邻接表
            g[b].push_back(st(a,c));
        }
        for(int i=0; i<w; i++){         //负权,添入邻接表
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            g[a].push_back(st(b,-c));
        }
        //---->判断负权环
        bool ans = spfa(1);    //起点为1
        printf(ans?"YES\n":"NO\n");
    }
    return 0;
}
