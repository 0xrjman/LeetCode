#include <cstdio>
#include <cstring>
static int n,m,bit[1000001] = {0};

int lowbit(int x){            //第两种写法
    return x&(-x);           //或者是return i-(i&(i-1));
}
void add_update(int i,int val)//添加_更新 单节点的值
{
    while(i <= n){     	//由叶子结点向上更新C[]数组
        bit[i] += val;		//由叶子节点向上更新a数组
        i += lowbit(i);   //由叶子结点向上更新C[]数组,可以发现 更新过程是查询过程的逆过程
    }
}
int sum(int i)//求和节点的值  sum(j) - sum(i);
{
    int ret = 0;
    while(i > 0){
        ret += bit[i];//从右往左区间求和
        i -= lowbit(i);
    }
    return ret;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i++){  //不能从0开始
        int t;
        scanf("%d",&t);
        add_update(i,t);
    }
    while(m--){
        char s[10];
        scanf("%s",s);
        int i , j;
        scanf("%d%d",&i,&j);
        if(!strcmp(s,"QUERY")){ //区间查询
            printf("%d\n",sum(j)-sum(i-1));
        }else if(!strcmp(s,"ADD")){ //单点更新
            add_update(i,j);
        }else continue;

    }
    return 0;
}
