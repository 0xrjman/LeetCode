//注意修改输出
//注意输入为0 ~ n-1
#include <cstdio>
#include <iostream>
using namespace std;
const int MAX = 201;
const int inf = 0x3f3f3f3f;
static int map[MAX][MAX],dis[MAX],book[MAX];

void Dijkstra(int n,int x,int y){   //参数(点数量，起点，终点)
    for(int i = 0;i < n;i++){   //初始化dis和book
        dis[i] = map[x][i];
        book[i] = 0;
        if (i == x) book[i] = 1;    //初始值
    }
    for(int i = 1;i < n;i++){
        //找出未访问过的dis的最小值
        int min = inf;
        int t = 0;
        for(int j = 0;j < n;j++){
            if(book[j] == 0 && dis[j] < min){
                min = dis[j];
                t = j;
            }
        }
        //if(min == inf) break; //图不连通的情况
        book[t] = 1;
        //更新dis数组
        for(int j = 0;j < n;j++){
            if(map[t][j] < inf){    //相邻点
                if(dis[t]+map[t][j] < dis[j]){
                    dis[j] = dis[t]+map[t][j];
                }
            }
        }
    }
    cout << "result from Dijkstra: ";
    if(dis[y] == inf) cout << "-1" <<endl;
    else cout << dis[y] << endl;
}

void SPFA(int n,int x,int y)    //参数(点数量，起点，终点)
{
    for(int i = 0;i < n;i++){   //初始化dis和book
        dis[i] = inf;
        book[i] = 0;
        if(i == x){         //关于起点的初始值
            dis[i] = 0;
            book[i] = 1;
        }
    }
    //采用队列优化
    queue<int> q;
    while(!q.empty()) q.pop();
    q.push(x);
    while(!q.empty()){
        int t = q.front();
        q.pop();
        book[t] = 0;
        for(int i = 0;i < n;i++){
            //if(map[t][i] < inf){
                if(dis[t] + map[t][i] < dis[i]){
                    dis[i] = dis[t] + map[t][i];
                    if(!book[i]){
                        book[i] = 1;
                        q.push(i);
                    }
                }
            //}
        }
    }
    cout << "result from SPFA: ";
    if(dis[y] == inf) cout << "-1" <<endl;
    else cout << dis[y] << endl;
}
int main()
{
    int m,n,x,y;
    while(~scanf("%d %d",&n,&m)){
        for(int i = 0;i < n;i++){   //初始化邻接矩阵
            for(int j = 0;j < n;j++) map[i][j] = inf;
            map[i][i] = 0;
        }
        for(int i = 0;i < m;i++){   //输入边
            int t1,t2,t3;
            scanf("%d %d %d",&t1,&t2,&t3);
            if(t3 < map[t1][t2]) map[t1][t2] = map[t2][t1] = t3;
        }
        scanf("%d %d",&x,&y);   //始终点
        Dijkstra(n,x,y);
        SPFA(n,x,y);
    }
    return 0;
}
