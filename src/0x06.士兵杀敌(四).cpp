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
    scanf("%d%d",&m,&n);
    while(m--){
        char s[10];
        scanf("%s",s);
        if(!strcmp(s,"QUERY")){ //区间查询
            int i;
            scanf("%d",&i);
            printf("%d\n",sum(i));
        }else if(!strcmp(s,"ADD")){ //单点更新
            int i,j,k;
            scanf("%d%d%d",&i,&j,&k);
            add_update(i,k);       //更新区间[i,n]
            add_update(j+1,-k);    //减去超出区间的更新[j+1.n] 
        }else continue;

    }
    return 0;
}
