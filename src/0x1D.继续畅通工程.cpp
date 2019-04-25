#include<cstdio>
#include<algorithm>
using namespace std;

const int N = 10001;
struct Edge{ // 边结构体
    int x,y;
    int w;
    bool f;
    bool operator < (const Edge &a) const{
        return w < a.w;
    }
}edges[6000];

int bb[N];

int getroot(int x){ //寻根
    while(x != bb[x]) x = bb[x];
    return x;
}
//
//void merge(int x,int y){    //合并操作--->根据情况修改为下述bool类型
//    x = getroot(x);
//    y = getroot(y);
//    if(x != y) bb[x] = y;
//
bool merge(int x,int y){
    x = getroot(x);
    y = getroot(y);
    if(x == y) return false;
    else{
        bb[x] = y;
        return true;
    }
}
int main()
{
    int n;
    while(~scanf("%d",&n) && n){
        for(int i = 1;i <= n;i++) bb[i] = i;
        for(int i = 0;i < n*(n-1)/2;i++){
            scanf("%d%d%d%d",&edges[i].x,&edges[i].y,&edges[i].w,&edges[i].f);
            if(edges[i].f == 1) edges[i].w=0; // 若道路已修建，则费用为0
        }
        sort(edges,edges + n*(n-1)/2);  //重载结构体 '<' 运算符,按权重升序排序
        int ret = 0;
        for(int i=0;i<n*(n-1)/2;i++){
            if(merge(edges[i].x,edges[i].y)){   //产生合并
                ret += edges[i].w;
            }
        }
        printf("%d\n",ret);
    }
    return 0;
}
