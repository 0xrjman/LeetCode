#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
  //用深搜会简单一点，广搜对 访问状态 的控制要求比较高
  //有空补上
static int t,i,j;
static int m,n;
static int g[50][50],dir[8][2] ={-1,-1,1,-1,-1,1,1,1,-1,0,0,-1,1,0,0,1};
static bool book[50][50];
struct node{
    int x;
    int y;
    node(int a,int b):x(a),y(b){}
};
void bfs()
{
    memset(book,false,sizeof(book));
    int ret = 0;
    int xs = 0,ys = 0;
    node one(xs,ys);
    queue<node> q;
    while(!q.empty()) q.pop();
    q.push(one);
    while(!q.empty()){
        one = q.front();
        q.pop();
        int xt,yt;
        if(book[one.x][one.y]) continue;
        book[one.x][one.y] = true;
        for(int i = 0;i < 8;i++){
            xt = one.x + dir[i][0];
            yt = one.y + dir[i][1];
            if(xt<0||yt<0||xt>m-1||yt>n-1) continue;
            if(g[xt][yt] == g[one.x][one.y]){
                ret = g[xt][yt] > ret ? g[xt][yt] : ret;
            }
            if(book[xt][yt]) continue;
            node next(xt,yt);
            q.push(next);
        }
    }
    cout << ret << endl;
}
int main()
{

    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&m,&n);
        for(i = 0;i < m;i++){
            for(j = 0;j < n;j++){
                scanf("%d",&g[i][j]);
            }
        }
        bfs();
    }
    return 0;
}
