/******前缀数组AC******/
#include <cstdio>
#include <cstring>
static int n,m,q,bit[1000010] = {0};

int main()
{
    scanf("%d%d%d",&n,&m,&q);
    while(m--){
        int i,j,k;
        scanf("%d%d%d",&i,&j,&k);
        bit[i] += k;    //区间起点添加 待累加前缀
        bit[j+1] -= k; //区间终点后的元素添加 待累减前缀
    }
    //这一轮遍历更新数组中 待累计的前缀元素 到整个数组
    for(int i = 1;i <= n;i++) bit[i] += bit[i-1];   //第一阶段两数都在[0,100]区间内，相加不需要取余操作
    //这一轮遍历,两两相加,求和前置所有元素的值到当前元素
    for(int i = 1;i <= n;i++) bit[i] = (bit[i] + bit[i-1]) % 10003; //第二阶段可能溢出，对结果取余
    while(q--){
        int i,j;
        scanf("%d%d",&i,&j);
        int ret = (bit[j] - bit[i-1] + 10003) % 10003;  //取余操作
        printf("%d\n",ret);
    }
    return 0;
}


/******树状数组超时******/
#include <cstdio>
#include <cstring>
static int n,m,q,bit[1000001] = {0};

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
    scanf("%d%d%d",&n,&m,&q);
    while(m--){
        int i,j,k;
        scanf("%d%d%d",&i,&j,&k);
        add_update(i,k);       //更新区间[i,n]
        add_update(j+1,-k);    //减去超出区间的更新[j+1.n]
    }
    while(q--){
        int i,j;
        scanf("%d%d",&i,&j);
        int ret = 0;
        for(;i<=j;i++){
             ret = (ret + sum(i))%10003;
        }
        printf("%d\n",ret);
    }
    return 0;
}
